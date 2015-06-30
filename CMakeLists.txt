PROJECT(msgpack_0.5.7-bug-1469090-reproduce)

ADD_EXECUTABLE(${PROJECT_NAME} main.cpp)

TARGET_LINK_LIBRARIES(${PROJECT_NAME} msgpack)

ADD_CUSTOM_TARGET(check ./valgrind.sh)
