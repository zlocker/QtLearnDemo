﻿#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tab->installEventFilter(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter textPainter(this);
    textPainter.setFont(QFont("Times", 14, QFont::Bold));
    textPainter.drawText(QPoint(20, 30), "Testing");


    QPainter linePainter(this);
    linePainter.drawLine(QPoint(50, 60), QPoint(100, 100));

    QPainter rectPainter(this);
    rectPainter.setBrush(Qt::BDiagPattern);
    rectPainter.drawRect(QRect(40, 120, 80, 30));

    QPen ellipsePen;
    ellipsePen.setColor(Qt::red);
    ellipsePen.setStyle(Qt::DashDotLine);
    QPainter ellipsePainter(this);
    ellipsePainter.setPen(ellipsePen);
    ellipsePainter.drawEllipse(QPoint(80, 200), 50, 20);

    QPainterPath rectPath;
    rectPath.addRect(QRect(150, 20, 100, 50));
    QPainter pathPainter(this);
    pathPainter.setPen(QPen(Qt::red, 1, Qt::DashDotLine, Qt::FlatCap,
    Qt::MiterJoin));
    pathPainter.setBrush(Qt::yellow);
    pathPainter.drawPath(rectPath);

    QPainterPath ellipsePath;
    ellipsePath.addEllipse(QPoint(200, 120), 50, 20);
    QPainter ellipsePathPainter(this);
    ellipsePathPainter.setPen(QPen(QColor(79, 106, 25), 5,
    Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin));
    ellipsePathPainter.setBrush(QColor(122, 163, 39));
    ellipsePathPainter.drawPath(ellipsePath);

    QImage image;
    image.load("tux.png");
    QPainter imagePainter(this);
    imagePainter.drawImage(QPoint(100, 150), image);

}
bool MainWindow::eventFilter(QObject *watched, QEvent *event)
{
    if(watched == ui->tab && event->type() == QEvent::Paint)
    {
        magicTime();
    }
    return QWidget::eventFilter(watched,event);
}

void MainWindow::magicTime()
{
    QPainter textPainter(ui->tab);
    textPainter.setFont(QFont("Times", 14, QFont::Bold));
    textPainter.drawText(QPoint(20, 30), "Testing");
}
