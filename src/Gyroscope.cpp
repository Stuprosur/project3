// Gyroscope.cpp

#include "Gyroscope.h"
#include <iostream>
#include <fstream>

Gyroscope::Gyroscope() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    gyroModel = "CH110";
    gyroManufacturer = "NXP";
}

Gyroscope::Gyroscope(const std::string& model, const std::string& manufacturer)
    : gyroModel(model), gyroManufacturer(manufacturer) {
    // �������Ĺ��캯����ʵ��
}

void Gyroscope::setModel(const std::string& model) {
    gyroModel = model;
}

void Gyroscope::setManufacturer(const std::string& manufacturer) {
    gyroManufacturer = manufacturer;
}

void Gyroscope::print() const {
    // ��Ļ�����ʵ��
    std::cout << "9����������Ϣ:" << std::endl;
    std::cout << "�ͺ�: " << gyroModel << std::endl;
    std::cout << "������: " << gyroManufacturer << std::endl;
}

void Gyroscope::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // �������Ƕ��������д���ļ�
    outputFile << "9����������Ϣ:" << std::endl;
    outputFile << "�ͺ�: " << gyroModel << std::endl;
    outputFile << "������: " << gyroManufacturer << std::endl<<std::endl;

    outputFile.close();
}
