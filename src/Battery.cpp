#include "Battery.h"
#include <iostream>
#include <fstream>
#include <string>

Battery::Battery(){
    // 默认构造函数的实现，初始化成员变量
    batteryVoltage = "24V/15Ah";
    batteryCapacity = 24;
    batteryChargeTime = 2;
}

Battery::Battery(const std::string& voltage, double capacity, double chargeTime)
    : batteryVoltage(voltage), batteryCapacity(capacity), batteryChargeTime(chargeTime) {
    // 构造函数的实现
}

void Battery::setVoltage(const std::string& voltage) {
    batteryVoltage = voltage;
}

void Battery::setCapacity(double capacity) {
    batteryCapacity = capacity;
}

void Battery::setChargeTime(double chargeTime) {
    batteryChargeTime = chargeTime;
}

void Battery::print() const {
    // 屏幕输出的实现
    std::cout << "电池信息：" << std::endl;
    std::cout << "电池电压: " << batteryVoltage << " V" << std::endl;
    std::cout << "电池容量: " << batteryCapacity << " Ah" << std::endl;
    std::cout << "充电时间: " << batteryChargeTime << " 小时" << std::endl;
}

void Battery::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将电池对象的属性写入文件
    outputFile << "电池信息：" << std::endl;
    outputFile << "电池电压: " << batteryVoltage << " V" << std::endl;
    outputFile << "电池容量: " << batteryCapacity << " Ah" << std::endl;
    outputFile << "充电时间: " << batteryChargeTime << " 小时" << std::endl<<std::endl;

    outputFile.close();
}

