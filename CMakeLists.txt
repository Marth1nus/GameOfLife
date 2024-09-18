cmake_minimum_required(VERSION 3.29.0)
project(game_of_life VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
if (CMAKE_SYSTEM_NAME MATCHES "Emscripten")
  add_executable(${PROJECT_NAME} main.cpp)
  target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)
  target_link_options(${PROJECT_NAME} PUBLIC -sUSE_GLFW=3 -sUSE_WEBGL2=1)
  set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME} SUFFIX ".html")

else()
  include(FetchContent)
  FetchContent_Declare(glfw GIT_REPOSITORY https://github.com/glfw/glfw.git GIT_TAG master )

  set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
  set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(glfw)

  add_executable(${PROJECT_NAME} main.cpp)
  target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
  target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

endif()