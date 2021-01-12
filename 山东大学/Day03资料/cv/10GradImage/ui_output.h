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
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_grad
{
public:
    QLabel *lbl_org;
    QLabel *lbl_grad;
    QPushButton *btn_grad;
    QGroupBox *grp_type;
    QRadioButton *rdb_sobel;
    QRadioButton *rdb_prewitt;
    QRadioButton *rdb_diff;
    QRadioButton *rdb_roberts;
    QGroupBox *grp_direction;
    QRadioButton *rdb_l2;
    QRadioButton *rdb_l1;
    QRadioButton *rdb_x;
    QRadioButton *rdb_y;
    QButtonGroup *btg_type;
    QButtonGroup *btg_direction;

    void setupUi(QDialog *dlg_grad)
    {
        if (dlg_grad->objectName().isEmpty())
            dlg_grad->setObjectName(QString::fromUtf8("dlg_grad"));
        dlg_grad->resize(718, 343);
        dlg_grad->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #AAAAAA;\n"
"	border-radius:10px;\n"
"	padding:2px 4px;\n"
"}\n"
"QLabel{\n"
"	border:1px solid #BBBBBB;\n"
"	border-radius:6px;\n"
"	padding:4px 4px;\n"
"}\n"
"QPushButton:hover{\n"
"	background-color: #888888;\n"
"}\n"
""));
        lbl_org = new QLabel(dlg_grad);
        lbl_org->setObjectName(QString::fromUtf8("lbl_org"));
        lbl_org->setGeometry(QRect(10, 120, 288, 216));
        lbl_org->setFrameShape(QFrame::StyledPanel);
        lbl_org->setAlignment(Qt::AlignCenter);
        lbl_grad = new QLabel(dlg_grad);
        lbl_grad->setObjectName(QString::fromUtf8("lbl_grad"));
        lbl_grad->setGeometry(QRect(422, 120, 288, 216));
        lbl_grad->setFrameShape(QFrame::StyledPanel);
        lbl_grad->setAlignment(Qt::AlignCenter);
        btn_grad = new QPushButton(dlg_grad);
        btn_grad->setObjectName(QString::fromUtf8("btn_grad"));
        btn_grad->setGeometry(QRect(310, 210, 101, 31));
        grp_type = new QGroupBox(dlg_grad);
        grp_type->setObjectName(QString::fromUtf8("grp_type"));
        grp_type->setGeometry(QRect(9, 9, 291, 101));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        grp_type->setFont(font);
        rdb_sobel = new QRadioButton(grp_type);
        btg_type = new QButtonGroup(dlg_grad);
        btg_type->setObjectName(QString::fromUtf8("btg_type"));
        btg_type->addButton(rdb_sobel);
        rdb_sobel->setObjectName(QString::fromUtf8("rdb_sobel"));
        rdb_sobel->setGeometry(QRect(160, 70, 97, 20));
        rdb_prewitt = new QRadioButton(grp_type);
        btg_type->addButton(rdb_prewitt);
        rdb_prewitt->setObjectName(QString::fromUtf8("rdb_prewitt"));
        rdb_prewitt->setGeometry(QRect(160, 40, 97, 20));
        rdb_diff = new QRadioButton(grp_type);
        btg_type->addButton(rdb_diff);
        rdb_diff->setObjectName(QString::fromUtf8("rdb_diff"));
        rdb_diff->setGeometry(QRect(40, 40, 97, 20));
        rdb_diff->setChecked(true);
        rdb_roberts = new QRadioButton(grp_type);
        btg_type->addButton(rdb_roberts);
        rdb_roberts->setObjectName(QString::fromUtf8("rdb_roberts"));
        rdb_roberts->setGeometry(QRect(40, 70, 97, 20));
        grp_direction = new QGroupBox(dlg_grad);
        grp_direction->setObjectName(QString::fromUtf8("grp_direction"));
        grp_direction->setGeometry(QRect(420, 9, 291, 101));
        grp_direction->setFont(font);
        rdb_l2 = new QRadioButton(grp_direction);
        btg_direction = new QButtonGroup(dlg_grad);
        btg_direction->setObjectName(QString::fromUtf8("btg_direction"));
        btg_direction->addButton(rdb_l2);
        rdb_l2->setObjectName(QString::fromUtf8("rdb_l2"));
        rdb_l2->setGeometry(QRect(180, 70, 97, 20));
        rdb_l1 = new QRadioButton(grp_direction);
        btg_direction->addButton(rdb_l1);
        rdb_l1->setObjectName(QString::fromUtf8("rdb_l1"));
        rdb_l1->setGeometry(QRect(180, 40, 97, 20));
        rdb_x = new QRadioButton(grp_direction);
        btg_direction->addButton(rdb_x);
        rdb_x->setObjectName(QString::fromUtf8("rdb_x"));
        rdb_x->setGeometry(QRect(50, 40, 97, 20));
        rdb_x->setChecked(true);
        rdb_y = new QRadioButton(grp_direction);
        btg_direction->addButton(rdb_y);
        rdb_y->setObjectName(QString::fromUtf8("rdb_y"));
        rdb_y->setGeometry(QRect(50, 70, 97, 20));

        retranslateUi(dlg_grad);
        QObject::connect(btn_grad, SIGNAL(clicked()), dlg_grad, SLOT(grad()));
        QObject::connect(btg_type, SIGNAL(buttonClicked(int)), dlg_grad, SLOT(type(int)));
        QObject::connect(btg_direction, SIGNAL(buttonClicked(int)), dlg_grad, SLOT(direction(int)));

        QMetaObject::connectSlotsByName(dlg_grad);
    } // setupUi

    void retranslateUi(QDialog *dlg_grad)
    {
        dlg_grad->setWindowTitle(QApplication::translate("dlg_grad", "\345\267\256\345\210\206\347\256\227\345\255\220\347\232\204\345\217\221\345\261\225\345\216\206\345\217\262", nullptr));
        lbl_org->setText(QApplication::translate("dlg_grad", "\345\216\237\345\247\213\345\233\276\345\203\217", nullptr));
        lbl_grad->setText(QApplication::translate("dlg_grad", "\346\242\257\345\272\246\345\233\276\345\203\217", nullptr));
        btn_grad->setText(QApplication::translate("dlg_grad", "\347\256\227\345\255\220", nullptr));
        grp_type->setTitle(QApplication::translate("dlg_grad", "\347\256\227\345\255\220\347\261\273\345\236\213\357\274\232", nullptr));
        rdb_sobel->setText(QApplication::translate("dlg_grad", "Sobel\347\256\227\345\255\220", nullptr));
        rdb_prewitt->setText(QApplication::translate("dlg_grad", "Prewitt\347\256\227\345\255\220", nullptr));
        rdb_diff->setText(QApplication::translate("dlg_grad", "\344\270\200\351\230\266\345\267\256\345\210\206\347\256\227\345\255\220", nullptr));
        rdb_roberts->setText(QApplication::translate("dlg_grad", "Roberts\347\256\227\345\255\220", nullptr));
        grp_direction->setTitle(QApplication::translate("dlg_grad", "\346\250\241\346\235\277\346\226\271\345\220\221\357\274\232", nullptr));
        rdb_l2->setText(QApplication::translate("dlg_grad", "L2-\350\214\203\346\225\260", nullptr));
        rdb_l1->setText(QApplication::translate("dlg_grad", "L1-\350\214\203\346\225\260", nullptr));
        rdb_x->setText(QApplication::translate("dlg_grad", "x-\346\226\271\345\220\221", nullptr));
        rdb_y->setText(QApplication::translate("dlg_grad", "y-\346\226\271\345\220\221", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_grad: public Ui_dlg_grad {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OUTPUT_H
