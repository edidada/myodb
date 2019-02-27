cmake_minimum_required(VERSION 3.13)
project(testodbhello)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDATABASE_MYSQL")


add_executable(testodbhello main.cpp myodb-odb.cxx)

target_link_libraries(testodbhello libodb-mysql.so)
target_link_libraries(testodbhello libodb.so)
