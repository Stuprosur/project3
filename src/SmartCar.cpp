#include "D:\Code\CPP\Proj\project2\include\SmartCar.h"
#include <iostream>
#include <fstream>

SmartCar::SmartCar() {
    // Ĭ�Ϲ��캯����ʵ��
}

SmartCar::SmartCar(const std::string& id) : carID(id) {
    // ���캯����ʵ��
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
    // ��Ļ�����ʵ��
    std::cout << "SmartCar ID: " << carID << std::endl;

    // ��ӡ������Ϣ
    chassis.print();
    // ��ӡ��̥��Ϣ
    for (const Wheel& wheel : wheels) {
        wheel.print();
        break;
    }

    // ��ӡAGXKit��Ϣ
    agxKit.print();

    // ��ӡ����ͷ��Ϣ
    camera.print();

    // ��ӡLIDAR��Ϣ
    lidar.print();

    // ��ӡ��������Ϣ
    gyro.print();

    // ��ӡ��ʾ����Ϣ
    display.print();

    // ��ӡ�����Ϣ
    battery.print();



    // ��ӡ������ѧ����Ϣ
    student.print();

    std::cout<< "------------------ " <<std::endl;
}

void SmartCar::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // ��������Ϣд���ļ�
    outputFile << "SmartCar ID: " << carID << std::endl;
    
    // ���������Ϣ
    chassis.save(filePath);
    // ������̥��Ϣ
    for (const Wheel& wheel : wheels) {
        wheel.save(filePath);
        break;
    }
    outputFile <<std::endl;
    // ����AGXKit��Ϣ
    agxKit.save(filePath);

    // ��������ͷ��Ϣ
    camera.save(filePath);

    // ����LIDAR��Ϣ
    lidar.save(filePath);

    // ������������Ϣ
    gyro.save(filePath);

    // ������ʾ����Ϣ
    display.save(filePath);

    // ��������Ϣ
    battery.save(filePath);



    // ���������ѧ����Ϣ
    student.save(filePath);

    outputFile << "------------------- " <<std::endl;

    outputFile.close();
}
