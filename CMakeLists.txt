cmake_minimum_required(VERSION 3.0.0)
project(goth VERSION 1.0)

file(GLOB_RECURSE goth_src goth/**.*)
add_executable(goth ${goth_src})

file(COPY tests DESTINATION ${PROJECT_BINARY_DIR}/Debug)
file(COPY tests DESTINATION ${PROJECT_BINARY_DIR}/Release)