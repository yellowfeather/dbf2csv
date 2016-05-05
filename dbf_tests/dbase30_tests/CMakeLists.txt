set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREAD ON)
find_package (Boost COMPONENTS REQUIRED filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDbase30Tests
        Dbase30ColumnFixture.cpp
        Dbase30HeaderFixture.cpp
        Dbase30RecordFixture.cpp
        Dbase30TableFixture.cpp)

target_link_libraries(runDbase30Tests gtest gtest_main)
target_link_libraries(runDbase30Tests dbf dbf)
target_link_libraries(runDbase30Tests dbf ${Boost_LIBRARIES})