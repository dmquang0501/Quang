cmake_minimum_required(VERSION 2.8)

project(cmd_parser)
add_executable(${PROJECT_NAME} "main.cpp" "cmd_line.c" "cmd_line.h")
