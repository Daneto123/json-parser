cmake_minimum_required(VERSION 3.10)

project(StorageApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(StorageApp 
            src/command.cpp,
            src/create.cpp,
            src/delete.cpp,
            src/json.cpp,
            src/main.cpp,
            src/move.cpp,
            src/print.cpp,
            src/save.cpp,
            src/set.cpp,
            src/validate.cpp)