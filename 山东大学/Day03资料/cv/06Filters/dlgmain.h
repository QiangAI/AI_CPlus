/********************************************************************************
** Form generated from reading UI file 'dlgmain.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef DLGMAIN_H
#define DLGMAIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_dlg_opencv
{
public:
    QFrame *frm_image;
    QLabel *lbl_output;
    QPushButton *btn_blur;
    QPushButton *btn_2d;
    QPushButton *btn_gauss;
    QPushButton *btn_box;
    QPushButton *btn_median;
    QPushButton *btn_laplace;
    QPushButton *btn_sobel;
    QPushButton *btn_bilater;
    QPushButton *btn_dilate;
    QPushButton *btn_erode;
    QPushButton *btn_down;
    QPushButton *btn_up;
    QPushButton *btn_mean;
    QPushButton *btn_scharr;
    QPushButton *btn_sepfilter;
    QPushButton *btn_sqrbox;
    QPushButton *btn_pyramid;
    QPushButton *btn_morph;

    void setupUi(QDialog *dlg_opencv)
    {
        if (dlg_opencv->objectName().isEmpty())
            dlg_opencv->setObjectName(QString::fromUtf8("dlg_opencv"));
        dlg_opencv->resize(391, 488);
        dlg_opencv->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	border:1px solid #AAAAAA;\n"
"	border-radius:6px;\n"
"	padding:2px 4px;\n"
"}\n"
"\n"
"QLabel{\n"
"	border:1px solid #0000FF;\n"
"	border-radius:6px;\n"
"	padding:4px 4px;\n"
"}"));
        frm_image = new QFrame(dlg_opencv);
        frm_image->setObjectName(QString::fromUtf8("frm_image"));
        frm_image->setGeometry(QRect(10, 10, 371, 211));
        frm_image->setFrameShape(QFrame::Panel);
        frm_image->setFrameShadow(QFrame::Raised);
        lbl_output = new QLabel(frm_image);
        lbl_output->setObjectName(QString::fromUtf8("lbl_output"));
        lbl_output->setGeometry(QRect(10, 10, 351, 191));
        lbl_output->setStyleSheet(QString::fromUtf8(""));
        lbl_output->setAlignment(Qt::AlignCenter);
        btn_blur = new QPushButton(dlg_opencv);
        btn_blur->setObjectName(QString::fromUtf8("btn_blur"));
        btn_blur->setGeometry(QRect(20, 240, 80, 30));
        btn_blur->setStyleSheet(QString::fromUtf8(""));
        btn_blur->setFlat(false);
        btn_2d = new QPushButton(dlg_opencv);
        btn_2d->setObjectName(QString::fromUtf8("btn_2d"));
        btn_2d->setGeometry(QRect(290, 240, 80, 30));
        btn_gauss = new QPushButton(dlg_opencv);
        btn_gauss->setObjectName(QString::fromUtf8("btn_gauss"));
        btn_gauss->setGeometry(QRect(110, 240, 80, 30));
        btn_box = new QPushButton(dlg_opencv);
        btn_box->setObjectName(QString::fromUtf8("btn_box"));
        btn_box->setGeometry(QRect(110, 291, 80, 30));
        btn_median = new QPushButton(dlg_opencv);
        btn_median->setObjectName(QString::fromUtf8("btn_median"));
        btn_median->setGeometry(QRect(200, 240, 80, 30));
        btn_laplace = new QPushButton(dlg_opencv);
        btn_laplace->setObjectName(QString::fromUtf8("btn_laplace"));
        btn_laplace->setGeometry(QRect(200, 290, 80, 30));
        btn_sobel = new QPushButton(dlg_opencv);
        btn_sobel->setObjectName(QString::fromUtf8("btn_sobel"));
        btn_sobel->setGeometry(QRect(290, 290, 80, 30));
        btn_bilater = new QPushButton(dlg_opencv);
        btn_bilater->setObjectName(QString::fromUtf8("btn_bilater"));
        btn_bilater->setGeometry(QRect(20, 290, 80, 30));
        btn_dilate = new QPushButton(dlg_opencv);
        btn_dilate->setObjectName(QString::fromUtf8("btn_dilate"));
        btn_dilate->setGeometry(QRect(20, 340, 80, 30));
        btn_erode = new QPushButton(dlg_opencv);
        btn_erode->setObjectName(QString::fromUtf8("btn_erode"));
        btn_erode->setGeometry(QRect(110, 340, 80, 30));
        btn_down = new QPushButton(dlg_opencv);
        btn_down->setObjectName(QString::fromUtf8("btn_down"));
        btn_down->setGeometry(QRect(200, 340, 80, 30));
        btn_up = new QPushButton(dlg_opencv);
        btn_up->setObjectName(QString::fromUtf8("btn_up"));
        btn_up->setGeometry(QRect(290, 340, 80, 30));
        btn_mean = new QPushButton(dlg_opencv);
        btn_mean->setObjectName(QString::fromUtf8("btn_mean"));
        btn_mean->setGeometry(QRect(20, 390, 80, 30));
        btn_scharr = new QPushButton(dlg_opencv);
        btn_scharr->setObjectName(QString::fromUtf8("btn_scharr"));
        btn_scharr->setGeometry(QRect(110, 390, 80, 30));
        btn_sepfilter = new QPushButton(dlg_opencv);
        btn_sepfilter->setObjectName(QString::fromUtf8("btn_sepfilter"));
        btn_sepfilter->setGeometry(QRect(200, 390, 80, 30));
        btn_sqrbox = new QPushButton(dlg_opencv);
        btn_sqrbox->setObjectName(QString::fromUtf8("btn_sqrbox"));
        btn_sqrbox->setGeometry(QRect(290, 390, 80, 30));
        btn_pyramid = new QPushButton(dlg_opencv);
        btn_pyramid->setObjectName(QString::fromUtf8("btn_pyramid"));
        btn_pyramid->setGeometry(QRect(70, 440, 80, 30));
        btn_morph = new QPushButton(dlg_opencv);
        btn_morph->setObjectName(QString::fromUtf8("btn_morph"));
        btn_morph->setGeometry(QRect(250, 440, 80, 30));

        retranslateUi(dlg_opencv);
        QObject::connect(btn_blur, SIGNAL(clicked()), dlg_opencv, SLOT(blur()));
        QObject::connect(btn_bilater, SIGNAL(clicked()), dlg_opencv, SLOT(bilater()));
        QObject::connect(btn_gauss, SIGNAL(clicked()), dlg_opencv, SLOT(gauss()));
        QObject::connect(btn_box, SIGNAL(clicked()), dlg_opencv, SLOT(box()));
        QObject::connect(btn_2d, SIGNAL(clicked()), dlg_opencv, SLOT(fliter2d()));
        QObject::connect(btn_sobel, SIGNAL(clicked()), dlg_opencv, SLOT(sobel()));
        QObject::connect(btn_median, SIGNAL(clicked()), dlg_opencv, SLOT(median()));
        QObject::connect(btn_laplace, SIGNAL(clicked()), dlg_opencv, SLOT(laplace()));
        QObject::connect(btn_dilate, SIGNAL(clicked()), dlg_opencv, SLOT(dilate()));
        QObject::connect(btn_erode, SIGNAL(clicked()), dlg_opencv, SLOT(erode()));
        QObject::connect(btn_down, SIGNAL(clicked()), dlg_opencv, SLOT(down()));
        QObject::connect(btn_up, SIGNAL(clicked()), dlg_opencv, SLOT(up()));
        QObject::connect(btn_mean, SIGNAL(clicked()), dlg_opencv, SLOT(mean()));
        QObject::connect(btn_scharr, SIGNAL(clicked()), dlg_opencv, SLOT(scharr()));
        QObject::connect(btn_sepfilter, SIGNAL(clicked()), dlg_opencv, SLOT(sepfilter()));
        QObject::connect(btn_sqrbox, SIGNAL(clicked()), dlg_opencv, SLOT(sqrbox()));
        QObject::connect(btn_pyramid, SIGNAL(clicked()), dlg_opencv, SLOT(pyramid()));
        QObject::connect(btn_morph, SIGNAL(clicked()), dlg_opencv, SLOT(morph()));

        QMetaObject::connectSlotsByName(dlg_opencv);
    } // setupUi

    void retranslateUi(QDialog *dlg_opencv)
    {
        dlg_opencv->setWindowTitle(QApplication::translate("dlg_opencv", "OpenCV\344\271\213\345\233\276\345\203\217\346\273\244\346\263\242", nullptr));
        lbl_output->setText(QApplication::translate("dlg_opencv", "\345\233\276\345\203\217\350\276\223\345\207\272\345\214\272\345\237\237", nullptr));
        btn_blur->setText(QApplication::translate("dlg_opencv", "Blur", nullptr));
        btn_2d->setText(QApplication::translate("dlg_opencv", "Filter2D", nullptr));
        btn_gauss->setText(QApplication::translate("dlg_opencv", "Gauss", nullptr));
        btn_box->setText(QApplication::translate("dlg_opencv", "Box", nullptr));
        btn_median->setText(QApplication::translate("dlg_opencv", "Median", nullptr));
        btn_laplace->setText(QApplication::translate("dlg_opencv", "Laplace", nullptr));
        btn_sobel->setText(QApplication::translate("dlg_opencv", "Sobel", nullptr));
        btn_bilater->setText(QApplication::translate("dlg_opencv", "Bilateral", nullptr));
        btn_dilate->setText(QApplication::translate("dlg_opencv", "dilate", nullptr));
        btn_erode->setText(QApplication::translate("dlg_opencv", "erode", nullptr));
        btn_down->setText(QApplication::translate("dlg_opencv", "pyrDown ", nullptr));
        btn_up->setText(QApplication::translate("dlg_opencv", "pyrUP", nullptr));
        btn_mean->setText(QApplication::translate("dlg_opencv", "pyrMean", nullptr));
        btn_scharr->setText(QApplication::translate("dlg_opencv", "Scharr", nullptr));
        btn_sepfilter->setText(QApplication::translate("dlg_opencv", "sepFilter", nullptr));
        btn_sqrbox->setText(QApplication::translate("dlg_opencv", "sqrBox", nullptr));
        btn_pyramid->setText(QApplication::translate("dlg_opencv", "\351\253\230\346\226\257\351\207\221\345\255\227\345\241\224", nullptr));
        btn_morph->setText(QApplication::translate("dlg_opencv", "\345\275\242\346\200\201\345\217\230\346\215\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dlg_opencv: public Ui_dlg_opencv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // DLGMAIN_H
