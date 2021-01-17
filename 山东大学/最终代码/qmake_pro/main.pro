TEMPLATE = app

CONFIG += debug
CONFIG += console
CONFIG += qt

QT += core
QT += gui
QT += widgets

INCLUDEPATH += "C:\opencv_sdu\install\include" 
INCLUDEPATH += "C:\libtorch\include"
INCLUDEPATH += "C:\libtorch\include\torch\csrc\api\include"


LIBS += -L"C:\opencv_sdu\install\x64\vc16\lib" -lopencv_videoio420d -lopencv_core420d -lopencv_imgcodecs420d -lopencv_highgui420d -lopencv_imgproc420d
LIBS += -L"C:\libtorch\lib"  -ltorch_cpu  -lc10

SOURCES  += main.cpp
SOURCES  += guis\app.cpp
SOURCES  += guis\frame.cpp
SOURCES  += devs\video.cpp
SOURCES  += models\lenet5.cpp
SOURCES  += models\lenet5_reco.cpp

HEADERS += guis\app.h
HEADERS += guis\frame.h
HEADERS += devs\video.h
SOURCES  += models\lenet5.h
SOURCES  += models\lenet5_reco.h

FORMS += forms\camera.ui
UI_DIR = forms

TARGET = main
