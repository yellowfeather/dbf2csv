cmake_minimum_required(VERSION 3.3)
project(dbf2csv)

add_definitions(-std=c++11)



set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREAD ON)
find_package (Boost COMPONENTS REQUIRED filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

set(SOURCE_FILES main.cpp)
set(HEADER_FILES Version.h)

add_executable(dbf2csv ${SOURCE_FILES} ${HEADER_FILES})

include_directories(dbf)

add_subdirectory(dbf)
add_subdirectory(dbf_tests)

set(CMAKE_EXE_LINKER_FLAGS=-static-libgcc -static-libstdc++ -static)

target_link_libraries(dbf2csv dbf)
target_link_libraries(dbf2csv ${Boost_LIBRARIES})
