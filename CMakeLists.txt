cmake_minimum_required(VERSION 3.13)
project(FlightGearProj)

set(CMAKE_CXX_STANDARD 14)

add_executable(FlightGearProj main.cpp Interpreter.cpp Interpreter.h Command.h ConditionCommand.h Expression.h BinaryExpression.cpp BinaryExpression.h CommandExpression.cpp CommandExpression.h VarData.cpp VarData.h CommandFactory.cpp CommandFactory.h Utils.cpp Utils.h ExpsCollection.cpp ExpsCollection.h ReadCode.cpp ReadCode.h Threads.cpp Threads.h MathExpressions.cpp MathExpressions.h ConditionCommands.cpp ConditionCommands.h EntrcPrintSleepCommands.cpp EntrcPrintSleepCommands.h DefClientPlaceServerCommands.cpp DefClientPlaceServerCommands.h LexerParser.cpp LexerParser.h)
SET(CMAKE_CXX_FLAGS -pthread)