cmake_minimum_required(VERSION 3.8)

project(web-creator-dfs
    LANGUAGES CXX 
    VERSION 1.0.0 
    DESCRIPTION "Tool for creating simple network (graph) withs IPs as nodes."
    HOMEPAGE_URL "https://github.com/przemek83/web-creator-dfs")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

configure_file(${CMAKE_SOURCE_DIR}/testFile.txt 
    ${CMAKE_BINARY_DIR}/testFile.txt COPYONLY)

set(${PROJECT_NAME}_SOURCES
    main.cpp
    )

add_executable(${CMAKE_PROJECT_NAME} ${${PROJECT_NAME}_SOURCES})
