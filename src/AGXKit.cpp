#include "AGXKit.h"
#include <iostream>
#include <fstream>

AGXKit::AGXKit() {
    // Ĭ�Ϲ��캯����ʵ�֣���ʼ����Ա����
    agxModel = "AGX Xavier";
    agxAIPerformance = 32;
    agxCudaCores = 512;
    agxTensorCores = 64;
    agxMemorySize = 32;
    agxStorageSize = 32;
}

AGXKit::AGXKit(const std::string& model, double aiPerformance, int cudaCores, int tensorCores, double memorySize, double storageSize)
    : agxModel(model), agxAIPerformance(aiPerformance), agxCudaCores(cudaCores), agxTensorCores(tensorCores), agxMemorySize(memorySize), agxStorageSize(storageSize) {
    // ���캯����ʵ��
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
    // ��Ļ�����ʵ��
    std::cout << "AGX�׼���Ϣ��" << std::endl;
    std::cout << "�ͺ�: " << agxModel << std::endl;
    std::cout << "AI����: " << agxAIPerformance << " TOPS" << std::endl;
    std::cout << "CUDA����: " << agxCudaCores << std::endl;
    std::cout << "Tensor CORE: " << agxTensorCores << std::endl;
    std::cout << "�Դ��С: " << agxMemorySize << " GB" << std::endl;
    std::cout << "�洢��С: " << agxStorageSize << " GB" << std::endl;
}



void AGXKit::save(const std::string& filePath) const {
    // �����ļ������ʵ��
    std::ofstream outputFile(filePath, std::ios::app); 

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // �����������д���ļ�
    outputFile << "AGX�׼���Ϣ��" << std::endl;
    outputFile << "�ͺ�: " << agxModel << std::endl;
    outputFile << "AI����: " << agxAIPerformance << " TOPS" << std::endl;
    outputFile << "CUDA����: " << agxCudaCores << std::endl;
    outputFile << "Tensor CORE: " << agxTensorCores << std::endl;
    outputFile << "�Դ��С: " << agxMemorySize << " GB" << std::endl;
    outputFile << "�洢��С: " << agxStorageSize << " GB" << std::endl<<std::endl;


    outputFile.close();
}


