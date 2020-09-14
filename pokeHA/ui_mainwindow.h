/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QTextBrowser *turn;
    QTextBrowser *past;
    QTextBrowser *others;
    QLabel *tonghuashun;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1179, 705);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(350, 180, 461, 211));
        turn = new QTextBrowser(widget);
        turn->setObjectName(QStringLiteral("turn"));
        turn->setGeometry(QRect(0, 10, 461, 61));
        turn->setStyleSheet(QString::fromUtf8("QTextBrowser{border-image:url(:/\345\205\266\344\273\226\345\233\276\347\211\207/SOURSES/01.jpg);}\n"
"QTextBrowser{border-color:rgb(0, 0, 0);}\n"
"QTextBrowser{font-size:25px}"));
        past = new QTextBrowser(widget);
        past->setObjectName(QStringLiteral("past"));
        past->setGeometry(QRect(0, 70, 461, 61));
        past->setStyleSheet(QString::fromUtf8("QTextBrowser{border-image:url(:/\345\205\266\344\273\226\345\233\276\347\211\207/SOURSES/01.jpg);}\n"
"QTextBrowser{font-size:25px}"));
        others = new QTextBrowser(widget);
        others->setObjectName(QStringLiteral("others"));
        others->setGeometry(QRect(0, 130, 461, 61));
        others->setStyleSheet(QString::fromUtf8("QTextBrowser{border-image:url(:/\345\205\266\344\273\226\345\233\276\347\211\207/SOURSES/01.jpg);}\n"
"QTextBrowser{font-size:25px}"));
        tonghuashun = new QLabel(widget);
        tonghuashun->setObjectName(QStringLiteral("tonghuashun"));
        tonghuashun->setGeometry(QRect(330, 65, 131, 41));
        tonghuashun->setStyleSheet(QStringLiteral("QLabel{font-size:25px}"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(230, 245, 131, 41));
        label->setStyleSheet(QStringLiteral("QLabel{font-size:25px}"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(230, 185, 131, 41));
        label_2->setStyleSheet(QStringLiteral("QLabel{font-size:25px}"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(230, 305, 131, 41));
        label_3->setStyleSheet(QStringLiteral("QLabel{font-size:25px}"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(170, 20, 72, 41));
        label_4->setStyleSheet(QStringLiteral("QLabel{font-size:20px}"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(0, 50, 31, 101));
        label_5->setStyleSheet(QStringLiteral("QLabel{font-size:20px}"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(1160, 40, 31, 91));
        label_6->setStyleSheet(QStringLiteral("QLabel{font-size:20px}"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(171, 494, 71, 31));
        label_7->setStyleSheet(QStringLiteral("QLabel{font-size:20px}"));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        tonghuashun->setText(QString());
        label->setText(QApplication::translate("MainWindow", "\344\270\212\345\256\266\345\207\272\347\211\214\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\350\275\256\345\210\260\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\346\217\220\347\244\272\344\277\241\346\201\257\357\274\232", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\347\216\251\345\256\2661", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\347\216\251\n"
"\345\256\266\n"
"2", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\347\216\251\n"
"\345\256\266\n"
"4", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\347\216\251\345\256\2663", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
