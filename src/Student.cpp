#include "D:\Code\CPP\Proj\project2\include\Student.h"


// 构造函数实�?
Student::Student() {
    studentID = "";
    studentName = "";
}

// 设置学号
void Student::setStudentID(const std::string& id) {
    studentID = id;
}

// 设置姓名
void Student::setName(const std::string& name) {
    studentName = name;
}

std::string Student::getName(){
    return studentName;
}

std::string Student::getStudentID(){
    return studentID;
}

// 打印学生信息到屏�?
void Student::print() const {
    std::cout << "ѧ��: " << studentID << std::endl;
    std::cout << "����: " << studentName << std::endl;
}

// 保存学生信息到本地文�?
void Student::save(const std::string& filePath) const {
    std::ofstream outputFile(filePath, std::ios::app);

    if (!outputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filePath << " for writing." << std::endl;
        return;
    }

    // 将学生信息写入文�?
    outputFile << "ѧ��: " << studentID << std::endl;
    outputFile << "����: " << studentName << std::endl;

    outputFile.close();
}
