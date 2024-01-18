#include "widget.h"
#include "ui_widget.h"
#include <QCursor>
#include <QMouseEvent>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

void Widget::mousePressEvent(QMouseEvent *event)
{
    //如果是鼠标左键按下
    if(event->button() == Qt::LeftButton){
        // offset是QPoint类对象，记录当前点击位置在以窗口左上角为原点的坐标系下的坐标
        offset = event->globalPos() - pos();  // 相当于向量相减，减向量指向被减向量
    }
}

void Widget::mouseReleaseEvent(QMouseEvent *event){

}
void Widget::mouseDoubleClickEvent(QMouseEvent *event){

}
void Widget::mouseMoveEvent(QMouseEvent *event){
    //移动过程中判断鼠标是左键点击并且移动，那么要用buttons，返回的是鼠标状态的集合
    if(event->buttons() & Qt::LeftButton){   // 按位与，当按下的按钮中有左键时为真
        //获取窗口应当移动到的位置
        QPoint windowpos = event->globalPos() - offset;  // 向量相减
        this->move(windowpos);  // 不断调整窗口的位置，从而保持offset的值不变
    }
}
Widget::~Widget()
{
    delete ui;
}
