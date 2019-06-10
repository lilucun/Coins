#include <QDebug>
#include <QMouseEvent>
#include <QSound>
#include "coin.h"

bool Coin::coinIsWin  = false;

Coin::Coin(QWidget *parent) : QPushButton(parent)
{

}
Coin::~Coin()
{

}

Coin::Coin(QString path)
{
    setImage(path);

    timer2 = new QTimer;
    timer1 = new QTimer;

    connect(timer1,&QTimer::timeout,[=](){
        //切换图片
        setImage(QString(":/res/Coin000%1.png").arg(++min));
        //定时器停止
        if(min >= 8)
        {
            min = 1;
            timer1->stop();
        }

    });

    connect(timer2,&QTimer::timeout,[=](){

        setImage(QString(":/res/Coin000%1.png").arg(--max));

        if(max <= 1)
        {
            max = 8;
            timer2->stop();
        }

    });

}



void Coin::changFlag()
{
    QSound *coinSound = new QSound(":/res/ConFlipSound.wav",this);
    coinSound->play();

    if(flag == true)
    {
        //翻为银币
        flag = false;
        //开始定时
        timer1->start(50);
    }
    else
    {
        //翻为金币
        flag = true;
        timer2->start(50);
    }

}


// 加载图片
void Coin::setImage(QString path)
{
    QPixmap pix;
    bool flag = pix.load(path);
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
    this->setStyleSheet("QPushButton{border:0px;}");
}

