// Chassis.cpp

#include "D:\Code\CPP\Proj\project3\include\Chassis.h"
#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"
#include <iostream>
#include <fstream>

Chassis::Chassis() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
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
    // �������Ĺ��캯����ʵ��
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
    // ��Ļ�����ʵ��
    std::cout << "������Ϣ��" << std::endl;
    std::cout << "���̱��: " << chassisNumber << std::endl;
    std::cout << "�����ͺ�: " << chassisModel << std::endl;
    std::cout << "���: " << chassisWheelbase << " mm" << std::endl;
    std::cout << "�־�: " << chassisTrack << " mm" << std::endl;
    std::cout << "��С��ؼ�϶: " << chassisGroundClearance << " mm" << std::endl;
    std::cout << "��Сת��뾶: " << chassisTurningRadius << " m" << std::endl;
    std::cout << "������ʽ: " << chassisDriveType << std::endl;
    std::cout << "����г�: " << chassisMaxRange << " KM" << std::endl;
}

void Chassis::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // �����̶��������д���ļ�
    outputFile<< "������Ϣ��" << std::endl;
    outputFile<< "���̱��: " << chassisNumber << std::endl;
    outputFile<< "�����ͺ�: " << chassisModel << std::endl;
    outputFile<< "���: " << chassisWheelbase << " mm" << std::endl;
    outputFile<< "�־�: " << chassisTrack << " mm" << std::endl;
    outputFile<< "��С��ؼ�϶: " << chassisGroundClearance << " mm" << std::endl;
    outputFile<< "��Сת��뾶: " << chassisTurningRadius << " m" << std::endl;
    outputFile<< "������ʽ: " << chassisDriveType << std::endl;
    outputFile<< "����г�: " << chassisMaxRange << " KM" << std::endl;

    outputFile.close();
}


void Chassis::Update(const std::string& obstacle) {
    // �����ϰ���״ִ̬�в���
    if (obstacle == "ǰ��") {
        std::cout << chassisNumber << "ִ�к��˲���" << std::endl;
    } else if (obstacle == "��ǰ��") {
        std::cout << chassisNumber << "ִ����ת����" << std::endl;
    } else if (obstacle == "��ǰ��") {
        std::cout << chassisNumber << "ִ����ת����" << std::endl;
    }
}