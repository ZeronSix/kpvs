cmake_minimum_required(VERSION 2.8)
project(kpvs)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic")

file(GLOB KPVS_LIB_HEADERS include/*.hpp)
file(GLOB KPVS_LIB_SOURCES src/*.cpp)

add_library(kpvs STATIC ${KPVS_LIB_SOURCES} ${KPVS_LIB_HEADERS})
add_subdirectory(tests)
