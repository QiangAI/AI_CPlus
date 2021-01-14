# 项目模板（编译的是app应用？lib库等）
TEMPLATE = app
# 基本配置
CONFIG += debug
CONFIG += console
CONFIG += qt
# QT的库
QT += core
QT += gui
QT += widgets
# 头文件
INCLUDEPATH = "C:\opencv_sdu\install\include"

# OpenCV的库
LIBS += -L"C:\opencv_sdu\install\x64\vc16\lib" -lopencv_videoio420d -lopencv_core420d -lopencv_imgcodecs420d -lopencv_highgui420d -lopencv_imgproc420d

# 源代码与头文件
SOURCES  += main.cpp
SOURCES  += guis\app.cpp
SOURCES  += guis\frame.cpp
SOURCES  += devs\video.cpp

HEADERS += guis\app.h
HEADERS += guis\frame.h
HEADERS += devs\video.h

FORMS += forms\camera.ui
UI_DIR = forms
# 编译的执行文件
TARGET = main
