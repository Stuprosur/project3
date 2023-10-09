#include "D:\Code\CPP\Proj\project2\include\SmartCar.h"
#include <iostream>
#include <fstream>

SmartCar::SmartCar() {
    // 默认构造函数的实现
}

SmartCar::SmartCar(const std::string& id) : carID(id) {
    // 构造函数的实现
}

void SmartCar::setID(const std::string& id) {
    carID = id;
}

void SmartCar::setChassis(const Chassis& chassis) {
    this->chassis = chassis;
}

void SmartCar::setAGXKit(const AGXKit& agxKit) {
    this->agxKit = agxKit;
}

void SmartCar::setCamera(const Camera& camera) {
    this->camera = camera;
}

void SmartCar::setLIDAR(const LIDAR& lidar) {
    this->lidar = lidar;
}

void SmartCar::setGyroscope(const Gyroscope& gyro) {
    this->gyro = gyro;
}

void SmartCar::setDisplay(const Display& display) {
    this->display = display;
}

void SmartCar::setBattery(const Battery& battery) {
    this->battery = battery;
}

void SmartCar::setWheels(const std::vector<Wheel>& wheels) {
    this->wheels = wheels;
}

void SmartCar::AssignToStudent(const Student& student) {
    this->student = student;
}

void SmartCar::print() const {
    // 屏幕输出的实现
    std::cout << "SmartCar ID: " << carID << std::endl;

    // 打印底盘信息
    chassis.print();
    // 打印轮胎信息
    for (const Wheel& wheel : wheels) {
        wheel.print();
        break;
    }

    // 打印AGXKit信息
    agxKit.print();

    // 打印摄像头信息
    camera.print();

    // 打印LIDAR信息
    lidar.print();

    // 打印陀螺仪信息
    gyro.print();

    // 打印显示屏信息
    display.print();

    // 打印电池信息
    battery.print();



    // 打印关联的学生信息
    student.print();

    std::cout<< "------------------ " <<std::endl;
}

void SmartCar::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将车辆信息写入文件
    outputFile << "SmartCar ID: " << carID << std::endl;
    
    // 保存底盘信息
    chassis.save(filePath);
    // 保存轮胎信息
    for (const Wheel& wheel : wheels) {
        wheel.save(filePath);
        break;
    }
    outputFile <<std::endl;
    // 保存AGXKit信息
    agxKit.save(filePath);

    // 保存摄像头信息
    camera.save(filePath);

    // 保存LIDAR信息
    lidar.save(filePath);

    // 保存陀螺仪信息
    gyro.save(filePath);

    // 保存显示屏信息
    display.save(filePath);

    // 保存电池信息
    battery.save(filePath);



    // 保存关联的学生信息
    student.save(filePath);

    outputFile << "------------------- " <<std::endl;

    outputFile.close();
}
