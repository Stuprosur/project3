// Camera.cpp

#include "Camera.h"
#include <iostream>
#include <fstream>

Camera::Camera() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    cameraModel = "RealSense D435i";
    cameraType = "D430";
    cameraResolutionX = 1920;
    cameraResolutionY = 1080;
    cameraFrameRate = 30;
    cameraFieldOfView = "87 58";
    cameraDepthFrameRate = 90;
}

Camera::Camera(const std::string& model, const std::string& cameraModel, int resolutionX, int resolutionY, int frameRate, std::string fieldOfView, int depthFrameRate)
    : cameraModel(cameraModel), cameraType(model), cameraResolutionX(resolutionX), cameraResolutionY(resolutionY), cameraFrameRate(frameRate), cameraFieldOfView(fieldOfView), cameraDepthFrameRate(depthFrameRate) {
    // �������Ĺ��캯����ʵ��
}

void Camera::setModel(const std::string& model) {
    cameraType = model;
}

void Camera::setCameraModel(const std::string& cameraModel) {
    this->cameraModel = cameraModel;
}

void Camera::setResolutionX(int resolutionX) {
    cameraResolutionX = resolutionX;
}

void Camera::setResolutionY(int resolutionY) {
    cameraResolutionY = resolutionY;
}

void Camera::setFrameRate(int frameRate) {
    cameraFrameRate = frameRate;
}

void Camera::setFieldOfView(const std::string& fieldOfView) {
    // ����ʹ���ַ����������ֶΣ������Ը�����Ҫ����ת��Ϊ��ֵ����
    cameraFieldOfView = fieldOfView;
}

void Camera::setDepthFrameRate(int depthFrameRate) {
    cameraDepthFrameRate = depthFrameRate;
}

void Camera::print() const {
    // ��Ļ�����ʵ��
    std::cout << "˫Ŀ����ͷ��Ϣ��" << std::endl;
    std::cout << "����ͷ�ͺ�: " << cameraModel << std::endl;
    std::cout << "����ͷ����: " << cameraType << std::endl;
    std::cout << "�ֱ���: " << cameraResolutionX << "x" << cameraResolutionY << std::endl;
    std::cout << "֡��: " << cameraFrameRate << " FPS" << std::endl;
    std::cout << "�ӳ���: " << cameraFieldOfView << " ��" << std::endl;
    std::cout << "���֡��: " << cameraDepthFrameRate << " FPS" << std::endl;
}

void Camera::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // ������ͷ���������д���ļ�
    outputFile << "˫Ŀ����ͷ��Ϣ��" << std::endl;
    outputFile << "����ͷ�ͺ�: " << cameraModel << std::endl;
    outputFile << "����ͷ����: " << cameraType << std::endl;
    outputFile << "�ֱ���: " << cameraResolutionX << "x" << cameraResolutionY << std::endl;
    outputFile << "֡��: " << cameraFrameRate << " FPS" << std::endl;
    outputFile << "�ӳ���: " << cameraFieldOfView << " ��" << std::endl;
    outputFile << "���֡��: " << cameraDepthFrameRate << " FPS" << std::endl<<std::endl;

    outputFile.close();
}
