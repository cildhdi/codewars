cmake_minimum_required(VERSION 3.0.0)
project(codewars VERSION 0.1.0)

include_directories(libs/igloo)

file(GLOB SRCS *.cpp)

foreach(SRC ${SRCS})
  string(REPLACE ${PROJECT_SOURCE_DIR}/
                 ""
                 EXECUTABLE_NAME
                 ${SRC})
  add_executable(${EXECUTABLE_NAME} ${SRC})
endforeach()
