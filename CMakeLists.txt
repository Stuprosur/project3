cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_COMPILER "D:/mingw64/bin/g++.exe")

set(CMAKE_C_COMPILER "D:/mingw64/bin/gcc.exe")


project(project3)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)

# 添加可执行文件
add_executable(project3
    main.cpp
    src/SmartCar.cpp
    src/Chassis.cpp
    src/AGXKit.cpp
    src/Camera.cpp
    src/LIDAR.cpp
    src/Gyroscope.cpp
    src/Display.cpp
    src/Battery.cpp
    src/Wheel.cpp
    src/Student.cpp
)

# 增加编译参数
add_compile_options(-fexec-charset=gbk)
add_compile_options(-finput-charset=gbk)


# 包含头文件目录
target_include_directories(project3 PRIVATE include)



