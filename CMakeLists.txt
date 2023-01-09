cmake_minimum_required(VERSION 3.16)
project(bdj_vacation)

set(CMAKE_CXX_STANDARD 14)

add_executable(bdj_vacation main.cpp lib/SkipListNode.cpp lib/SkipListNode.h lib/SkipList.cpp lib/SkipList.h lib/Box.cpp lib/Box.h)
