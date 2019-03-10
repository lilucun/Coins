#ifndef CHOOSELEVELSENCE_H
#define CHOOSELEVELSENCE_H

#include <QWidget>
#include"playsence.h"

class chooseLevelSence : public QWidget
{
    Q_OBJECT
public:
    //声明游戏关卡
    PlaySence *playLevel = NULL;
    explicit chooseLevelSence(QWidget *parent = nullptr);

    //创建 游戏场景
    void creatTwentyLevel(int easyLevel);
    //难度
    static int chooseMode;
    //绘图事件
    void paintEvent(QPaintEvent *);


signals:
    void showStartWindow();


public slots:

};

#endif // CHOOSELEVELSENCE_H
