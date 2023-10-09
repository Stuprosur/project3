#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
#include <fstream>

class Student {
public:
    // 构造函数
    Student();

    // 设置学号
    void setStudentID(const std::string& id);

    // 设置姓名
    void setName(const std::string& name);

    // 学号
    std::string getStudentID();

    // 姓名
    std::string getName();

    // 打印学生信息到屏幕
    void print() const;

    // 保存学生信息到本地文件
    void save(const std::string& filePath) const;

private:
    std::string studentID;
    std::string studentName;
};

#endif // STUDENT_H
