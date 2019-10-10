cmake_minimum_required(VERSION 3.0.0)
project(codewars VERSION 0.1.0)

include_directories(libs/igloo)

file(GLOB SRCS *.cpp)

set(README "# Codewars\n")
set(CMAKE_CXX_STANDARD 14)

foreach(SRC ${SRCS})
  string(FIND ${SRC} / SPOS REVERSE)
  string(FIND ${SRC} . EPOS REVERSE)
  math(EXPR BEGIN ${SPOS}+1)
  math(EXPR LENGTH ${EPOS}-${BEGIN})
  string(SUBSTRING ${SRC}
                   ${BEGIN}
                   ${LENGTH}
                   EXECUTABLE_NAME)
  string(
    APPEND README
    "- [${EXECUTABLE_NAME}](https://www.codewars.com/kata/${EXECUTABLE_NAME})\n"
    )
  add_executable(${EXECUTABLE_NAME} ${SRC})
endforeach()

string(TIMESTAMP GENERATE_TIME)
string(APPEND README "\n *Write by cmake at ${GENERATE_TIME}*")
file(WRITE README.md ${README})
