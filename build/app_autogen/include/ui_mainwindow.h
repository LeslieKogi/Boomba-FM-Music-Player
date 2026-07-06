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
#include <QtGui/QIcon>
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
    QPushButton *playButton;
    QSlider *horizontalSlider;
    QPushButton *openButton;
    QLabel *currentTimeLabel;
    QLabel *totalTimeLabel;
    QLabel *ImageLabel;
    QPushButton *nextButton;
    QPushButton *prevButton;
    QSlider *volumeSlider;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(774, 440);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8("/* The Main Background Gradient (Black, Neon Purple, Neon Blue) */\n"
"QWidget #centralwidget {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1,\n"
"                                stop:0 #000000, \n"
"                                stop:0.6 #25003e, \n"
"                                stop:1 #002b47);\n"
"}\n"
"\n"
"/* Make all text stand out in clean white */\n"
"QLabel {\n"
"    color: #ffffff;\n"
"    font-family: \"Segoe UI\", sans-serif;\n"
"}\n"
"\n"
"/* Style your buttons with Neon Purple borders and Neon Blue text */\n"
"QPushButton {\n"
"    background-color: rgba(255, 255, 255, 0.03);\n"
"    color: #00ffff; /* Electric Neon Blue */\n"
"    border: 1.5px solid #bd00ff; /* Sharp Neon Purple */\n"
"    border-radius: 6px;\n"
"    padding: 6px 12px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"/* Glowing effect when you hover over buttons */\n"
"QPushButton:hover {\n"
"    background-color: rgba(0, 255, 255, 0.08);\n"
"    border: 1.5px solid #00ffff; /* Flips to Neon Blue on hover */\n"
"}\n"
""
                        "\n"
"/* The Music Progress Slider */\n"
"QSlider::groove:horizontal {\n"
"    height: 6px;\n"
"    background: #111122;\n"
"    border-radius: 3px;\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background: #00ffff; /* Neon Blue progress fill */\n"
"    border-radius: 3px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: #bd00ff; /* Neon Purple knob */\n"
"    width: 14px;\n"
"    margin-top: -4px;\n"
"    margin-bottom: -4px;\n"
"    border-radius: 7px;\n"
"}"));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(370, 30, 161, 41));
        searchLineEdit = new QLineEdit(centralwidget);
        searchLineEdit->setObjectName("searchLineEdit");
        searchLineEdit->setGeometry(QRect(10, 360, 191, 31));
        genreComboBox = new QComboBox(centralwidget);
        genreComboBox->addItem(QString());
        genreComboBox->addItem(QString());
        genreComboBox->setObjectName("genreComboBox");
        genreComboBox->setGeometry(QRect(310, 360, 91, 31));
        artistComboBox = new QComboBox(centralwidget);
        artistComboBox->addItem(QString());
        artistComboBox->setObjectName("artistComboBox");
        artistComboBox->setGeometry(QRect(210, 360, 91, 31));
        songListWidget = new QListWidget(centralwidget);
        songListWidget->setObjectName("songListWidget");
        songListWidget->setGeometry(QRect(10, 40, 361, 311));
        songListWidget->setStyleSheet(QString::fromUtf8("background-color: #0b0b12; /* Deep space black */\n"
"color: #ffffff;            /* Crisp white song text */\n"
"border: 1px solid #bd00ff; /* Sharp Neon Purple frame */\n"
"border-radius: 8px;\n"
"padding: 6px;\n"
"\n"
"/* How a song looks when you hover your mouse over it */\n"
"QListWidget::item:hover {\n"
"    background-color: rgba(0, 255, 255, 0.12); /* Subtle neon blue glow */\n"
"    color: #00ffff;                            /* Turns text neon blue */\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"/* How the currently selected/playing song looks */\n"
"QListWidget::item:selected {\n"
"    background-color: #00ffff; /* Bright Neon Blue selection bar */\n"
"    color: #000000;            /* Jet black text so it's clean and readable */\n"
"    font-weight: bold;\n"
"    border-radius: 4px;\n"
"}"));
        playButton = new QPushButton(centralwidget);
        playButton->setObjectName("playButton");
        playButton->setGeometry(QRect(540, 360, 51, 31));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../../../../Downloads/play_button.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        icon.addFile(QString::fromUtf8("../../../../Downloads/pause_button.png"), QSize(), QIcon::Mode::Normal, QIcon::State::On);
        playButton->setIcon(icon);
        playButton->setCheckable(true);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(440, 320, 251, 20));
        horizontalSlider->setOrientation(Qt::Orientation::Horizontal);
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");
        openButton->setGeometry(QRect(10, 10, 81, 26));
        currentTimeLabel = new QLabel(centralwidget);
        currentTimeLabel->setObjectName("currentTimeLabel");
        currentTimeLabel->setGeometry(QRect(420, 340, 49, 16));
        totalTimeLabel = new QLabel(centralwidget);
        totalTimeLabel->setObjectName("totalTimeLabel");
        totalTimeLabel->setGeometry(QRect(680, 340, 41, 16));
        ImageLabel = new QLabel(centralwidget);
        ImageLabel->setObjectName("ImageLabel");
        ImageLabel->setGeometry(QRect(440, 80, 241, 221));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(600, 360, 31, 31));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../../../../Downloads/next_button.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        nextButton->setIcon(icon1);
        prevButton = new QPushButton(centralwidget);
        prevButton->setObjectName("prevButton");
        prevButton->setGeometry(QRect(500, 360, 31, 31));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../../../../Downloads/previous_button.png"), QSize(), QIcon::Mode::Normal, QIcon::State::Off);
        prevButton->setIcon(icon2);
        volumeSlider = new QSlider(centralwidget);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(730, 240, 20, 151));
        volumeSlider->setMaximum(100);
        volumeSlider->setValue(50);
        volumeSlider->setOrientation(Qt::Orientation::Vertical);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 774, 33));
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

        playButton->setText(QString());
        openButton->setText(QCoreApplication::translate("MainWindow", "Open File", nullptr));
        currentTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        totalTimeLabel->setText(QCoreApplication::translate("MainWindow", "00:00", nullptr));
        ImageLabel->setText(QCoreApplication::translate("MainWindow", "Images", nullptr));
        nextButton->setText(QString());
        prevButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
