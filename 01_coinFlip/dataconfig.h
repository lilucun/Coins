#ifndef DATACONFIG_H
#define DATACONFIG_H

#include <QObject>
#include <QMap>
#include <QVector>

class dataConfig : public QObject
{
    Q_OBJECT
public:
    explicit dataConfig(int easyLevel,QObject *parent = 0);


    //金币 每一关的排列数据
    QMap< int, QVector< QVector<int> > > mData;

    //产生 6*6矩阵
    void randData();
    // 初始化
    void initArray();
    // 金币随机翻转1次
    void reverseData();

    int array_level6[6][6];
signals:

public slots:
};

#endif // DATACONFIG_H
