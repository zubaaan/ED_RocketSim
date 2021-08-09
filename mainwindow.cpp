#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    delete graphicsView;
}

void MainWindow::on_pB_start_clicked()
{
    ui->pB_start->setEnabled(false);
    graphicsView->clear();

    engine = new Engine();
    engine->init(ui->dSpB_rocketSpeed->value(), ui->dSpB_targetSpeed->value(), ui->dSpB_distance->value(), 0.1);
    connect(engine, &Engine::paintPointSignal, graphicsView, &GraphicsView::paintPointSlot, Qt::BlockingQueuedConnection);

    thread = new QThread(this);
    engine->moveToThread(thread);

    connect(thread, &QThread::started, engine, &Engine::process);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);

    connect(engine, &Engine::finished, [this]()
    {
        thread->quit();
        engine->deleteLater();
        ui->pB_start->setEnabled(true);
    });

    connect(this, &MainWindow::stopEngine, engine, &Engine::stop, Qt::DirectConnection);


    thread->start();
}


void MainWindow::on_pB_stop_clicked()
{
    emit stopEngine();
    ui->pB_start->setEnabled(true);
}

