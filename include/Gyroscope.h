// 6. 9轴陀螺仪
#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <string>

class Gyroscope {
public:
    Gyroscope();
    Gyroscope(const std::string& model, const std::string& manufacturer);

    void setModel(const std::string& model);
    void setManufacturer(const std::string& manufacturer);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string gyroModel;
    std::string gyroManufacturer;
};

#endif // GYROSCOPE_H
