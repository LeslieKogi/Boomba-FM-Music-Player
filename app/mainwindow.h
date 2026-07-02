#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QList>

struct Song {
    QString title;
    QString artist;
    QString genre;
    QString imagePath;
    QString filePath;
    int duration; // Duration in seconds
};

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    Ui::MainWindow *ui;
    QList<Song> musicLibrary; // List to store songs in the music library
};
#endif // MAINWINDOW_H
