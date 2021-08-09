#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>

#include "graphicsview.h"
#include "engine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void stopEngine();

private slots:
    void on_pB_start_clicked();

    void on_pB_stop_clicked();

private:
    Ui::MainWindow *ui;
    GraphicsView *graphicsView;
    Engine *engine;
    QThread *thread;
};
#endif // MAINWINDOW_H
