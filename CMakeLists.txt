cmake_minimum_required(VERSION 3.1.0)
project(bitsy)

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "-std=c++17 -Wall -Wextra -pedantic -static")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Wextra -pedantic -static")
endif()

file(GLOB_RECURSE bitsy_source ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/*.hpp)
add_library(bitsy ${bitsy_source})
target_include_directories(bitsy ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/cpr)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/cpr/include)
target_link_libraries(bitsy cpr)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/deps/json)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/deps/json/src)
target_link_libraries(bitsy nlohmann_json)
