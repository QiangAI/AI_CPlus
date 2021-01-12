/********************************************************************************
** Form generated from reading UI file 'ui_output.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OUTPUT_H
#define UI_OUTPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_canny
{
public:
    QLabel *lbl_gray;
    QLabel *lbl_x_grad;
    QLabel *lbl_y_grad;
    QLabel *lbl_canny;
    QPushButton *btn_canny;

    void setupUi(QDialog *dlg_canny)
    {
        if (dlg_canny->objectName().isEmpty())
            dlg_canny->setObjectName(QString::fromUtf8("dlg_canny"));
        dlg_canny->resize(1046, 452);
        dlg_canny->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #AAAAAA;\n"
"	border-radius:10px;\n"
"	padding:2px 4px;\n"
"}\n"
"QLabel{\n"
"	border:1px solid #BBBBBB;\n"
"	border-radius:6px;\n"
"	padding:4px 4px;\n"
"}"));
        lbl_gray = new QLabel(dlg_canny);
        lbl_gray->setObjectName(QString::fromUtf8("lbl_gray"));
        lbl_gray->setGeometry(QRect(10, 120, 288, 216));
        lbl_gray->setFrameShape(QFrame::StyledPanel);
        lbl_gray->setAlignment(Qt::AlignCenter);
        lbl_x_grad = new QLabel(dlg_canny);
        lbl_x_grad->setObjectName(QString::fromUtf8("lbl_x_grad"));
        lbl_x_grad->setGeometry(QRect(450, 10, 288, 216));
        lbl_x_grad->setFrameShape(QFrame::StyledPanel);
        lbl_x_grad->setAlignment(Qt::AlignCenter);
        lbl_y_grad = new QLabel(dlg_canny);
        lbl_y_grad->setObjectName(QString::fromUtf8("lbl_y_grad"));
        lbl_y_grad->setGeometry(QRect(450, 230, 288, 216));
        lbl_y_grad->setFrameShape(QFrame::StyledPanel);
        lbl_y_grad->setAlignment(Qt::AlignCenter);
        lbl_canny = new QLabel(dlg_canny);
        lbl_canny->setObjectName(QString::fromUtf8("lbl_canny"));
        lbl_canny->setGeometry(QRect(750, 120, 288, 216));
        lbl_canny->setFrameShape(QFrame::StyledPanel);
        lbl_canny->setAlignment(Qt::AlignCenter);
        btn_canny = new QPushButton(dlg_canny);
        btn_canny->setObjectName(QString::fromUtf8("btn_canny"));
        btn_canny->setGeometry(QRect(320, 210, 111, 41));

        retranslateUi(dlg_canny);
        QObject::connect(btn_canny, SIGNAL(clicked()), dlg_canny, SLOT(canny()));

        QMetaObject::connectSlotsByName(dlg_canny);
    } // setupUi

    void retranslateUi(QDialog *dlg_canny)
    {
        dlg_canny->setWindowTitle(QApplication::translate("dlg_canny", "Canny\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
        lbl_gray->setText(QApplication::translate("dlg_canny", "\347\201\260\345\272\246\345\233\276", nullptr));
        lbl_x_grad->setText(QApplication::translate("dlg_canny", "x-\346\242\257\345\272\246\347\211\271\345\276\201\345\233\276", nullptr));
        lbl_y_grad->setText(QApplication::translate("dlg_canny", "y-\346\242\257\345\272\246\347\211\271\345\276\201\345\233\276", nullptr));
        lbl_canny->setText(QApplication::translate("dlg_canny", "\350\276\271\347\274\230\347\211\271\345\276\201\345\233\276", nullptr));
        btn_canny->setText(QApplication::translate("dlg_canny", "Canny\350\276\271\347\274\230\346\243\200\346\265\213", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_canny: public Ui_dlg_canny {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
