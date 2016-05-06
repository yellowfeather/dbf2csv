set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREAD ON)
find_package (Boost COMPONENTS REQUIRED filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDbaseF5Tests
        DbaseF5ColumnFixture.cpp
        DbaseF5HeaderFixture.cpp
        DbaseF5RecordFixture.cpp
        DbaseF5TableFixture.cpp)

target_link_libraries(runDbaseF5Tests gtest gtest_main)
target_link_libraries(runDbaseF5Tests dbf dbf)
target_link_libraries(runDbaseF5Tests dbf ${Boost_LIBRARIES})