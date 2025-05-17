cmake_minimum_required(VERSION 3.20)
project(AnimalsProject)


set(SOURCE_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/${ANIMAL_TYPE}.cpp)

if(NOT EXISTS ${SOURCE_FILE})
    message(FATAL_ERROR "Source file ${SOURCE_FILE} not found")
endif()

add_executable(${ANIMAL_TYPE} ${SOURCE_FILE})
