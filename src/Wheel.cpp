#include "Wheel.h"
#include <iostream>
#include <fstream>

Wheel::Wheel(){}

Wheel::Wheel(const std::string& model, double size)
    : wheelModel(model), wheelSize(size) {
    // ���캯����ʵ��
}

void Wheel::setModel(const std::string& model) {
    wheelModel = model;
}


void Wheel::setSize(double size) {
    wheelSize = size;
}

void Wheel::print() const {
    std::cout << "��̥�ͺ�: " << wheelModel << std::endl;
    std::cout << "��̥�ߴ�: " << wheelSize << " inches" << std::endl;
}

void Wheel::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // ����̥���������д���ļ�
    outputFile << "��̥�ͺ�: " << wheelModel << std::endl;
    outputFile << "��̥�ߴ�: " << wheelSize << " inches" << std::endl;

    outputFile.close();
}

