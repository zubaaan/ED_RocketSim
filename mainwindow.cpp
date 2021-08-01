#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Crafts/target.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    graphicsView = new GraphicsView();
    ui->centralwidget->layout()->addWidget(graphicsView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pB_start_clicked()
{
    graphicsView->clear();

    QPointF pos  {ui->dSpB_distance->value(), 0};
    QPointF velo {- ui->dSpB_targetSpeed->value(), 0};
    double dT = 0.1;
    auto target = new Target(pos, velo, dT);
    for (int var = 0; var < 1500; ++var)
    {
        target->move();
        auto pos = target->getPos();
        pos.setY(pos.y()*-1);

        graphicsView->addPoint(pos);
    }

    graphicsView->repaint();
}

