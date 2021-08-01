#include "graphicsview.h"

void GraphicsView::addPoint(QPointF point)
{
    points.push_back(point);

    auto abs_x = qAbs(point.x());
    auto abs_y = qAbs(point.y());

    if(abs_x > max_x)
        max_x = abs_x + 10000;
    if(abs_y > max_y)
        max_y = abs_y + 2500;
}

void GraphicsView::clear()
{
    points.clear();
    max_x = 1;
    max_y = 1;
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
//    QObject::resizeEvent(event);
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
        pt.setX( pt.x() / max_x * width);
        pt.setY( pt.y() / max_y * height / 2 + height / 2);
//        pt.setY( pt.y() / max_y * height + height/2);
    }
//    qDebug() << tempPts;

    qp->drawLines(tempPts);

    if(!tempPts.isEmpty())
    {
        pen.setColor(Qt::black);
        qp->setPen(pen);
        qp->drawText(tempPts.at(0), "Target");
    }
    // test paint
//    QPen penRed(Qt::red, 4);

//    group_ranges->addToGroup(scene->addSimpleText("test text"));
//    group_ranges->addToGroup(scene->addPath() ???
//    group_ranges->addToGroup(scene->addEllipse(0,0,10,10,penRed));
//    group_ranges->addToGroup(scene->addEllipse(-100,0,20,20,penRed));
//    group_ranges->addToGroup(scene->addEllipse(0,100,30,30,penRed));
//    group_ranges->addToGroup(scene->addEllipse(100,100,40,40,penRed));
}
