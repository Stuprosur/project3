// 5.双目摄像头
#ifndef CAMERA_H
#define CAMERA_H

#include <string>

class Camera {
public:
    Camera();
    Camera(const std::string& model, const std::string& cameraModel, int resolutionX, int resolutionY, int frameRate, std::string fieldOfView, int depthFrameRate);

    void setModel(const std::string& model);
    void setCameraModel(const std::string& cameraModel);
    void setResolutionX(int resolutionX);
    void setResolutionY(int resolutionY);
    void setFrameRate(int frameRate);
    void setFieldOfView(const std::string& fieldOfView);
    void setDepthFrameRate(int depthFrameRate);

    void print() const;
    void save(const std::string& filePath) const; 

private:
    std::string cameraModel;
    std::string cameraType;
    int cameraResolutionX;
    int cameraResolutionY;
    int cameraFrameRate;
    std::string cameraFieldOfView;
    int cameraDepthFrameRate;
};

#endif // CAMERA_H
