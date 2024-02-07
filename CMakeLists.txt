cmake_minimum_required(VERSION 3.27)
project(Lithium)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCES src/**.cpp)
include_directories(include)

add_executable(Lithium ${SOURCES}
        include/Token.h
        src/Token.cpp
        src/Lexer.cpp
        include/Lexer.h
        include/Common.h
        src/Stack.cpp
        include/Stack.h
        src/Error.cpp
        include/Error.h
        include/PositionalError.h
        include/Position.h
        include/Util.h
        include/ChunkError.h
        src/AstNode.cpp
        include/AstNode.h
        src/Parser.cpp
        include/Parser.h
)

