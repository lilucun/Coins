/********************************************************************************
** Form generated from reading UI file 'chooselevel.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSELEVEL_H
#define UI_CHOOSELEVEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseLevel
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *level4;
    QPushButton *level6;

    void setupUi(QWidget *ChooseLevel)
    {
        if (ChooseLevel->objectName().isEmpty())
            ChooseLevel->setObjectName(QStringLiteral("ChooseLevel"));
        ChooseLevel->resize(136, 130);
        ChooseLevel->setStyleSheet(QStringLiteral("background-color: rgb(85, 255, 255);"));
        verticalLayout = new QVBoxLayout(ChooseLevel);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        level4 = new QPushButton(ChooseLevel);
        level4->setObjectName(QStringLiteral("level4"));
        level4->setMaximumSize(QSize(16777215, 16777215));
        level4->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(245, 224, 176, 255), stop:0.09 rgba(246, 189, 237, 255), stop:0.14 rgba(194, 207, 246, 255), stop:0.19 rgba(184, 160, 168, 255), stop:0.25 rgba(171, 186, 248, 255), stop:0.32 rgba(243, 248, 224, 255), stop:0.385 rgba(249, 162, 183, 255), stop:0.47 rgba(100, 115, 124, 255), stop:0.58 rgba(251, 205, 202, 255), stop:0.65 rgba(170, 128, 185, 255), stop:0.75 rgba(252, 222, 204, 255), stop:0.805 rgba(206, 122, 218, 255), stop:0.86 rgba(254, 223, 175, 255), stop:0.91 rgba(254, 236, 244, 255), stop:1 rgba(255, 191, 221, 255));\n"
"font: 87 15pt \"Arial Black\";\n"
"border-radius:15px;\n"
""));

        verticalLayout->addWidget(level4);

        level6 = new QPushButton(ChooseLevel);
        level6->setObjectName(QStringLiteral("level6"));
        level6->setMaximumSize(QSize(16777213, 16777215));
        level6->setStyleSheet(QLatin1String("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(245, 224, 176, 255), stop:0.09 rgba(246, 189, 237, 255), stop:0.14 rgba(194, 207, 246, 255), stop:0.19 rgba(184, 160, 168, 255), stop:0.25 rgba(171, 186, 248, 255), stop:0.32 rgba(243, 248, 224, 255), stop:0.385 rgba(249, 162, 183, 255), stop:0.47 rgba(100, 115, 124, 255), stop:0.58 rgba(251, 205, 202, 255), stop:0.65 rgba(170, 128, 185, 255), stop:0.75 rgba(252, 222, 204, 255), stop:0.805 rgba(206, 122, 218, 255), stop:0.86 rgba(254, 223, 175, 255), stop:0.91 rgba(254, 236, 244, 255), stop:1 rgba(255, 191, 221, 255));\n"
"font: 87 15pt \"Arial Black\";\n"
"border-radius:15px;"));

        verticalLayout->addWidget(level6);


        retranslateUi(ChooseLevel);

        QMetaObject::connectSlotsByName(ChooseLevel);
    } // setupUi

    void retranslateUi(QWidget *ChooseLevel)
    {
        ChooseLevel->setWindowTitle(QApplication::translate("ChooseLevel", "Form", Q_NULLPTR));
        level4->setText(QApplication::translate("ChooseLevel", "\347\255\211\347\272\2474", Q_NULLPTR));
        level6->setText(QApplication::translate("ChooseLevel", "\347\255\211\347\272\2476", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChooseLevel: public Ui_ChooseLevel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSELEVEL_H
