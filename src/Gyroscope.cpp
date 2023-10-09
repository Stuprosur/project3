// Gyroscope.cpp

#include "Gyroscope.h"
#include <iostream>
#include <fstream>

Gyroscope::Gyroscope() {
    // 默认构造函数的实现，初始化成员变量
    gyroModel = "CH110";
    gyroManufacturer = "NXP";
}

Gyroscope::Gyroscope(const std::string& model, const std::string& manufacturer)
    : gyroModel(model), gyroManufacturer(manufacturer) {
    // 带参数的构造函数的实现
}

void Gyroscope::setModel(const std::string& model) {
    gyroModel = model;
}

void Gyroscope::setManufacturer(const std::string& manufacturer) {
    gyroManufacturer = manufacturer;
}

void Gyroscope::print() const {
    // 屏幕输出的实现
    std::cout << "9轴陀螺仪信息:" << std::endl;
    std::cout << "型号: " << gyroModel << std::endl;
    std::cout << "制造商: " << gyroManufacturer << std::endl;
}

void Gyroscope::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将陀螺仪对象的属性写入文件
    outputFile << "9轴陀螺仪信息:" << std::endl;
    outputFile << "型号: " << gyroModel << std::endl;
    outputFile << "制造商: " << gyroManufacturer << std::endl<<std::endl;

    outputFile.close();
}
