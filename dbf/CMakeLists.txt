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
        )

set(SOURCE_FILES
        DbfColumn.cpp
        DbfHeader.cpp
        DbfRecord.cpp
        DbfTable.cpp
        DbfValue.cpp
        TypedDbfValue.cpp
        )

add_library(dbf STATIC ${SOURCE_FILES} ${HEADER_FILES})
