// Display.cpp

#include "Display.h"
#include <iostream>
#include <fstream>

Display::Display() {
    // 默认构造函数的实现，初始化成员变量
    displaySize = 11.6;
    displayModel = "super";
}

Display::Display(double size, const std::string& model)
    : displaySize(size), displayModel(model) {
    // 带参数的构造函数的实现
}

void Display::setSize(double size) {
    displaySize = size;
}

void Display::setModel(const std::string& model) {
    displayModel = model;
}

void Display::print() const {
    // 屏幕输出的实现
    std::cout << "液晶显示屏信息：" << std::endl;
    std::cout << "尺寸: " << displaySize << " inches" << std::endl;
    std::cout << "型号: " << displayModel << std::endl;
}

void Display::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将显示屏对象的属性写入文件
    outputFile<< "液晶显示屏信息：" << std::endl;
    outputFile<< "尺寸: " << displaySize << " inches" << std::endl;
    outputFile<< "型号: " << displayModel << std::endl<<std::endl;

    outputFile.close();
}
