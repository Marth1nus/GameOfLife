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