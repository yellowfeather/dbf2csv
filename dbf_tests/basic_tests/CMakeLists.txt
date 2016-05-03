include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicDbfTests
        DbfColumnFixture.cpp
        DbfHeaderFixture.cpp
        DbfRecordFixture.cpp
        DbfTableFixture.cpp)

target_link_libraries(runBasicDbfTests gtest gtest_main)
target_link_libraries(runBasicDbfTests dbf dbf)