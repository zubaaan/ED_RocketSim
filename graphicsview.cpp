#include "graphicsview.h"

GraphicsView::GraphicsView()
{
//    scene = new QGraphicsScene();
//    this->setScene(scene);
//    group_ranges = new QGraphicsItemGroup();
    //    scene->addItem(group_ranges);
}

void GraphicsView::addPoint(QPointF point)
{
    points.push_back(point);
}

void GraphicsView::clear()
{
    points.clear();
}

void GraphicsView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter qp(this);
    testDraw(&qp);
}

void GraphicsView::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
//    QGraphicsView::resizeEvent(event);
}

void GraphicsView::testDraw(QPainter *qp)
{
    int width = this->width();
    int height = this->height();

    QPen pen(Qt::gray, 2, Qt::SolidLine);

    qp->setPen(pen);
    qp->drawLine(0,0,width,0);
    qp->drawLine(width,0,width,height);
    qp->drawLine(width,height,0,height);
    qp->drawLine(0,height,0,0);
    qp->setBrush(QBrush(Qt::white));
    qp->drawRect(0,0,width,height);

    pen.setColor(Qt::blue);
    qp->setPen(pen);

    auto tempPts = points;
    for(auto&& pt : tempPts)
    {
        pt.setX( pt.x() / 100000 * width);
        pt.setY( pt.y() + height/2);
    }
//    qDebug() << tempPts;

    qp->drawLines(tempPts);

    // test paint
//    QPen penRed(Qt::red, 4);

//    group_ranges->addToGroup(scene->addSimpleText("test text"));
//    group_ranges->addToGroup(scene->addPath() ???
//    group_ranges->addToGroup(scene->addEllipse(0,0,10,10,penRed));
//    group_ranges->addToGroup(scene->addEllipse(-100,0,20,20,penRed));
//    group_ranges->addToGroup(scene->addEllipse(0,100,30,30,penRed));
//    group_ranges->addToGroup(scene->addEllipse(100,100,40,40,penRed));
}
