// LIDAR.cpp

#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"
#include <iostream>
#include <fstream>



LIDAR::LIDAR() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    lidarModel = "RS-Helios-16p";
    lidarChannels = 16;
    lidarRange = 100;
    lidarPowerConsumption = 8;
}

LIDAR::LIDAR(const std::string& model, int channels, double range, double powerConsumption)
    : lidarModel(model), lidarChannels(channels), lidarRange(range), lidarPowerConsumption(powerConsumption) {
    // �������Ĺ��캯����ʵ��
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
    // ��Ļ�����ʵ��
    std::cout << "���߼����״���Ϣ��" << std::endl;
    std::cout << "�ͺ�: " << lidarModel << std::endl;
    std::cout << "ͨ����: " << lidarChannels << std::endl;
    std::cout << "���Է�Χ: " << lidarRange << " m" << std::endl;
    std::cout << "����: " << lidarPowerConsumption << " W" << std::endl;
}

void LIDAR::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // �������״���������д���ļ�

    outputFile << "���߼����״���Ϣ��" << std::endl;
    outputFile << "�ͺ�: " << lidarModel << std::endl;
    outputFile << "ͨ����: " << lidarChannels << std::endl;
    outputFile << "���Է�Χ: " << lidarRange << " m" << std::endl;
    outputFile << "����: " << lidarPowerConsumption << " W" << std::endl<<std::endl;
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