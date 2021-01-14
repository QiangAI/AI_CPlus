/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMERA_H
#define UI_CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QFrame *frm_video;
    QLabel *lbl_video;
    QPushButton *btn_capture;
    QLabel *lbl_digit_image;
    QPushButton *btn_recognize;
    QLabel *lbl_digit_result;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(920, 275);
        Camera->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	color: red;\n"
"	border-width:1px;\n"
"	border-style:solid;\n"
"	border-radius:6px;\n"
"	border-top-color: #FFFFFF;\n"
"	border-right-color: #FFFFFF;\n"
"	border-bottom-color: #BBBBBB;\n"
"	border-left-color: #BBBBBB;\n"
"}"));
        frm_video = new QFrame(Camera);
        frm_video->setObjectName(QString::fromUtf8("frm_video"));
        frm_video->setGeometry(QRect(20, 20, 321, 231));
        frm_video->setFrameShape(QFrame::Box);
        frm_video->setFrameShadow(QFrame::Raised);
        lbl_video = new QLabel(frm_video);
        lbl_video->setObjectName(QString::fromUtf8("lbl_video"));
        lbl_video->setGeometry(QRect(10, 10, 301, 211));
        lbl_video->setAlignment(Qt::AlignCenter);
        btn_capture = new QPushButton(Camera);
        btn_capture->setObjectName(QString::fromUtf8("btn_capture"));
        btn_capture->setGeometry(QRect(360, 120, 93, 28));
        lbl_digit_image = new QLabel(Camera);
        lbl_digit_image->setObjectName(QString::fromUtf8("lbl_digit_image"));
        lbl_digit_image->setGeometry(QRect(480, 70, 151, 121));
        lbl_digit_image->setFrameShape(QFrame::Panel);
        lbl_digit_image->setFrameShadow(QFrame::Raised);
        lbl_digit_image->setAlignment(Qt::AlignCenter);
        btn_recognize = new QPushButton(Camera);
        btn_recognize->setObjectName(QString::fromUtf8("btn_recognize"));
        btn_recognize->setGeometry(QRect(660, 120, 93, 28));
        lbl_digit_result = new QLabel(Camera);
        lbl_digit_result->setObjectName(QString::fromUtf8("lbl_digit_result"));
        lbl_digit_result->setGeometry(QRect(790, 100, 111, 61));
        lbl_digit_result->setAlignment(Qt::AlignCenter);

        retranslateUi(Camera);
        QObject::connect(btn_capture, SIGNAL(clicked()), Camera, SLOT(capture()));
        QObject::connect(btn_recognize, SIGNAL(clicked()), Camera, SLOT(recognize()));

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QCoreApplication::translate("Camera", "\344\272\272\345\267\245\346\231\272\350\203\275 - \346\211\213\345\206\231\346\225\260\345\255\227\350\257\206\345\210\253", nullptr));
        lbl_video->setText(QCoreApplication::translate("Camera", "\350\247\206\351\242\221\346\230\276\347\244\272\345\214\272", nullptr));
        btn_capture->setText(QCoreApplication::translate("Camera", "\346\212\223\345\233\276", nullptr));
        lbl_digit_image->setText(QCoreApplication::translate("Camera", "\345\233\276\345\203\217\346\230\276\347\244\272", nullptr));
        btn_recognize->setText(QCoreApplication::translate("Camera", "\350\257\206\345\210\253", nullptr));
        lbl_digit_result->setText(QCoreApplication::translate("Camera", "\350\257\206\345\210\253\347\273\223\346\236\234", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMERA_H
