set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREAD ON)
find_package (Boost COMPONENTS REQUIRED filesystem)

if (Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIR})
endif ()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runDbase03Tests
        Dbase03ColumnFixture.cpp
        Dbase03HeaderFixture.cpp
        Dbase03RecordFixture.cpp
        Dbase03TableFixture.cpp)

target_link_libraries(runDbase03Tests gtest gtest_main)
target_link_libraries(runDbase03Tests dbf dbf)
target_link_libraries(runDbase03Tests dbf ${Boost_LIBRARIES})