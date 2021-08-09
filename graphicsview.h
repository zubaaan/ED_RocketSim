#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QPainter>

class GraphicsView : public QWidget
{
    Q_OBJECT
public:
    GraphicsView() {}

    void clear();

public slots:
    void paintPointSlot(QString name, QPointF pos);

private:
    void paintEvent(QPaintEvent *event);

    void testDraw(QPainter *qp);

    std::map<QString, QVector<QPointF>> points;

    double max_x = 1;
    double min_x = 1;
    double max_y = 1;
    double min_y = 1;
};

#endif // GRAPHICSVIEW_H
