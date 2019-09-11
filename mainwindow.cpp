#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    for(int i=0;i<70;i++)
    {
        hairs.push_back(hair());
    }
    orihairs=hairs;
    force.x=0;
    force.y=0;

    ui->setupUi(this);
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpDate()));
    timer->start(40);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    QPen mypen;
//       mypen.setWidth(3);                     // 1 表示点的大小（形状为方形）
//       mypen.setColor(Qt::black);
//       painter.setPen(mypen);
//    if(points.size()>=1)
//    {
//        sizetype size = points.size();
//        for(sizetype i=0;i<size;i++)
//        {
//            painter.drawPoint(points[i].x,points[i].y);
//        }
//    }

    mypen.setColor(Qt::black);
    painter.setPen(mypen);
    sizetype size = hairs.size();
    if(size >= 1)
    {
        for(sizetype i=0;i<size;i++)
        {
            points = hairs[i].hpar;
            for(sizetype j=0;j<points.size()-1;j++)
            {
                painter.drawLine(points[j].x, points[j].y, points[j+1].x, points[j+1].y);
            }
        }
    }
}



void MainWindow::on_pushButton_clicked()
{
    ifplay=true;
    update();
}

void MainWindow::timerUpDate()
{
    if(ifplay)
    {
        time += 1;

        force.x=5+8.0*sin(1.0*time/20*PI);
        //force.y+=2.0*sin(1.0*time/20*PI);

        //force.x++;
        points.clear();
        for(sizetype i=0;i<hairs.size();i++)
        {
            hairs[i].next(force,orihairs[i]);
        }
    }
    update();
}
