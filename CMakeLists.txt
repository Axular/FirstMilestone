cmake_minimum_required(VERSION 3.15)
project(FirstMilestone)

set(CMAKE_CXX_STANDARD 11)

add_executable(FirstMilestone main.cpp Lexer.cpp Lexer.h Command.cpp Command.h
        DefineVarCommand.cpp DefineVarCommand.h Var.cpp Var.h VariablesSymbolTable.cpp
        VariablesSymbolTable.h ConnectCommand.cpp ConnectCommand.h OpenServerCommand.cpp
        OpenServerCommand.h SleepCommand.cpp SleepCommand.h PrintCommand.cpp PrintCommand.h
        Parser.cpp Parser.h UpdateVarCommand.cpp UpdateVarCommand.h ConditionParser.cpp
        WhileLoopCommand.cpp WhileLoopCommand.h ex1.h ex1.cpp globals.cpp globals.h Interpreter.cpp Interpreter.h
        BinaryOperator.h BinaryOperator.cpp Var.cpp Var.h Value.cpp Value.cpp Minus.h Minus.cpp Plus.cpp
        Plus.h Div.cpp Div.h UMinus.cpp UMinus.h UPlus.cpp UPlus.h Variable.cpp Variable.h Mul.cpp Mul.h
        UnaryOperator.cpp UnaryOperator.h test.cpp test.h)
SET(CMAKE_CXX_FLAGS -pthread)