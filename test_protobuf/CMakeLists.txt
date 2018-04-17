cmake_minimum_required(VERSION 3.7)
project(test_protobuf)

set(CMAKE_CXX_STANDARD 11)

#add_executable(test_protobuf main.cpp)



include_directories(.)

add_executable(test_protobuf main.cpp
        pb.h
        pb_common.c
        pb_common.h
        pb_decode.c
        pb_decode.h
        pb_encode.c
        pb_encode.h
        TemperatureProtocol.pb.c
        TemperatureProtocol.pb.h
)
