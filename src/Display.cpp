// Display.cpp

#include "Display.h"
#include <iostream>
#include <fstream>

Display::Display() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    displaySize = 11.6;
    displayModel = "super";
}

Display::Display(double size, const std::string& model)
    : displaySize(size), displayModel(model) {
    // �������Ĺ��캯����ʵ��
}

void Display::setSize(double size) {
    displaySize = size;
}

void Display::setModel(const std::string& model) {
    displayModel = model;
}

void Display::print() const {
    // ��Ļ�����ʵ��
    std::cout << "Һ����ʾ����Ϣ��" << std::endl;
    std::cout << "�ߴ�: " << displaySize << " inches" << std::endl;
    std::cout << "�ͺ�: " << displayModel << std::endl;
}

void Display::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // ����ʾ�����������д���ļ�
    outputFile<< "Һ����ʾ����Ϣ��" << std::endl;
    outputFile<< "�ߴ�: " << displaySize << " inches" << std::endl;
    outputFile<< "�ͺ�: " << displayModel << std::endl<<std::endl;

    outputFile.close();
}
