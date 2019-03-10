#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QToolButton>
#include <QPropertyAnimation>

class MyButton : public QToolButton
{
    Q_OBJECT
public:
    explicit MyButton(QWidget *parent = nullptr);
    //加载按钮图片
    MyButton(QString firstImage,QString secondImage="");
    //按钮动画
    void zoom();
signals:

public slots:
};

#endif // MYBUTTON_H
