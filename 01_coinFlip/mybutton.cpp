#include <QPixmap>
#include <QDebug>
#include "mybutton.h"

MyButton::MyButton(QWidget *parent) : QToolButton(parent)
{

}
//加载按钮图片：构造函数
MyButton::MyButton(QString firstImage,QString secondImage)
{

    QPixmap pix;
    bool flag = pix.load(firstImage);
    if(!flag)
    {
        qDebug()<<"加载图片失败";
        return ;
    }
    //设置图标
    this->setIcon(pix);
    //设置按钮大小

    this->setFixedSize(pix.width(),pix.height());
    this->setIconSize(QSize (pix.width(),pix.height()));

    //设置边框
    this->setStyleSheet("QToolButton{border:0px;}");
}


void MyButton::zoom()
{
    //创建动画对象
    QPropertyAnimation *animation1 = new QPropertyAnimation(this,"geometry");
    //设置时间间隔，单位毫秒
    animation1->setDuration(200);
    //创建起始位置
    animation1->setStartValue(QRect(this->x(),this->y(),  this->width(),this->height()));
    //创建结束位置
    animation1->setEndValue(QRect(this->x(),this->y() + 10,  this->width(),this->height()) );
    //设置缓和曲线，QEasingCurve::OutBounce 为弹跳效果
    animation1->setEasingCurve(QEasingCurve::OutBounce);
    //开始动画
    animation1->start();

    //跳跃回去
    QPropertyAnimation *animation2 = new QPropertyAnimation(this,"geometry");
    animation2->setDuration(200);
    animation2->setStartValue(QRect(this->x(),this->y()+10,  this->width(),this->height()));
    animation2->setEndValue(QRect(this->x(),this->y(),  this->width(),this->height()) );
    animation2->setEasingCurve(QEasingCurve::OutBounce);
    animation2->start();

}
