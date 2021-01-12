/********************************************************************************
** Form generated from reading UI file 'camera.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef CAMERA_H
#define CAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Camera
{
public:
    QLabel *lbl_video;

    void setupUi(QDialog *Camera)
    {
        if (Camera->objectName().isEmpty())
            Camera->setObjectName(QString::fromUtf8("Camera"));
        Camera->resize(857, 445);
        lbl_video = new QLabel(Camera);
        lbl_video->setObjectName(QString::fromUtf8("lbl_video"));
        lbl_video->setGeometry(QRect(60, 70, 721, 331));
        lbl_video->setAlignment(Qt::AlignCenter);

        retranslateUi(Camera);

        QMetaObject::connectSlotsByName(Camera);
    } // setupUi

    void retranslateUi(QDialog *Camera)
    {
        Camera->setWindowTitle(QCoreApplication::translate("Camera", "\346\211\213\345\206\231\346\225\260\345\255\227\350\257\206\345\210\253", nullptr));
        lbl_video->setText(QCoreApplication::translate("Camera", "\350\257\206\345\210\253\346\230\276\347\244\272\345\214\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Camera: public Ui_Camera {};
} // namespace Ui

QT_END_NAMESPACE

#endif // CAMERA_H
