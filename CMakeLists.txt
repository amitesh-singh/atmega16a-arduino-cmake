cmake_minimum_required(VERSION 3.0)

#this is the place where you can set configuration options
include(config.cmake)

set(CMAKE_TOOLCHAIN_FILE cmake/avr-arduino-toolchain.cmake)

# project name and code types we use
project(ubirch C CXX ASM)

# adding our libraries, sources
add_libraries(lib)
add_sources(src)

# add the sketches directory (contains sketch directories and
# a "libraries" dir where dependent libs are extracted
add_sketches(sketches)
