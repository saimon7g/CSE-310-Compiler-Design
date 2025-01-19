cmake_minimum_required(VERSION 3.23)
project (offline1)

set(CMAKE_CXX_STANDARD 14)

add_executable(offline1 main.cpp SymbolInfo.h ScopeTable.h SymbolTable.h)
