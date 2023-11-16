#pragma once

#include "game.hpp"
#include <array>

auto make_shader(gl::GLenum shader_type, std::string_view code) -> gl::raii::shader {
	using namespace gl;
	raii::shader sid = glCreateShader(shader_type);
	GLchar const* sources[]{ code.data() };
	GLsizei const lengths[]{ code.size() };
	glShaderSource(sid, std::size(sources), sources, lengths);
	glCompileShader(sid);
	GLint status;
	if (glGetShaderiv(sid, GL_COMPILE_STATUS, &status);
		!status) {
		GLint length;
		glGetShaderiv(sid, GL_INFO_LOG_LENGTH, &length);
		std::string log(length, ' ');
		glGetShaderInfoLog(sid, log.size(), &length, log.data());

		static no_repeat no_repeat{};
		std::cerr << no_repeat(log);

		return 0;
	}
	return sid;
}
auto make_program(std::string_view fragment_code) -> gl::raii::program {
	using namespace gl;
	raii::shader fid = make_shader(GL_FRAGMENT_SHADER, fragment_code);
	raii::program pid = glCreateProgram();
	glAttachShader(pid, fid);
	glLinkProgram(pid);
	GLint status;
	if (glGetProgramiv(pid, GL_LINK_STATUS, &status);
		!status) {
		GLint length;
		glGetProgramiv(pid, GL_INFO_LOG_LENGTH, &length);
		std::string log(length, ' ');
		glGetProgramInfoLog(pid, log.size(), &length, log.data());

		static no_repeat no_repeat{};
		std::cerr << no_repeat(log);

		return 0;
	}
	return pid;
}
auto centered_quad_verts(float x, float y, float w, float h) { 
	return std::array{ 
		x + w / 2, /**/ y + h / 2,
		x + w / 2, /**/ y - h / 2,
		x - w / 2, /**/ y - h / 2,
		x - w / 2, /**/ y + h / 2,
	};
}

void game_of_life::build() {
	using namespace gl;

	vbo = raii::make1from(glCreateBuffers);
	auto const verts = centered_quad_verts(0, 0, 2, 2);
	glNamedBufferData(vbo, sizeof(verts), data(verts), GL_STATIC_DRAW);

	vao = raii::make1from(glCreateVertexArrays);
	glVertexArrayAttribFormat(vao, 0, 2, GL_FLOAT, GL_FALSE, 0);
	glVertexArrayVertexBuffer(vao, 0, vbo, 0, sizeof(float) * 2);
	glVertexArrayAttribBinding(vao, 0, 0);
	glEnableVertexArrayAttrib(vao, 0);

	build_texture();
	upload_noise_image();

	load_shader(""
		"\n#version 460 core"
		"\nout vec4 color;"
		"\nuniform uvec2 window_size;"
		"\nvoid main() { color = vec4(gl_FragCoord.xy / window_size, 0, 1); }"
	);
}

bool game_of_life::pull_size() {
	using gl::glGetTextureLevelParameteriv;

	GLint width{}, height{};
	glGetTextureLevelParameteriv(tid, 0, GL_TEXTURE_WIDTH, &width);
	glGetTextureLevelParameteriv(tid, 0, GL_TEXTURE_HEIGHT, &height);

	bool was_same = this->width == width
		/*    */ && this->height == height;

	this->width = width;
	this->height = height;

	return was_same;
}
void game_of_life::build_texture() {
	using namespace gl;

	tid = raii::make1from(glCreateTextures, GL_TEXTURE_2D);
	glTextureStorage2D(tid, 1, GL_R8, width, height);
	glTextureParameteri(tid, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
	glTextureParameteri(tid, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
	glTextureParameteri(tid, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTextureParameteri(tid, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	fbo = raii::make1from(glCreateFramebuffers);
	glNamedFramebufferTexture(fbo, GL_COLOR_ATTACHMENT0, tid, 0);
	if (GLenum status = glCheckNamedFramebufferStatus(fbo, GL_FRAMEBUFFER);
		status != GL_FRAMEBUFFER_COMPLETE)
		throw std::runtime_error("framebuffer incomplete");
}
void game_of_life::upload_image(std::span<uint8_t const> pixels) {
	using namespace gl;
	if (bool size_synced = pull_size());
	else throw std::runtime_error{ "width and/or height was out of sync" };

	if (pixels.size() != static_cast<size_t>(width) * height)
		throw new std::range_error{ "size(pixels) != width * height" };

	glTextureSubImage2D(tid, 0, 0, 0, width, height, GL_RED, GL_UNSIGNED_BYTE, pixels.data());
}
void game_of_life::upload_noise_image() {
	std::vector<uint8_t> pixels(width * height);
	std::ranges::generate(pixels, rand);
	upload_image(pixels);
}
auto game_of_life::download_image() -> std::vector<uint8_t> {
	using namespace gl;

	if (bool size_synced = pull_size());
	else throw std::runtime_error{ "width and/or height was out of sync" };

	std::vector<uint8_t> pixels(static_cast<size_t>(width) * height);
	glGetTextureImage(tid, 0, GL_RED, GL_UNSIGNED_BYTE, pixels.size(), pixels.data());
	return pixels;
}

void game_of_life::load_shader(std::string_view code) {
	pid = make_program(code);
	locate_uniforms();
}
void game_of_life::locate_uniforms() {
	using gl::glGetUniformLocation;
	uniform_display_only  /**/ = glGetUniformLocation(pid, "display_only");
	uniform_source        /**/ = glGetUniformLocation(pid, "source");
	uniform_grid_size     /**/ = glGetUniformLocation(pid, "grid_size");
	uniform_window_size   /**/ = glGetUniformLocation(pid, "window_size");
	uniform_tik           /**/ = glGetUniformLocation(pid, "tik");
	uniform_pause         /**/ = glGetUniformLocation(pid, "pause");
	uniform_millis        /**/ = glGetUniformLocation(pid, "millis");
	uniform_mouse_buttons /**/ = glGetUniformLocation(pid, "mouse_buttons");
	uniform_mouse_pos     /**/ = glGetUniformLocation(pid, "mouse_pos");
}
void game_of_life::set_uniforms(bool display_only) {
	using namespace gl;

	GLuint const textures[]{ tid };
	glBindTextures(0, std::size(textures), textures);

	GetCursorPos(&mouse_pos);
	ScreenToClient(hwnd, &mouse_pos);

	RECT client_rect{};
	GetClientRect(hwnd, &client_rect);

	uint16_t static constexpr 
		key_down = 0x8000, 
		key_just_pressed = 0x0001;
	uint16_t
		mouse1 = GetAsyncKeyState(VK_LBUTTON),
		mouse2 = GetAsyncKeyState(VK_RBUTTON),
		mouse3 = GetAsyncKeyState(VK_MBUTTON);

	glProgramUniform1ui(pid, uniform_display_only, display_only);
	glProgramUniform1i (pid, uniform_source, 0);
	glProgramUniform2ui(pid, uniform_grid_size, width, height);
	glProgramUniform2ui(pid, uniform_window_size, client_rect.right - client_rect.left, client_rect.bottom - client_rect.top);
	glProgramUniform1ui(pid, uniform_tik, tik);
	glProgramUniform1ui(pid, uniform_pause, pause);
	glProgramUniform1f (pid, uniform_millis, static_cast<float>(time.milliseconds()));
	glProgramUniform3ui(pid, uniform_mouse_buttons, bool(mouse1 & key_down), bool(mouse2 & key_down), bool(mouse3 & key_down));
	glProgramUniform2f (pid, uniform_mouse_pos, mouse_pos.x, mouse_pos.y);
}

void game_of_life::update() {
	using namespace gl;

	uint16_t static constexpr
		key_down = 0x8000,
		key_just_pressed = 0x0001;
	uint16_t const
		arrow_up    /**/ = GetAsyncKeyState(VK_UP),
		arrow_down  /**/ = GetAsyncKeyState(VK_DOWN),
		arrow_left  /**/ = GetAsyncKeyState(VK_LEFT),
		arrow_right /**/ = GetAsyncKeyState(VK_RIGHT);

	if (arrow_up & key_just_pressed
	||  arrow_right & key_just_pressed)
		pause = !pause;

	tik++;
	set_uniforms(false);

	if (arrow_right & key_just_pressed)
		pause = !pause;

	glUseProgram(pid);
	glBindVertexArray(vao);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
void game_of_life::draw() {
	using namespace gl;

	set_uniforms(true);

	glUseProgram(pid);
	glBindVertexArray(vao);
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
	glClear(GL_COLOR_BUFFER_BIT);
	glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
}
