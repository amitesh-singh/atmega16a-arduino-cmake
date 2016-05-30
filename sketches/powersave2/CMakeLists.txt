# add a target and tell it what it's source files are
add_executable_avr(powersave2 powersave2.cpp)
# tell the target, that it should use the arduino core libraries
target_link_libraries(powersave2 arduino-core)
