// 3.轮胎
#ifndef WHEEL_H
#define WHEEL_H

#include <string>

class Wheel {
public:
    Wheel();
    Wheel(const std::string& model, double size);

    void setModel(const std::string& model);
    void setSize(double size);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string wheelModel;
    std::string wheelType;
    double wheelSize;
};

#endif // WHEEL_H
