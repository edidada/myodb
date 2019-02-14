cmake_minimum_required(VERSION 3.13)
project(myodb)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -DDATABASE_MYSQL")


add_executable(myodb main.cpp myodb-odb.cxx)

target_link_libraries(myodb libodb-mysql.so)
target_link_libraries(myodb libodb.so)