// Camera.cpp

#include "Camera.h"
#include <iostream>
#include <fstream>

Camera::Camera() {
    // 默认构造函数的实现，初始化成员变量
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
    // 带参数的构造函数的实现
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
    // 这里使用字符串来设置字段，您可以根据需要将其转换为数值类型
    cameraFieldOfView = fieldOfView;
}

void Camera::setDepthFrameRate(int depthFrameRate) {
    cameraDepthFrameRate = depthFrameRate;
}

void Camera::print() const {
    // 屏幕输出的实现
    std::cout << "双目摄像头信息：" << std::endl;
    std::cout << "摄像头型号: " << cameraModel << std::endl;
    std::cout << "摄像头类型: " << cameraType << std::endl;
    std::cout << "分辨率: " << cameraResolutionX << "x" << cameraResolutionY << std::endl;
    std::cout << "帧率: " << cameraFrameRate << " FPS" << std::endl;
    std::cout << "视场角: " << cameraFieldOfView << " 度" << std::endl;
    std::cout << "深度帧率: " << cameraDepthFrameRate << " FPS" << std::endl;
}

void Camera::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将摄像头对象的属性写入文件
    outputFile << "双目摄像头信息：" << std::endl;
    outputFile << "摄像头型号: " << cameraModel << std::endl;
    outputFile << "摄像头类型: " << cameraType << std::endl;
    outputFile << "分辨率: " << cameraResolutionX << "x" << cameraResolutionY << std::endl;
    outputFile << "帧率: " << cameraFrameRate << " FPS" << std::endl;
    outputFile << "视场角: " << cameraFieldOfView << " 度" << std::endl;
    outputFile << "深度帧率: " << cameraDepthFrameRate << " FPS" << std::endl<<std::endl;

    outputFile.close();
}
