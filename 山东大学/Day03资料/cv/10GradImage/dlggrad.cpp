#include "dlggrad.h"

#include <iostream>
// 构造器与析构器
DlgGrad::DlgGrad(QWidget *parent):
        QDialog(parent),
        dlg(new Ui::dlg_grad),
        proc(new ImageProc()),
        type_id(1), direction_id(1){
    dlg->setupUi(this);
    // 设置分组按钮的id便于管理
    dlg->btg_type->setId(dlg->rdb_diff,1);
    dlg->btg_type->setId(dlg->rdb_roberts,2);
    dlg->btg_type->setId(dlg->rdb_prewitt,3);
    dlg->btg_type->setId(dlg->rdb_sobel,4);

    dlg->btg_direction->setId(dlg->rdb_x, 1);
    dlg->btg_direction->setId(dlg->rdb_y, 2);
    dlg->btg_direction->setId(dlg->rdb_l1, 3);
    dlg->btg_direction->setId(dlg->rdb_l2, 4);
}
DlgGrad::~DlgGrad(){
    delete dlg;
    delete proc;
}
// 显示图像到指定组件 
void DlgGrad::showGrayImage(cv::Mat img, QLabel *container){
    if(img.empty() || ! container ) return;   // 图像与现实容器都非空才处理

    cv::Mat  m_out;
    // OpenCV到Qt的颜色格式转换
    cv::cvtColor(img, m_out, cv::COLOR_GRAY2RGBA); 
    // 转换为Qt图像
    QImage i_out(m_out.data, m_out.cols, m_out.rows, QImage::Format_RGBA8888);
    // 转换为组件能处理的像素格式
    QPixmap p_out = QPixmap::fromImage(i_out);
    // 显示图像
    container->setPixmap(p_out);
    // 缩放图像适应组件大小
    container->setScaledContents(true);
}
// 显示事件
void DlgGrad::showEvent(QShowEvent *event){
    // 原图转换为灰度图像，
    proc->toGray();
    // 显示灰度图像
    showGrayImage(proc->m_gray, dlg->lbl_org);
}

void DlgGrad::type(int id){
    type_id = id;
}
void DlgGrad::direction(int id){
    direction_id = id;
}

void DlgGrad::grad(){
    if(type_id == 1){
        if(direction_id == 1){
            proc->diff_x();
            showGrayImage(proc->m_diff_x, dlg->lbl_grad);
        }
        if(direction_id == 2){
            proc->diff_y();
            showGrayImage(proc->m_diff_y, dlg->lbl_grad);
        }
        if(direction_id == 3){
            proc->diff_1();
            showGrayImage(proc->m_diff_1, dlg->lbl_grad);
        }
        if(direction_id == 4){
            proc->diff_2();
            showGrayImage(proc->m_diff_2, dlg->lbl_grad);
        }
    }
    if(type_id == 2){
        if(direction_id == 1){
            proc->roberts_x();
            showGrayImage(proc->m_roboerts_x, dlg->lbl_grad);
        }
        if(direction_id == 2){
            proc->roberts_y();
            showGrayImage(proc->m_roboerts_y, dlg->lbl_grad);
        }
        if(direction_id == 3){
            proc->roberts_1();
            showGrayImage(proc->m_roboerts_1, dlg->lbl_grad);
        }
        if(direction_id == 4){
            proc->roberts_2();
            showGrayImage(proc->m_roboerts_2, dlg->lbl_grad);
        }        
    }
    if(type_id == 3){
        if(direction_id == 1){
            proc->prewitt_x();
            showGrayImage(proc->m_prewitt_x, dlg->lbl_grad);
        }
        if(direction_id == 2){
            proc->prewitt_y();
            showGrayImage(proc->m_prewitt_y, dlg->lbl_grad);
        }
        if(direction_id == 3){
            proc->prewitt_1();
            showGrayImage(proc->m_prewitt_1, dlg->lbl_grad);
        }
        if(direction_id == 4){
            proc->prewitt_2();
            showGrayImage(proc->m_prewitt_2, dlg->lbl_grad);
        }        
    }
    if(type_id == 4){
        if(direction_id == 1){
            proc->sobel_x();
            showGrayImage(proc->m_sobels_x, dlg->lbl_grad);
        }
        if(direction_id == 2){
            proc->sobel_y();
            showGrayImage(proc->m_sobels_y, dlg->lbl_grad);
        }
        if(direction_id == 3){
            proc->sobel_1();
            showGrayImage(proc->m_sobels_1, dlg->lbl_grad);
        }
        if(direction_id == 4){
            proc->sobel_2();
            showGrayImage(proc->m_sobels_2, dlg->lbl_grad);
        }       
    }
}
