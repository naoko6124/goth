cmake_minimum_required(VERSION 3.0.0)
project(goth VERSION 1.0)

file(GLOB_RECURSE goth_src goth/**.*)
add_executable(goth ${goth_src})
target_precompile_headers(goth PUBLIC goth/pch.h)
target_include_directories(goth PUBLIC goth)