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

public:
    //金币 每一关的排列数据
    QMap< int, QVector< QVector<int> > > mData;

    //随机 产生 6*6矩阵
    void randData();

signals:

public slots:
};

#endif // DATACONFIG_H
