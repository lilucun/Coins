#include <QLabel>
#include <QMenuBar>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QPixmap>
#include <QEvent>
#include <QLabel>
#include <QPropertyAnimation>
#include <QSound>
#include <QLCDNumber>
#include "playsence.h"
#include "coin.h"
#include "chooselevelsence.h"


int PlaySence::sec = 0;

PlaySence::PlaySence(QWidget *parent) : QWidget(parent)
{

}


PlaySence::PlaySence(int level,int easyLevel)
{
    //初始化静态数据
    Coin::coinIsWin = false;
    PlaySence::sec = 0;

    this->setFixedSize(400,600);
    QMenuBar *menubar = new QMenuBar(this);

    //设置菜单栏显示大小
    menubar->setGeometry(QRect(0, 0, 400, 23));
    QMenu *menu = menubar->addMenu("开始");
    QAction *action = menu->addAction("退出");

    this->setWindowTitle("游戏开始");
    this->setWindowIcon( QIcon (":/res/Coin0001.png"));

    //退出
    connect(action,&QAction::triggered,this,&PlaySence::close);


    //显示成功标签
    QLabel *successLabel = new QLabel(this);
    QPixmap pix;
    pix.load(":/res/LevelCompletedDialogBg.png");
    successLabel->setPixmap(pix);
    successLabel->resize(pix.width(),pix.height());
    int wid = successLabel->width();

    successLabel->setGeometry(QRect ((this->width() - wid)/2,-100,successLabel->width(),successLabel->height()));
    successLabel->show();

    QLabel *showLevelLabel = new QLabel(this);

    //设置字体 ：参数 字体 字号 粗体
    showLevelLabel->setFont(QFont ("Helvetica",18,QFont::Bold));

    showLevelLabel->setText(QString("关卡：%1").arg(level+1));
    showLevelLabel->move(40,540);
    showLevelLabel->setStyleSheet(QString("color: rgb(0, 255, 0);font: 18pt 'MV Boli'"));

    // 设置时间
    QLabel * label = new QLabel(this);
    label->setText(QString("当前使用时间："));
    label->setGeometry(40, 75, 130, 30);
    label->setStyleSheet(QString("color:rgb(0, 255, 0);font: 25 14pt 'Calibri Light';"));
    showtime = new QLCDNumber(this);
    showtime->setGeometry(180, 75, 80, 30);

    showtime->setStyleSheet(QString("color:rgb(255, 0, 0);background-color: rgb(255, 255, 127);font: 25 14pt 'Calibri Light';"));
    timer = new QTimer(this);
    timer->start(1000);
    // 超时
    connect(timer, &QTimer::timeout, this, &PlaySence::onTimeOut);
    // 清空计时
    chooseLevelSence *sence = new chooseLevelSence;

    //新建返回按钮
    MyButton *backButton = new MyButton(":/res/BackButton.png",":/res/BackButtonSelected.png");

    backButton->setParent(this);
    backButton->move(380 - backButton->width(),580 - backButton->height());
    //发送 返回信号
    connect(backButton,&MyButton::clicked,[=](){
        //返回按钮音效
        QSound *backsound = new QSound(":/res/BackButtonSound.wav",this);
        backsound->play();

        QTimer::singleShot(300,[=](){
            //隐藏本窗口 发送显示信号到主窗口
            this->hide();
            emit showSecletLevelWindow();
        });
    });

    //设置 游戏布局
    //关卡数据 加载
    myCoinData = new dataConfig(easyLevel);

    // 关卡生成
    for(int i=0;i < easyLevel;i++)
    {
        for(int j=0;j < easyLevel;j++)
        {

            centureButton = new MyButton(":/res/BoardNode.png");
            centureButton->setParent(this);
            centureButton->move(200 - (easyLevel/2 - j)*centureButton->width() , 300 - (easyLevel/2 - i)*centureButton->height() );

            //具体金币场景生成 由 level 确定哪一关
            QString path = ":/res/Coin0001.png";
            if(myCoinData->mData[level+1][i][j] == 0)
            {
                path = ":/res/Coin0008.png";
            }

            coin[i][j] = new Coin(path);
            coin[i][j]->setParent(this);
            coin[i][j]->move(202 - (easyLevel/2 - j)*centureButton->width() , 304 - (easyLevel/2 - i)*centureButton->height() );
            coin[i][j]->flag = myCoinData->mData[level+1][i][j];
            qDebug()<<coin[i][j]->flag;

            connect(coin[i][j],&Coin::clicked,[=](){
                //点击，币反转
                if( coin[i][j]->errorTranlate && !isWin(easyLevel))
                {
                    coin[i][j]->errorTranlate = false;
                    coin[i][j]->changFlag();
                    //四周金币反转
                    //上
                    if(i - 1 >= 0)
                    {
                        coin[i-1][j]->changFlag();
                    }
                    //下
                    if(i + 1 < easyLevel)
                    {
                        coin[i+1][j]->changFlag();
                    }
                    //左
                    if(j - 1 >= 0)
                    {
                        coin[i][j-1]->changFlag();
                    }
                    //右
                    if(j + 1 < easyLevel)
                    {
                        coin[i][j+1]->changFlag();
                    }
                    coin[i][j]->errorTranlate = true;

                }

                //判断是否成功 且把 按钮的静态标志 置true
                if(isWin(easyLevel) && Coin::coinIsWin == false)
                {
                    // 让标签显示在最上层
                    successLabel->raise();
                    //成功标签 动画
                    QPropertyAnimation *animation1 = new QPropertyAnimation(successLabel,"geometry");
                    animation1->setStartValue(QRect(successLabel->x(),successLabel->y(),  successLabel->width(),successLabel->height()));
                    animation1->setEndValue(QRect(successLabel->x(),successLabel->y() + 330,  successLabel->width(),successLabel->height()) );
                    animation1->setEasingCurve(QEasingCurve::OutBounce);
                    animation1->start();
                    //成功标签 动画
                    QPropertyAnimation *animation2 = new QPropertyAnimation(successLabel,"geometry");
                    animation2->setStartValue(QRect(successLabel->x(),successLabel->y() + 330,  successLabel->width(),successLabel->height()));
                    animation2->setEndValue(QRect(successLabel->x(),successLabel->y() + 300,  successLabel->width(),successLabel->height()) );
                    animation2->setEasingCurve(QEasingCurve::OutBounce);
                    animation2->start();
                    //播放胜利音效
                    QSound *sound = new QSound(":/res/LevelWinSound.wav",this);
                    sound->play();

                    Coin::coinIsWin = true;
                    timer->stop();

                }

            });
        }
    }

}


bool  PlaySence::isWin(int easyLevel)
{
    bool isWin = true;
    for(int i=0;i<easyLevel;i++)
    {
        for(int j=0;j<easyLevel;j++)
        {
            if(coin[i][j]->flag == false)
            {
                isWin = false;
                return isWin;
            }
        }
    }
    return isWin;
}





void PlaySence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //显示背景图片
    QPixmap pix(":/res/OtherSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

}

void PlaySence::onTimeOut()
{
    //显示用时
    showtime->display(++sec);
}
