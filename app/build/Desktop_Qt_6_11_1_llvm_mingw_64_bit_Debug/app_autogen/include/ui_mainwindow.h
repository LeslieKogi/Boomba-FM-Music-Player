/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *searchLineEdit;
    QComboBox *genreComboBox;
    QComboBox *artistComboBox;
    QListWidget *songListWidget;
    QPushButton *pauseButton;
    QPushButton *playButton;
    QSlider *horizontalSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 399);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 10, 161, 41));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(20, 50, 191, 31));
        genreComboBox = new QComboBox(centralwidget);
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->setObjectName("genreComboBox");
        genreComboBox->setGeometry(QRect(20, 100, 81, 22));
        artistComboBox = new QComboBox(centralwidget);
        artistComboBox->addItem(QString());
        artistComboBox->setObjectName("artistComboBox");
        artistComboBox->setGeometry(QRect(120, 100, 81, 22));
        songListWidget = new QListWidget(centralwidget);
        songListWidget->setObjectName("songListWidget");
        songListWidget->setGeometry(QRect(20, 140, 256, 111));
        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setGeometry(QRect(90, 310, 56, 41));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(20, 310, 61, 41));
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(20, 270, 251, 20));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Boomba FM Music Player", nullptr));
        searchLineEdit->setText(QCoreApplication::translate("MainWindow", "Search Title", nullptr));
        genreComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Genre", nullptr));
        genreComboBox->setItemText(1, QString());

        artistComboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Artist", nullptr));

        pauseButton->setText(QCoreApplication::translate("MainWindow", "Pause", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
