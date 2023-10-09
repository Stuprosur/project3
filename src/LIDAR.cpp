// LIDAR.cpp

#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"
#include <iostream>
#include <fstream>



LIDAR::LIDAR() {
    // 默认构造函数的实现，初始化成员变量
    lidarModel = "RS-Helios-16p";
    lidarChannels = 16;
    lidarRange = 100;
    lidarPowerConsumption = 8;
}

LIDAR::LIDAR(const std::string& model, int channels, double range, double powerConsumption)
    : lidarModel(model), lidarChannels(channels), lidarRange(range), lidarPowerConsumption(powerConsumption) {
    // 带参数的构造函数的实现
}

void LIDAR::setModel(const std::string& model) {
    lidarModel = model;
}

void LIDAR::setChannels(int channels) {
    lidarChannels = channels;
}

void LIDAR::setRange(double range) {
    lidarRange = range;
}

void LIDAR::setPowerConsumption(double powerConsumption) {
    lidarPowerConsumption = powerConsumption;
}

void LIDAR::print() const {
    // 屏幕输出的实现
    std::cout << "多线激光雷达信息：" << std::endl;
    std::cout << "型号: " << lidarModel << std::endl;
    std::cout << "通道数: " << lidarChannels << std::endl;
    std::cout << "测试范围: " << lidarRange << " m" << std::endl;
    std::cout << "功耗: " << lidarPowerConsumption << " W" << std::endl;
}

void LIDAR::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将激光雷达对象的属性写入文件

    outputFile << "多线激光雷达信息：" << std::endl;
    outputFile << "型号: " << lidarModel << std::endl;
    outputFile << "通道数: " << lidarChannels << std::endl;
    outputFile << "测试范围: " << lidarRange << " m" << std::endl;
    outputFile << "功耗: " << lidarPowerConsumption << " W" << std::endl<<std::endl;
    outputFile.close();
}



void LIDAR::DetectObstacle(const std::string& obstacle) {
    NotifyObservers(obstacle);
}

void LIDAR::Subscribe(Observer* observer) {
    observers.push_back(observer);
}

void LIDAR::Unsubscribe(Observer* observer) {
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        if(observer==*it) {
            observers.erase(it);
            return;
        }
    }
}

void LIDAR::NotifyObservers(const std::string& obstacle) {
    for (Observer* observer : observers) {
        observer->Update(obstacle);
    }
}