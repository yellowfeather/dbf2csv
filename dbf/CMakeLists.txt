cmake_minimum_required(VERSION 3.5)

project(dbf)

add_definitions(-std=c++11)

set(HEADER_FILES
        DbfColumn.h
        DbfHeader.h
        DbfRecord.h
        DbfTable.h
        DbfUtils.h
        DbfValue.h
        TypedDbfValue.h
        DbfMemo.h
        DbfMemoDbase3.h
        DbfMemoDbase4.h
        DbfMemoFoxpro.h)

set(SOURCE_FILES
        DbfColumn.cpp
        DbfHeader.cpp
        DbfRecord.cpp
        DbfTable.cpp
        DbfValue.cpp
        TypedDbfValue.cpp
        DbfMemo.cpp
        DbfMemoDbase3.cpp
        DbfMemoDbase4.cpp
        DbfMemoFoxpro.cpp)

add_library(dbf STATIC ${SOURCE_FILES} ${HEADER_FILES})
