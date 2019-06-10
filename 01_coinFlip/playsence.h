#ifndef PLAYSENCE_H
#define PLAYSENCE_H


#include "mybutton.h"
#include "dataconfig.h"
#include "coin.h"
#include <QWidget>
#include <QLCDNumber>

class PlaySence : public QWidget
{
    Q_OBJECT
public:
    explicit PlaySence(QWidget *parent = nullptr);
    PlaySence(int level, int easyLevel);

    void paintEvent(QPaintEvent *);
    //
    bool isWin(int easyLevel);

    //
    MyButton * centureButton;
    //金币数组
    Coin *coin[6][6];

    //关卡数据
    dataConfig *myCoinData ;
    //时间s
    static int sec;
    //显示时间
    QLCDNumber *showtime_sec;
    QLCDNumber *showtime_min;
    QTimer *timer;

signals:
    void showSecletLevelWindow();

public slots:
    void onTimeOut();
};

#endif // PLAYSENCE_H
