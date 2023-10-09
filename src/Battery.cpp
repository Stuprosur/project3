#include "Battery.h"
#include <iostream>
#include <fstream>
#include <string>

Battery::Battery(){
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    batteryVoltage = "24V/15Ah";
    batteryCapacity = 24;
    batteryChargeTime = 2;
}

Battery::Battery(const std::string& voltage, double capacity, double chargeTime)
    : batteryVoltage(voltage), batteryCapacity(capacity), batteryChargeTime(chargeTime) {
    // ���캯����ʵ��
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
    // ��Ļ�����ʵ��
    std::cout << "�����Ϣ��" << std::endl;
    std::cout << "��ص�ѹ: " << batteryVoltage << " V" << std::endl;
    std::cout << "�������: " << batteryCapacity << " Ah" << std::endl;
    std::cout << "���ʱ��: " << batteryChargeTime << " Сʱ" << std::endl;
}

void Battery::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // ����ض��������д���ļ�
    outputFile << "�����Ϣ��" << std::endl;
    outputFile << "��ص�ѹ: " << batteryVoltage << " V" << std::endl;
    outputFile << "�������: " << batteryCapacity << " Ah" << std::endl;
    outputFile << "���ʱ��: " << batteryChargeTime << " Сʱ" << std::endl<<std::endl;

    outputFile.close();
}

