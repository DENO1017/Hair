#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>
#include "hair.h"

#define PI 3.14159265
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *);

    vector<cdn> points;
    vector<hair> hairs;
    vector<hair> orihairs;
    cdn force;

    bool ifplay = false;
    sizetype time = 0;
private slots:
    void on_pushButton_clicked();
    void timerUpDate();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
