#pragma warning(disable: 4191)

#include <stdexcept>
#include <string>

using namespace std::literals;

#ifdef DEBUG
#define THROWING_ASSERT(x, ...) if (x); else throw __VA_ARGS__
#else // DEBUG
#define THROWING_ASSERT(x, ...) 
#endif // DEBUG


#define GLF_IMPLIMENT_FUNC(name)                                                \
auto static load_##name() -> name##_t {    										\
	THROWING_ASSERT(load_proc, std::logic_error("load_proc not set"));			\
	name = reinterpret_cast<name##_t>(load_proc(#name));						\
	THROWING_ASSERT(name, std::runtime_error(#name""s + " failed to load"));	\
	return name;																\
};																				\
name##_t name = make_loader<load_##name>();   									\

namespace gl {

	template <auto& loader>
	auto make_loader() {
		return [](auto...args) { return loader()(args...); };
	}

}

#include "gl.hpp"

gl::load_proc_t gl::load_proc = nullptr;

void gl::set_load_proc(load_proc_t new_load_proc)
{
	load_proc = new_load_proc;
}