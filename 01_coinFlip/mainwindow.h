#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"mybutton.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


    //开始按钮设置
    MyButton *startbutton;
    //选择难度
    MyButton *chooseEasyDiff;
    //游戏介绍
    MyButton *gameInfo;
    //画图事件
    void paintEvent(QPaintEvent *);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
