#ifndef CHOOSELEVEL_H
#define CHOOSELEVEL_H

#include <QWidget>

namespace Ui {
class ChooseLevel;
}

class ChooseLevel : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseLevel(int posX, int posY, QWidget *parent = 0);

    ~ChooseLevel();
    void initArray();
private:
    Ui::ChooseLevel *ui;

signals:
    void Level6();
    void Level4();

};

#endif // CHOOSELEVEL_H
