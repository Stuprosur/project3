// 9.电池
#ifndef BATTERY_H
#define BATTERY_H

#include <string>

class Battery {
public:
    Battery();
    Battery(const std::string& voltage, double capacity, double chargeTime);

    void setVoltage(const std::string& voltage);
    void setCapacity(double capacity);
    void setChargeTime(double chargeTime);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string batteryVoltage;
    double batteryCapacity;
    double batteryChargeTime;
};

#endif // BATTERY_H
