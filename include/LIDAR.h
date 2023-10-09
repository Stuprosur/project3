// 7.多线激光雷达
#ifndef LIDAR_H
#define LIDAR_H
#include <string>
#include <vector>
// 定义一个观察者接口
class Observer {
public:
    virtual void Update(const std::string& obstacle) = 0;
};


// 多线激光雷达类（主题）
class LIDAR {
public:
    LIDAR();
    LIDAR(const std::string& model, int channels, double range, double powerConsumption);

    void setModel(const std::string& model);
    void setChannels(int channels);
    void setRange(double range);
    void setPowerConsumption(double powerConsumption);

    void DetectObstacle(const std::string& obstacle);
    void Subscribe(Observer* observer);
    void Unsubscribe(Observer* observer);

    void print() const;
    void save(const std::string& filePath) const;

private:
    void NotifyObservers(const std::string& obstacle);

    std::string lidarModel;
    int lidarChannels;
    double lidarRange;
    double lidarPowerConsumption;

    std::vector<Observer*> observers;
};

#endif // LIDAR_H
