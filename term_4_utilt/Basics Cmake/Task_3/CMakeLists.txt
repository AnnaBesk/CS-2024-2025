cmake_minimum_required(VERSION 3.10)
project(LinkingLibrary)

set(CUBE_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cube/include)
set(CUBE_LIB_DIR ${CMAKE_CURRENT_SOURCE_DIR}/cube/lib)

add_executable(main main.cpp)
target_include_directories(main PUBLIC ${CUBE_INCLUDE_DIR})
target_link_directories(main PUBLIC ${CUBE_LIB_DIR})
target_link_libraries(main PUBLIC cube)

