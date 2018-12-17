cmake_minimum_required(VERSION 3.13)
project(ori_lexer)

set(CMAKE_CXX_STANDARD 14)

add_executable(ori_lexer main.cpp Interpreter.cpp Interpreter.h Command.cpp Command.h DefineVarCommand.cpp DefineVarCommand.h ConditionCommand.cpp ConditionCommand.h ConnectCommand.cpp ConnectCommand.h LoopCommand.cpp LoopCommand.h IfCommand.cpp IfCommand.h OpenServerCommand.cpp OpenServerCommand.h Expression.cpp Expression.h BinaryExpression.cpp BinaryExpression.h Number.cpp Number.h Plus.cpp Plus.h Minus.cpp Minus.h Div.cpp Div.h Mul.cpp Mul.h CommandExpression.cpp CommandExpression.h VarData.cpp VarData.h CommandFactory.cpp CommandFactory.h CmdsCollection.cpp CmdsCollection.h PrintCommand.cpp PrintCommand.h)