#ifndef COIN_H
#define COIN_H

#include <QPushButton>
#include <QTimer>



class Coin : public QPushButton
{
    Q_OBJECT
public:
    explicit Coin(QWidget *parent = nullptr);
    Coin(QString path);
    ~Coin();

    void setImage(QString path);
    //金币 翻银币
    void changFlag();
    //硬币标志
    bool flag;
    //金币标志
    bool errorTranlate = true;
    static bool coinIsWin;

    //定时器
    QTimer *timer1;
    //第2幅图片
    int min = 1;
    QTimer *timer2;
    int max = 8;
signals:

public slots:
};




#endif // COIN_H
