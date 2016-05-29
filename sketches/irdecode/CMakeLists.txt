add_executable_avr(irdecoder irdecoder.cpp)
# we require a number of arduino libraries for this
# (they already depend on arduino-core, so we don't need it here)
# install these libraries and either copy them or create a link in the 'external' directory
#target_link_libraries(fewl)

# special external dependencies can be added like this and will be downloaded once
# arguments: <target> <name> <git url> <branch>
target_sketch_library(irdecoder Arduino-IRremote "https://github.com/amitesh-singh/Arduino-IRremote" atmega16a)
