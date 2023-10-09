#ifndef SMARTCAR_H
#define SMARTCAR_H

#include <string>
#include <vector>
#include "Chassis.h"
#include "AGXKit.h"
#include "Camera.h"
#include "LIDAR.h"
#include "Gyroscope.h"
#include "Display.h"
#include "Battery.h"
#include "Wheel.h"
#include "Student.h"

class SmartCar {
public:
    SmartCar();
    SmartCar(const std::string& id);

    void setID(const std::string& id);
    void setChassis(const Chassis& chassis);
    void setAGXKit(const AGXKit& agxKit);
    void setCamera(const Camera& camera);
    void setLIDAR(const LIDAR& lidar);
    void setGyroscope(const Gyroscope& gyro);
    void setDisplay(const Display& display);
    void setBattery(const Battery& battery);
    void setWheels(const std::vector<Wheel>& wheels);
    void AssignToStudent(const Student& student);
    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string carID;
    Chassis chassis;
    AGXKit agxKit;
    Camera camera;
    LIDAR lidar;
    Gyroscope gyro;
    Display display;
    Battery battery;
    std::vector<Wheel> wheels;
    //所属的学生信息
    Student student;
};

#endif // SMARTCAR_H
