cmake_minimum_required(VERSION 3.29.0)
project(game_of_life VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(stb     GIT_REPOSITORY https://github.com/Marth1nus/CMakeLib-stb      GIT_TAG master )
FetchContent_Declare(glm     GIT_REPOSITORY https://github.com/g-truc/glm.git              GIT_TAG master )
FetchContent_Declare(glfw    GIT_REPOSITORY https://github.com/glfw/glfw.git               GIT_TAG master )

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(stb glm glfw)

add_library(glad glad/src/gles2.c)
target_include_directories(glad PUBLIC glad/include/)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE glad stb glm glfw)
target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)