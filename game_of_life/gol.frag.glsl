#version 460 core

out vec4 frag_color;

uniform uint      display_only;
uniform sampler2D source;
uniform uvec2     grid_size;
uniform uvec2     window_size;
uniform uint      tik;
uniform uint      millis;
uniform vec2      mouse_pos;
uniform uvec3     mouse_buttons;

uint get_cell(ivec2 pos) {
	return texelFetch(source, pos, 0).r > 0.5 ? 1 : 0;
}

uint count_alive_neighbors(ivec2 pos) {
	uint count = 0;
	for (int i = -1; i <= 1; i++)
		for (int j = -1; j <= 1; j++) 
			if (i == 0 && j == 0) continue;
			else count += get_cell(pos + ivec2(i, j));
	return count;
}

uint alive() {
	ivec2 pos = ivec2(gl_FragCoord.xy);
	uint neighbor_count = count_alive_neighbors(pos);
	uint self = get_cell(pos);
	return (self == 1 
		? neighbor_count == 2 || neighbor_count == 3
		: neighbor_count == 3 ) ? 1 : 0;
}

vec4 display() {
	vec2 tex = gl_FragCoord.xy / window_size;
	tex.y = 1.0 - tex.y;
	return texture(source, tex);
}

void main() {
	if (display_only == 1) {
		frag_color = display();
		return;
	}
	uint a = alive();
	if (mouse_buttons.x == 1
 	&&  length(mouse_pos / window_size * grid_size - gl_FragCoord.xy) < 1)
		a = 1;
	frag_color = vec4(a,a,a,1);
}