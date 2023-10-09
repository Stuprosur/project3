// Chassis.cpp

#include "D:\Code\CPP\Proj\project3\include\Chassis.h"
#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"
#include <iostream>
#include <fstream>

Chassis::Chassis() {
    // 默认构造函数的实现，初始化成员变量
    chassisNumber = "";
    chassisModel = "";
    chassisWheelbase = 0.0;
    chassisTrack = 0.0;
    chassisGroundClearance = 0.0;
    chassisTurningRadius = 0.0;
    chassisDriveType = "";
    chassisMaxRange = 0.0;
}

Chassis::Chassis(const std::string& number, const std::string& model, double wheelbase, double track, double groundClearance, double turningRadius, const std::string& driveType, double maxRange)
    : chassisNumber(number), chassisModel(model), chassisWheelbase(wheelbase), chassisTrack(track), chassisGroundClearance(groundClearance), chassisTurningRadius(turningRadius), chassisDriveType(driveType), chassisMaxRange(maxRange) {
    // 带参数的构造函数的实现
}

void Chassis::setNumber(const std::string& number) {
    chassisNumber = number;
}

void Chassis::setModel(const std::string& model) {
    chassisModel = model;
}

void Chassis::setWheelbase(double wheelbase) {
    chassisWheelbase = wheelbase;
}

void Chassis::setTrack(double track) {
    chassisTrack = track;
}

void Chassis::setGroundClearance(double groundClearance) {
    chassisGroundClearance = groundClearance;
}

void Chassis::setTurningRadius(double turningRadius) {
    chassisTurningRadius = turningRadius;
}

void Chassis::setDriveType(const std::string& driveType) {
    chassisDriveType = driveType;
}

void Chassis::setMaxRange(double maxRange) {
    chassisMaxRange = maxRange;
}

void Chassis::print() const {
    // 屏幕输出的实现
    std::cout << "底盘信息：" << std::endl;
    std::cout << "底盘编号: " << chassisNumber << std::endl;
    std::cout << "底盘型号: " << chassisModel << std::endl;
    std::cout << "轴距: " << chassisWheelbase << " mm" << std::endl;
    std::cout << "轮距: " << chassisTrack << " mm" << std::endl;
    std::cout << "最小离地间隙: " << chassisGroundClearance << " mm" << std::endl;
    std::cout << "最小转弯半径: " << chassisTurningRadius << " m" << std::endl;
    std::cout << "驱动形式: " << chassisDriveType << std::endl;
    std::cout << "最大行程: " << chassisMaxRange << " KM" << std::endl;
}

void Chassis::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将底盘对象的属性写入文件
    outputFile<< "底盘信息：" << std::endl;
    outputFile<< "底盘编号: " << chassisNumber << std::endl;
    outputFile<< "底盘型号: " << chassisModel << std::endl;
    outputFile<< "轴距: " << chassisWheelbase << " mm" << std::endl;
    outputFile<< "轮距: " << chassisTrack << " mm" << std::endl;
    outputFile<< "最小离地间隙: " << chassisGroundClearance << " mm" << std::endl;
    outputFile<< "最小转弯半径: " << chassisTurningRadius << " m" << std::endl;
    outputFile<< "驱动形式: " << chassisDriveType << std::endl;
    outputFile<< "最大行程: " << chassisMaxRange << " KM" << std::endl;

    outputFile.close();
}


void Chassis::Update(const std::string& obstacle) {
    // 根据障碍物状态执行操作
    if (obstacle == "前方") {
        std::cout << chassisNumber << "执行后退操作" << std::endl;
    } else if (obstacle == "右前方") {
        std::cout << chassisNumber << "执行左转操作" << std::endl;
    } else if (obstacle == "左前方") {
        std::cout << chassisNumber << "执行右转操作" << std::endl;
    }
}