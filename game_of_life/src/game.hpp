#pragma once

#include "gl.hpp"

#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
#include <string_view>
#include <utility>
#include <ranges>
#include <concepts>
#include <chrono>

struct timer {
	using clock = std::chrono::steady_clock;
	clock::time_point stamp = clock::now();
	inline constexpr auto seconds() const noexcept -> double { return std::chrono::duration<double>(timer{}.stamp - stamp).count(); }
	inline constexpr auto milliseconds() const noexcept -> double { return seconds() / 1'000.0; }
	inline constexpr auto restart() noexcept -> timer { return std::exchange(*this, timer{}); }
};
struct no_repeat {
	size_t stamp{}, repeat{};
	std::string repeat_message_buffer{};
	using hash = std::hash<std::string_view>;
	auto operator()(std::string_view message) -> std::string_view {
		size_t const old_stamp = std::exchange(stamp, hash{}(message));
		if (stamp == old_stamp)
			return repeat_message_buffer = std::format("^^^ x{}\r", ++repeat);
		repeat = 1;
		return message;
	}
};

struct game_of_life {
public: /* Function View */

	void build();
	void build_shaders();
	void build_textures();
	void locate_uniforms();
	void set_uniforms(bool display_only);
	void update();
	void draw();

public: /* Data View */
	HWND hwnd{};
	GLuint 
		width = 256, 
		height = width;

public: /* State */
	GLuint tik{};
	POINT mouse_pos{};
	timer time{};

public: /* Graphics */
	gl::raii::buffer vbo{};
	gl::raii::vertexarray vao{};
	gl::raii::texture tid{};
	gl::raii::framebuffer fbo{};
	gl::raii::program pid{};
	gl::GLint /* Uniform Locations */
		uniform_display_only{},
		uniform_source{},
		uniform_grid_size{},
		uniform_window_size{},
		uniform_tik{},
		uniform_millis{},
		uniform_mouse_buttons{},
		uniform_mouse_pos{};
};
