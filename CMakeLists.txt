cmake_minimum_required(VERSION 3.14)
project(WorkFlow)

set(CMAKE_CXX_STANDARD 17)

add_executable(WorkFlow main.cpp Worker.h Blocks/ReadFile.cpp Blocks/ReadFile.cpp Blocks/ReadFile.h Blocks/WriteFile.cpp Blocks/WriteFile.h Flow.cpp Flow.h Flow.cpp Flow.h Blocks/Grep.cpp Blocks/Grep.h Blocks/Sort.cpp Blocks/Sort.h Blocks/Replace.cpp Blocks/Replace.h Blocks/Dump.cpp Blocks/Dump.h Parser.cpp Parser.h)