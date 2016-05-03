cmake_minimum_required(VERSION 3.3)
project(dbf2csv)

add_definitions(-std=c++11)

set(SOURCE_FILES main.cpp)
set(HEADER_FILES version.h)

add_executable(dbf2csv ${SOURCE_FILES} ${HEADER_FILES})

include_directories(dbf)

add_subdirectory(dbf)
add_subdirectory(dbf_tests)

target_link_libraries(dbf2csv dbf)