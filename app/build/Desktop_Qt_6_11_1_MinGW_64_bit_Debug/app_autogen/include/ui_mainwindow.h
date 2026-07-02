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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *currentSongLabel;
    QHBoxLayout *seekLayout;
    QLabel *timeLabel;
    QSlider *seekSlider;
    QLabel *durationLabel;
    QHBoxLayout *controlsLayout;
    QPushButton *previousButton;
    QPushButton *playButton;
    QPushButton *pauseButton;
    QPushButton *stopButton;
    QPushButton *nextButton;
    QHBoxLayout *volumeLayout;
    QLabel *volumeTextLabel;
    QSlider *volumeSlider;
    QLabel *volumeLabel;
    QLabel *statusLabel;
    QLabel *playlistLabel;
    QHBoxLayout *playlistButtonLayout;
    QPushButton *addButton;
    QPushButton *removeButton;
    QPushButton *clearButton;
    QLabel *playlistCountLabel;
    QSpacerItem *horizontalSpacer;
    QListWidget *playlistWidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(900, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        currentSongLabel = new QLabel(centralwidget);
        currentSongLabel->setObjectName("currentSongLabel");
        currentSongLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(currentSongLabel);

        seekLayout = new QHBoxLayout();
        seekLayout->setObjectName("seekLayout");
        timeLabel = new QLabel(centralwidget);
        timeLabel->setObjectName("timeLabel");

        seekLayout->addWidget(timeLabel);

        seekSlider = new QSlider(centralwidget);
        seekSlider->setObjectName("seekSlider");
        seekSlider->setOrientation(Qt::Horizontal);

        seekLayout->addWidget(seekSlider);

        durationLabel = new QLabel(centralwidget);
        durationLabel->setObjectName("durationLabel");

        seekLayout->addWidget(durationLabel);


        verticalLayout->addLayout(seekLayout);

        controlsLayout = new QHBoxLayout();
        controlsLayout->setObjectName("controlsLayout");
        previousButton = new QPushButton(centralwidget);
        previousButton->setObjectName("previousButton");
        previousButton->setMinimumHeight(40);

        controlsLayout->addWidget(previousButton);

        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setMinimumHeight(40);

        controlsLayout->addWidget(playButton);

        pauseButton = new QPushButton(centralwidget);
        pauseButton->setObjectName("pauseButton");
        pauseButton->setMinimumHeight(40);

        controlsLayout->addWidget(pauseButton);

        stopButton = new QPushButton(centralwidget);
        stopButton->setObjectName("stopButton");
        stopButton->setMinimumHeight(40);

        controlsLayout->addWidget(stopButton);

        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setMinimumHeight(40);

        controlsLayout->addWidget(nextButton);


        verticalLayout->addLayout(controlsLayout);

        volumeLayout = new QHBoxLayout();
        volumeLayout->setObjectName("volumeLayout");
        volumeTextLabel = new QLabel(centralwidget);
        volumeTextLabel->setObjectName("volumeTextLabel");

        volumeLayout->addWidget(volumeTextLabel);

        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setMinimum(0);
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(100);
        volumeSlider->setOrientation(Qt::Horizontal);

        volumeLayout->addWidget(volumeSlider);

        volumeLabel = new QLabel(centralwidget);
        volumeLabel->setObjectName("volumeLabel");
        volumeLabel->setMinimumWidth(40);

        volumeLayout->addWidget(volumeLabel);


        verticalLayout->addLayout(volumeLayout);

        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName("statusLabel");
        statusLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(statusLabel);

        playlistLabel = new QLabel(centralwidget);
        playlistLabel->setObjectName("playlistLabel");

        verticalLayout->addWidget(playlistLabel);

        playlistButtonLayout = new QHBoxLayout();
        playlistButtonLayout->setObjectName("playlistButtonLayout");
        addButton = new QPushButton(centralwidget);
        addButton->setObjectName("addButton");

        playlistButtonLayout->addWidget(addButton);

        removeButton = new QPushButton(centralwidget);
        removeButton->setObjectName("removeButton");

        playlistButtonLayout->addWidget(removeButton);

        clearButton = new QPushButton(centralwidget);
        clearButton->setObjectName("clearButton");

        playlistButtonLayout->addWidget(clearButton);

        playlistCountLabel = new QLabel(centralwidget);
        playlistCountLabel->setObjectName("playlistCountLabel");

        playlistButtonLayout->addWidget(playlistCountLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        playlistButtonLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(playlistButtonLayout);

        playlistWidget = new QListWidget(centralwidget);
        playlistWidget->setObjectName("playlistWidget");
        playlistWidget->setMinimumHeight(200);

        verticalLayout->addWidget(playlistWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 900, 18));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Music Player", nullptr));
        currentSongLabel->setText(QCoreApplication::translate("MainWindow", "Now Playing: No song", nullptr));
        timeLabel->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        durationLabel->setText(QCoreApplication::translate("MainWindow", "0:00", nullptr));
        previousButton->setText(QCoreApplication::translate("MainWindow", "\342\217\256 Previous", nullptr));
        playButton->setText(QCoreApplication::translate("MainWindow", "\342\226\266 Play", nullptr));
        pauseButton->setText(QCoreApplication::translate("MainWindow", "\342\217\270 Pause", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\342\217\271 Stop", nullptr));
        nextButton->setText(QCoreApplication::translate("MainWindow", "Next \342\217\255", nullptr));
        volumeTextLabel->setText(QCoreApplication::translate("MainWindow", "Volume:", nullptr));
        volumeLabel->setText(QCoreApplication::translate("MainWindow", "100%", nullptr));
        statusLabel->setText(QCoreApplication::translate("MainWindow", "Status: Stopped", nullptr));
        playlistLabel->setText(QCoreApplication::translate("MainWindow", "Playlist", nullptr));
        addButton->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Add Songs", nullptr));
        removeButton->setText(QCoreApplication::translate("MainWindow", "\342\236\226 Remove", nullptr));
        clearButton->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221 Clear", nullptr));
        playlistCountLabel->setText(QCoreApplication::translate("MainWindow", "Songs: 0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
