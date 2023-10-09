// 8.液晶显示屏
#ifndef DISPLAY_H
#define DISPLAY_H

#include <string>

class Display {
public:
    Display();
    Display(double size, const std::string& model);

    void setSize(double size);
    void setModel(const std::string& model);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    double displaySize;
    std::string displayModel;
};

#endif // DISPLAY_H
