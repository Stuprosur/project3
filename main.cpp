#include <iostream>
#include "D:\Code\CPP\Proj\project3\include\Chassis.h"
#include "D:\Code\CPP\Proj\project3\include\LIDAR.h"

int main() {
    // �������߼����״����
    LIDAR lidar("RS-Helios-16p", 16, 100, 8);

    // �������̶���
    Chassis chassis1("dp0", "SCOUT MINI", 451, 490, 115, 0, "Four-wheel Drive", 10);
    Chassis chassis2("dp1", "SCOUT MINI", 451, 490, 115, 0, "Four-wheel Drive", 10);

    // �õ��̶����Ķ��߼����״�����
    lidar.Subscribe(&chassis1);
    lidar.Subscribe(&chassis2);

    // ����ϰ���״̬��֪ͨ����
    std::cout << "�������ϰ���״̬ (1: ǰ��, 2: ��ǰ��, 3: ��ǰ��): ";
    int obstacle;
    std::cin >> obstacle;

    if (obstacle == 1) {
        lidar.DetectObstacle("ǰ��");
    } else if (obstacle == 2) {
        lidar.DetectObstacle("��ǰ��");
    } else if (obstacle == 3) {
        lidar.DetectObstacle("��ǰ��");
    } else {
        std::cout << "δ֪�ϰ���״̬" << std::endl;
    }

    return 0;
}
