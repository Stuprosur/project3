// 4.agx套件
#ifndef AGXKIT_H
#define AGXKIT_H

#include <string>

class AGXKit {
public:
    AGXKit();
    AGXKit(const std::string& model, double aiPerformance, int cudaCores, int tensorCores, double memorySize, double storageSize);

    void setModel(const std::string& model);
    void setAIPerformance(double aiPerformance);
    void setCudaCores(int cudaCores);
    void setTensorCores(int tensorCores);
    void setMemorySize(double memorySize);
    void setStorageSize(double storageSize);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string agxModel;
    double agxAIPerformance;
    int agxCudaCores;
    int agxTensorCores;
    double agxMemorySize;
    double agxStorageSize;
};

#endif // AGXKIT_H
