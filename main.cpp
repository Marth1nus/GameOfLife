#include <vector>
#include <array>
#include <ranges>
#include <memory>
#include <algorithm>
#include <stdexcept>

#include <cstdio>
#include <string>
#include <string_view>

#ifdef __EMSCRIPTEN__
#include <emscripten.h>
#include <GLES3/gl3.h>
#include <GLFW/glfw3.h>
#else
#include <glad/gles2.h>
#include <GLFW/glfw3.h>
#endif

auto static constexpr gol_step_dt = 1.0 / 30.0;
auto static constexpr gol_width = 512, gol_height = gol_width;

auto static constexpr &&vert_code{R"glsl(
  #version 300 es
  layout (location = 0) in vec3 a_pos;

  out vec2 v_tex;

  void main()
  {
    gl_Position = vec4(a_pos, 1);
    v_tex = a_pos.xy * 0.5 + 0.5;
  }
)glsl"};

auto static constexpr &&frag_code{R"glsl(
  #version 300 es
  precision mediump float;
  precision mediump sampler2D;

  out vec4 o_color;
  in vec2 v_tex;

  uniform sampler2D tex;
  uniform bool gol_step;

  vec4 game_of_life()
  {
    ivec2 pos = ivec2(gl_FragCoord.xy);
    float cell = texelFetch(tex, pos, 0).r;
    bool cell_alive = cell > 0.5;

    int neighbor_count = 0;
    for (int i=-1; i<=1; i++)
      for (int j=-1; j<=1; j++)
        if (i==0&&j==0) continue;
        else if (texelFetch(tex, pos + ivec2(i, j), 0).r > 0.5)
          neighbor_count++;

    cell_alive = cell_alive ? neighbor_count == 2 || neighbor_count == 3
                            : neighbor_count == 3;
    cell = cell_alive ? 1.0 : 0.0;
    return vec4(cell);
  }

  vec4 display_game()
  {
    return vec4(texture(tex, v_tex).r);
  }

  void main()
  {
    o_color = gol_step ? game_of_life() : display_game();
  }
)glsl"};

auto inline static constexpr assert(auto &&value, auto &&message) -> decltype(auto)
{
  if (value)
    return std::forward<decltype(value)>(value);
  throw std::runtime_error{message};
}
#define ASSERT(...) assert(__VA_ARGS__, #__VA_ARGS__)

auto static glCheckError()
{
  for (GLenum err; (err = glGetError()) not_eq GL_NO_ERROR;)
  {
    auto str = /* clang-format off */ [err]{ switch (err) {
      case GL_INVALID_ENUM:                  return "GL_INVALID_ENUM";
      case GL_INVALID_VALUE:                 return "GL_INVALID_VALUE";
      case GL_INVALID_OPERATION:             return "GL_INVALID_OPERATION";
      case GL_OUT_OF_MEMORY:                 return "GL_OUT_OF_MEMORY";
      case GL_INVALID_FRAMEBUFFER_OPERATION: return "GL_INVALID_FRAMEBUFFER_OPERATION";
      default:                               return "UNKNOWN_ERROR"; } }(); /* clang-format on */
    std::fprintf(stderr, "OpenGL ES error 0x%x: %s\n", err, str);
  }
}

struct glfw
{
  glfw() { ASSERT(glfwInit()); }
  ~glfw() { glfwTerminate(); }
} static const glfw{};

auto static window_lifetime = []
{
  auto const width = 720, height = width;
  auto const window_lifetime = std::shared_ptr<GLFWwindow>{
      ASSERT(glfwCreateWindow(width, height, "Game Of Life", 0, 0)), glfwDestroyWindow};
  auto const window = window_lifetime.get();
  glfwMakeContextCurrent(window);
#ifdef __EMSCRIPTEN__
#else
  ASSERT(gladLoadGLES2(glfwGetProcAddress));
#endif
  glViewport(0, 0, width, height);
  return window_lifetime;
}();
auto static window = window_lifetime.get();

auto static get_info_log(decltype(glGetShaderiv) get_iv, decltype(glGetShaderInfoLog) get_info_log, GLuint id, GLenum pname) noexcept -> std::string
{
  std::string res{};
  if (GLint status; get_iv(id, pname, &status), status)
    return res;
  GLsizei len;
  res.resize((get_iv(id, GL_INFO_LOG_LENGTH, &len), len));
  res.resize((get_info_log(id, len, &len, res.data()), len));
  return res;
}

auto static load_shader(GLenum type, std::string_view code) -> GLuint
{
  auto version_offset = code.find("#version");
  if (version_offset == std::string_view::npos or version_offset >= code.size())
    throw std::runtime_error{"Shader did not start with #version"};
  auto sid = glCreateShader(type);
  auto str = code.data() + version_offset;
  auto len = static_cast<GLsizei>(code.size() - version_offset);
  glShaderSource(sid, 1, &str, &len);
  glCompileShader(sid);
  if (auto log = get_info_log(glGetShaderiv, glGetShaderInfoLog, sid, GL_COMPILE_STATUS); not log.empty())
    std::fprintf(stderr, "Shader Compiler Error: \n%s\n", log.c_str());
  glCheckError();
  return sid;
}

auto pid = glCreateProgram();
struct
{
  GLint tex, gol_step;
} uniforms;

auto reload_program(char const *vert = vert_code, char const *frag = frag_code)
{
  glDeleteProgram(pid);
  pid = glCreateProgram();
  GLuint vid, fid;
  vid = load_shader(GL_VERTEX_SHADER, vert);
  fid = load_shader(GL_FRAGMENT_SHADER, frag);
  glAttachShader(pid, vid);
  glAttachShader(pid, fid);
  glLinkProgram(pid);
  glDeleteShader(vid);
  glDeleteShader(fid);
  if (auto log = get_info_log(glGetProgramiv, glGetProgramInfoLog, pid, GL_LINK_STATUS); not log.empty())
    std::fprintf(stderr, "Program Link Error:\n%s\n", log.c_str());
  glCheckError();
  uniforms.tex /*      */ = glGetUniformLocation(pid, "tex");
  uniforms.gol_step /* */ = glGetUniformLocation(pid, "gol_step");
  glCheckError();
}

auto static constexpr vertices = std::array{
    std::array{-1.0f, -1.0f},
    std::array{-1.0f, +1.0f},
    std::array{+1.0f, -1.0f},
    std::array{+1.0f, +1.0f},
};

auto static vbo = []
{
  GLuint vbo;
  glGenBuffers(1, &vbo);
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
  glCheckError();
  return vbo;
}();

auto static vao = []
{
  GLuint vao;
  glGenVertexArrays(1, &vao);
  glBindVertexArray(vao);
  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(vertices[0]), 0);
  glEnableVertexAttribArray(0);
  glCheckError();
  return vao;
}();

auto reload_texture(GLuint tid, int width = gol_width, int height = gol_height)
{
  std::vector<uint8_t> pixels(width * height * sizeof(uint8_t));
  for (auto &pixel : pixels)
    pixel = std::rand();
  glBindTexture(GL_TEXTURE_2D, tid);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_R8, width, height, 0, GL_RED, GL_UNSIGNED_BYTE, pixels.data());
  glCheckError();
}

auto static tids = []
{
  std::array<GLuint, 2> tids;
  glGenTextures(tids.size(), tids.data());
  for (auto tid : tids)
  {
    glBindTexture(GL_TEXTURE_2D, tid);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    reload_texture(tid);
  }
  return tids;
}();

auto static fbos = []
{
  std::array<GLuint, 2> fbos;
  glGenFramebuffers(fbos.size(), fbos.data());
  for (auto i = 0; i < fbos.size(); i++)
  {
    glBindFramebuffer(GL_FRAMEBUFFER, fbos.at(i));
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, tids.at(i), 0);
    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) not_eq GL_FRAMEBUFFER_COMPLETE)
      throw std::runtime_error{"Framebuffer is incomplete!\n"};
    glCheckError();
  }
  return fbos;
}();

auto static dt_stamp = glfwGetTime(), gol_stamp = dt_stamp;

auto static inline setup()
{
  reload_program();
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glCheckError();
}

auto static inline loop()
{
  auto dt_stamp_old = dt_stamp;
  dt_stamp = glfwGetTime();
  auto dt = dt_stamp_old - dt_stamp;
  glfwPollEvents();

  glUseProgram(pid);
  glBindVertexArray(vao);

  if (dt_stamp - gol_stamp > gol_step_dt)
  {
    gol_stamp = dt_stamp;
    reload_program();
    std::swap(tids.at(0), tids.at(1));
    std::swap(fbos.at(0), fbos.at(1));
    glUniform1i(uniforms.gol_step, 1);
    glBindTexture(GL_TEXTURE_2D, tids.at(1));
    glBindFramebuffer(GL_FRAMEBUFFER, fbos.at(0));
    glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
  }

  glUniform1i(uniforms.gol_step, 0);
  glBindTexture(GL_TEXTURE_2D, tids.at(0));
  glBindFramebuffer(GL_FRAMEBUFFER, 0);
  glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

  glCheckError();
  glfwSwapBuffers(window);
}

int main()
{
  setup();
#ifdef __EMSCRIPTEN__
  emscripten_set_main_loop(loop, 0, true);
  glfwSwapInterval(1);
#else
  glfwSwapInterval(1);
  while (not glfwWindowShouldClose(window))
    loop();
#endif
}