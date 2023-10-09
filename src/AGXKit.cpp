#include "AGXKit.h"
#include <iostream>
#include <fstream>

AGXKit::AGXKit() {
    // 默认构造函数的实现，初始化成员变量
    agxModel = "AGX Xavier";
    agxAIPerformance = 32;
    agxCudaCores = 512;
    agxTensorCores = 64;
    agxMemorySize = 32;
    agxStorageSize = 32;
}

AGXKit::AGXKit(const std::string& model, double aiPerformance, int cudaCores, int tensorCores, double memorySize, double storageSize)
    : agxModel(model), agxAIPerformance(aiPerformance), agxCudaCores(cudaCores), agxTensorCores(tensorCores), agxMemorySize(memorySize), agxStorageSize(storageSize) {
    // 构造函数的实现
}

void AGXKit::setModel(const std::string& model) {
    agxModel = model;
}

void AGXKit::setAIPerformance(double aiPerformance) {
    agxAIPerformance = aiPerformance;
}


void AGXKit::setCudaCores(int cudaCores) {
    agxCudaCores = cudaCores;
}

void AGXKit::setTensorCores(int tensorCores) {
    agxTensorCores = tensorCores;
}

void AGXKit::setMemorySize(double memorySize) {
    agxMemorySize = memorySize;
}

void AGXKit::setStorageSize(double storageSize) {
    agxStorageSize = storageSize;
}

void AGXKit::print() const {
    // 屏幕输出的实现
    std::cout << "AGX套件信息：" << std::endl;
    std::cout << "型号: " << agxModel << std::endl;
    std::cout << "AI性能: " << agxAIPerformance << " TOPS" << std::endl;
    std::cout << "CUDA核心: " << agxCudaCores << std::endl;
    std::cout << "Tensor CORE: " << agxTensorCores << std::endl;
    std::cout << "显存大小: " << agxMemorySize << " GB" << std::endl;
    std::cout << "存储大小: " << agxStorageSize << " GB" << std::endl;
}



void AGXKit::save(const std::string& filePath) const {
    // 本地文件保存的实现
    std::ofstream outputFile(filePath, std::ios::app); 

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将对象的属性写入文件
    outputFile << "AGX套件信息：" << std::endl;
    outputFile << "型号: " << agxModel << std::endl;
    outputFile << "AI性能: " << agxAIPerformance << " TOPS" << std::endl;
    outputFile << "CUDA核心: " << agxCudaCores << std::endl;
    outputFile << "Tensor CORE: " << agxTensorCores << std::endl;
    outputFile << "显存大小: " << agxMemorySize << " GB" << std::endl;
    outputFile << "存储大小: " << agxStorageSize << " GB" << std::endl<<std::endl;


    outputFile.close();
}


