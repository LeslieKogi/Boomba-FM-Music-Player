#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->songListWidget->addItem("Fine By Myself");
    ui->songListWidget->addItem("Poison");
    ui->songListWidget->addItem("Easily");
    ui->songListWidget->addItem("Fancy");
    ui->songListWidget->addItem("Love on the brain");
    ui->songListWidget->addItem("Hair");
}

MainWindow::~MainWindow()
{
    delete ui;
}
