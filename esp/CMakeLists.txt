cmake_minimum_required(VERSION 3.10)
project(esp)

set(CMAKE_CXX_STANDARD 11)


include_directories(.)

add_executable(esp
        Config.hpp
        ConfigServer.cpp
        ConfigServer.hpp
        DataLogger.cpp
        DataLogger.hpp
        DataLoggerClient.hpp
        esp.ino
        pb.h
        pb_common.c
        pb_common.h
        pb_decode.c
        pb_decode.h
        pb_encode.c
        pb_encode.h
        Temperature.pb.h
        Temperature.pb.c
        BaseMessage.pb.h
        BaseMessage.pb.c
        Worker.hpp
        ConfigPage.hpp)
