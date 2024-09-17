#version 300 es
layout (location = 0) in vec3 a_pos;

out vec2 v_tex;

void main()
{
  gl_Position = vec4(a_pos, 1);
  v_tex = a_pos.xy * 0.5 + 0.5;
}