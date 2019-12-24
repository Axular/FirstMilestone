cmake_minimum_required(VERSION 3.15)
project(FirstMilestone)

set(CMAKE_CXX_STANDARD 11)

add_executable(FirstMilestone main.cpp Lexer.cpp Lexer.h Command.cpp Command.h
        DefineVarCommand.cpp DefineVarCommand.h Var.cpp Var.h VariablesSymbolTable.cpp
        VariablesSymbolTable.h ConnectCommand.cpp ConnectCommand.h OpenServerCommand.cpp
        OpenServerCommand.h SleepCommand.cpp SleepCommand.h PrintCommand.cpp PrintCommand.h
        Parser.cpp Parser.h UpdateVarCommand.cpp UpdateVarCommand.h)
SET(CMAKE_CXX_FLAGS -pthread)