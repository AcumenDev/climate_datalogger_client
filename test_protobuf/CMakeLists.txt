cmake_minimum_required(VERSION 3.7)
project(test_protobuf)

set(CMAKE_CXX_STANDARD 11)

#add_executable(test_protobuf main.cpp)



include_directories(.)

add_executable(test_protobuf main.cpp
        pb/pb.h
        pb/pb_common.c
        pb/pb_common.h
        pb/pb_decode.c
        pb/pb_decode.h
        pb/pb_encode.c
        pb/pb_encode.h
        pb/BaseMessage.pb.c
        pb/BaseMessage.pb.h
        pb/Temperature.pb.c
        pb/Temperature.pb.h
)
