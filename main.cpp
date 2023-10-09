#include <iostream>
#include "D:\Code\CPP\Proj\project3\include\Chassis.h"
#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"

int main() {
    // 创建多线激光雷达对象
    LIDAR lidar("RS-Helios-16p", 16, 100, 8);

    // 创建底盘对象
    Chassis chassis1("dp0", "SCOUT MINI", 451, 490, 115, 0, "Four-wheel Drive", 10);
    Chassis chassis2("dp1", "SCOUT MINI", 451, 490, 115, 0, "Four-wheel Drive", 10);

    // 让底盘对象订阅多线激光雷达主题
    lidar.Subscribe(&chassis1);
    lidar.Subscribe(&chassis2);

    // 检测障碍物状态并通知底盘
    std::cout << "请输入障碍物状态 (1: 前方, 2: 右前方, 3: 左前方): ";
    int obstacle;
    std::cin >> obstacle;

    if (obstacle == 1) {
        lidar.DetectObstacle("前方");
    } else if (obstacle == 2) {
        lidar.DetectObstacle("右前方");
    } else if (obstacle == 3) {
        lidar.DetectObstacle("左前方");
    } else {
        std::cout << "未知障碍物状态" << std::endl;
    }

    return 0;
}
