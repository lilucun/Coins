#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QLabel>
#include <QSound>
#include "chooselevelsence.h"
#include "mybutton.h"
#include "playsence.h"


//难度
int chooseLevelSence::chooseMode = 4;

chooseLevelSence::chooseLevelSence(QWidget *parent) : QWidget(parent)
{
    this->setFixedSize(400,600);
    QMenuBar *menubar = new QMenuBar(this);
    //menubar->setBaseSize(400,20);
    //设置菜单栏显示大小
    menubar->setGeometry(QRect(0, 0, 400, 23));
    QMenu *menu = menubar->addMenu("开始");
    QAction *action = menu->addAction("退出");

    this->setWindowTitle("选择关卡");
    this->setWindowIcon( QIcon (":/res/Coin0001.png"));

    //退出
    connect(action,&QAction::triggered,this,&chooseLevelSence::close);
    //新建返回按钮
    MyButton *backButton = new MyButton(":/res/BackButton.png",":/res/BackButtonSelected.png");

    backButton->setParent(this);
    backButton->move(380 - backButton->width(),580 - backButton->height());

    //待补充:点击鼠标，显示不同的 图片，

    connect(backButton,&MyButton::clicked,[=](){

        QTimer::singleShot(300,[=](){
            //隐藏本窗口 发送显示信号到主窗口

            //返回按钮音效
            QSound *backsound = new QSound(":/res/BackButtonSound.wav",this);
            backsound->play();

            this->hide();
            emit showStartWindow();
        });
    });

}

void chooseLevelSence::creatTwentyLevel(int easyLevel)
{
    //创建关卡图标
    MyButton * playButton[20];
    QLabel * playLabel[20];

    for(int i = 0;i < 20;i++)
    {
        playButton[i] = new MyButton(":/res/LevelIcon.png");
        playButton[i]->setParent(this);

        playButton[i]->move(50 - playButton[i]->width()*0.5 + 100 * (i % 4),150 + (i / 4)* (playButton[i]->height() + 20));
        playLabel[i] = new QLabel(this);
        playLabel[i]->setText(QString("<center><h1>%1</h1></center>").arg(i+1));
        playLabel[i]->resize(playButton[i]->width(),playButton[i]->height());
        playLabel[i]->move(50 - playButton[i]->width()*0.5 + 100 * (i % 4),150 + (i / 4)* (playButton[i]->height() + 20));
        //设置 穿透标签 作用于 标签的 底层：button
        playLabel[i]->setAttribute(Qt::WA_TransparentForMouseEvents);
        playLabel[i]->setStyleSheet(QString("color: rgb(0, 0, 255);font: 15pt 'MV Boli'"));

        //连接 ：关卡按钮按下
        connect(playButton[i],&MyButton::clicked,[=](){

            this->hide();
            if(this->playLevel == NULL)
            {
                // 创建游戏场景
                this->playLevel = new PlaySence(i, easyLevel);
            }
            //设置窗口 显示到当前位置
            this->playLevel->setGeometry(this->geometry());
            this->playLevel->show();

            //检测到 游戏窗口 点击返回按钮
            connect(this->playLevel,&PlaySence::showSecletLevelWindow,[=](){
                //设置显示 到当前窗口位置
                this->setGeometry(this->playLevel->geometry());
                this->show();
                //释放 打开的关卡
                if(this->playLevel != NULL)
                {
                    delete this->playLevel;
                    this->playLevel = NULL;
                }

            });

        });

    }
}



void chooseLevelSence::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    //显示背景图片
    QPixmap pix(":/res/PlayLevelSceneBg.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //显示顶部图片
    pix.load(":/res/Title.png");
    painter.drawPixmap(200 - pix.width()*0.5,40,pix.width(),pix.height(),pix);

}
