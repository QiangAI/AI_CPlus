/********************************************************************************
** Form generated from reading UI file 'laplace.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef LAPLACE_H
#define LAPLACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_laplace
{
public:
    QFrame *frm_output;
    QLabel *lbl_opencv;
    QLabel *lbl_manual;
    QPushButton *btn_laplace;

    void setupUi(QDialog *dlg_laplace)
    {
        if (dlg_laplace->objectName().isEmpty())
            dlg_laplace->setObjectName(QString::fromUtf8("dlg_laplace"));
        dlg_laplace->resize(640, 273);
        frm_output = new QFrame(dlg_laplace);
        frm_output->setObjectName(QString::fromUtf8("frm_output"));
        frm_output->setGeometry(QRect(10, 9, 620, 210));
        frm_output->setFrameShape(QFrame::Panel);
        frm_output->setFrameShadow(QFrame::Raised);
        lbl_opencv = new QLabel(frm_output);
        lbl_opencv->setObjectName(QString::fromUtf8("lbl_opencv"));
        lbl_opencv->setGeometry(QRect(5, 5, 300, 200));
        lbl_opencv->setFrameShape(QFrame::StyledPanel);
        lbl_opencv->setAlignment(Qt::AlignCenter);
        lbl_manual = new QLabel(frm_output);
        lbl_manual->setObjectName(QString::fromUtf8("lbl_manual"));
        lbl_manual->setGeometry(QRect(315, 5, 300, 200));
        lbl_manual->setFrameShape(QFrame::StyledPanel);
        lbl_manual->setAlignment(Qt::AlignCenter);
        btn_laplace = new QPushButton(dlg_laplace);
        btn_laplace->setObjectName(QString::fromUtf8("btn_laplace"));
        btn_laplace->setGeometry(QRect(270, 230, 100, 35));

        retranslateUi(dlg_laplace);
        QObject::connect(btn_laplace, SIGNAL(clicked()), dlg_laplace, SLOT(image_proc()));

        QMetaObject::connectSlotsByName(dlg_laplace);
    } // setupUi

    void retranslateUi(QDialog *dlg_laplace)
    {
        dlg_laplace->setWindowTitle(QApplication::translate("dlg_laplace", "Laplace\344\270\216Sobel\347\256\227\345\255\220", nullptr));
        lbl_opencv->setText(QApplication::translate("dlg_laplace", "OpenCV", nullptr));
        lbl_manual->setText(QApplication::translate("dlg_laplace", "\346\211\213\345\267\245\345\256\236\347\216\260", nullptr));
        btn_laplace->setText(QApplication::translate("dlg_laplace", "Laplace", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_laplace: public Ui_dlg_laplace {};
} // namespace Ui

QT_END_NAMESPACE

#endif // LAPLACE_H
