set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREAD ON)
find_package (Boost COMPONENTS REQUIRED filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDbase31Tests
        Dbase31ColumnFixture.cpp
        Dbase31HeaderFixture.cpp
        Dbase31RecordFixture.cpp
        Dbase31TableFixture.cpp)

target_link_libraries(runDbase31Tests gtest gtest_main)
target_link_libraries(runDbase31Tests dbf dbf)
target_link_libraries(runDbase31Tests dbf ${Boost_LIBRARIES})