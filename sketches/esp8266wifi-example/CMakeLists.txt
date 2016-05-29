add_executable_avr(esp8266wifi-example ESP8266_library_test.cpp)
# we require a number of arduino libraries for this
# (they already depend on arduino-core, so we don't need it here)
# install these libraries and either copy them or create a link in the 'external' directory
target_link_libraries(esp8266wifi-example SoftwareSerial)

# special external dependencies can be added like this and will be downloaded once
# arguments: <target> <name> <git url>
target_sketch_library(esp8266wifi-example ESP8266wifi https://github.com/ekstrand/ESP8266wifi)

