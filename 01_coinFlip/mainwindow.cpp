#include <QPainter>
#include <QPixmap>
#include <QTimer>
#include <QDebug>
#include <QSound>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chooselevel.h"
#include "chooselevelsence.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);

    this->setFixedSize(400,600);

    this->setWindowTitle("翻金币");
    this->setWindowIcon( QIcon (":/res/Coin0001.png"));

    //退出
    connect(ui->actionquit,&QAction::triggered,this,&MainWindow::close);

    //实时更新 画图事件显示
    this->update();

    //开始按钮设置
    startbutton = new MyButton(":/res/MenuSceneStartButton.png");
    startbutton->setParent(this);


    //添加 游戏介绍 难度选择功能
    gameInfo = new MyButton(this);
    gameInfo->setText(QString("游戏介绍"));
    //gameInfo->setFont(QFont("宋体",25));
    gameInfo->resize(150,50);
    gameInfo->move(200 - 75,180);
    gameInfo->setStyleSheet(QString("color: rgb(0, 152, 255);font: 24pt 'MV Boli';background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                                      "background-color: rgb(0, 0, 139);"
                                      "border-radius:15px"));

    chooseEasyDiff = new MyButton(this);
    chooseEasyDiff->setText(QString("难度选择"));

    chooseEasyDiff->resize(150,50);
    chooseEasyDiff->move(200 - 75,280);
    chooseEasyDiff->setStyleSheet(QString("color: rgb(0, 152, 255);font: 24pt 'MV Boli';background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(255, 255, 255, 255));"
                                      "background-color: rgb(0, 0, 139);"
                                      "border-radius:15px"));
    //难度选择

    ChooseLevel *chooselevel = new ChooseLevel(this->geometry().x(), this->geometry().y());
    connect(chooseEasyDiff,&MyButton::clicked,[=](){

        chooselevel->show();
    });



    startbutton->move(200 - startbutton->width()*0.5,450 - startbutton->height()*0.5);
    //选择关卡窗口设置
    chooseLevelSence *sence = new chooseLevelSence;

    connect(startbutton,&MyButton::clicked,[=](){
        chooseLevelSence::chooseMode = 4;
        // 创建20 个关卡
        sence->creatTwentyLevel(chooseLevelSence::chooseMode);
        //播放按钮音效
        QSound *sound = new QSound(":/res/TapButtonSound.wav",this);
        sound->play();
        //设置移动动画
        startbutton->zoom();
        QTimer::singleShot(500,[=](){
            //隐藏当前窗口 显示选择关卡窗口
            this->hide();
            sence->setGeometry(this->geometry());
            sence->show();
        });
    });



    connect(chooselevel, &ChooseLevel::Level6,[=](){
         chooseLevelSence::chooseMode = 6;
         // 创建20 个关卡
         sence->creatTwentyLevel(chooseLevelSence::chooseMode);
         this->hide();
         sence->setGeometry(this->geometry());
         sence->show();
    });

    connect(chooselevel, &ChooseLevel::Level4,[=](){
         chooseLevelSence::chooseMode = 4;
         // 创建20 个关卡
         sence->creatTwentyLevel(chooseLevelSence::chooseMode);
         this->hide();
         sence->setGeometry(this->geometry());
         sence->show();
    });

    //返回
    connect(sence,&chooseLevelSence::showStartWindow,[=](){
        this->setGeometry(sence->geometry());
        this->show();
    });
}


void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    //画主界面
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    //画图标
    pix.load(":/res/Title.png");
    painter.drawPixmap(30,40,pix.width()*0.6,pix.height()*0.6,pix);

}



MainWindow::~MainWindow()
{
    delete ui;
}
