cmake_minimum_required(VERSION 3.20)
project(cs C)

set(CMAKE_C_STANDARD 99)

#允许一个项目中多个main函数
file (GLOB files *.c */*.c)
foreach (file ${files})
    string(REGEX REPLACE ".+/(.+)/(.+)\\..*" "\\1-\\2" exe ${file})
    add_executable (${exe} ${file})
endforeach ()