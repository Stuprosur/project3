#include "Wheel.h"
#include <iostream>
#include <fstream>

Wheel::Wheel(){}

Wheel::Wheel(const std::string& model, double size)
    : wheelModel(model), wheelSize(size) {
    // 构造函数的实现
}

void Wheel::setModel(const std::string& model) {
    wheelModel = model;
}


void Wheel::setSize(double size) {
    wheelSize = size;
}

void Wheel::print() const {
    std::cout << "轮胎型号: " << wheelModel << std::endl;
    std::cout << "轮胎尺寸: " << wheelSize << " inches" << std::endl;
}

void Wheel::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将轮胎对象的属性写入文件
    outputFile << "轮胎型号: " << wheelModel << std::endl;
    outputFile << "轮胎尺寸: " << wheelSize << " inches" << std::endl;

    outputFile.close();
}

