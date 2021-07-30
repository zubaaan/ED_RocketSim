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
    GraphicsView();

    void addPoint(QPointF point);
    void clear();

private:
    QGraphicsScene      *scene;
    QGraphicsItemGroup  *group_ranges;

    void paintEvent(QPaintEvent *event);
    void resizeEvent(QResizeEvent *event);

    void testDraw(QPainter *qp);

    QVector<QPointF> points;
};

#endif // GRAPHICSVIEW_H
