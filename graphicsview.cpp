#include "graphicsview.h"

void GraphicsView::clear()
{
    points.clear();
    max_x = 1;
    max_y = 1;
    min_x = 1;
    min_y = 1;
}

void GraphicsView::paintPointSlot(QString name, QPointF pos)
{
    pos.setY(pos.y() * -1);

    auto iter = points.find(name);

    if(iter != points.end())
        iter->second.push_back(pos);
    else
    {
        QVector<QPointF> temp;
        temp.push_back(pos);
        points.emplace(name, temp);
    }

//    auto abs_y = qAbs(pos.y());

    if(pos.x() > max_x)
        max_x = pos.x() + 10000;
    if(pos.y() > max_y)
        max_y = pos.y();// + 2500;
    if(pos.x() < min_x && pos.x() != 0)
        min_x = pos.x();// + 10000;
    if(pos.y() < min_y && pos.y() != 0)
        min_y = pos.y();// + 2500;

    this->repaint();
}

void GraphicsView::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event)
    QPainter qp(this);
    testDraw(&qp);
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

    for(const auto& [key, value] : points)
    {
        auto tempPts = value;
        for(auto&& pt : tempPts)
        {
            pt.setX( (pt.x() - min_x) / (max_x - min_x) * width);
            pt.setY( (pt.y() - min_y) / (max_y - min_y) * height / 2 + height / 2);
        }

        if(key == "Missile")
            pen.setColor(Qt::red);
        else
            pen.setColor(Qt::blue);
        qp->setPen(pen);
        qp->drawLines(tempPts);

        if(!tempPts.isEmpty())
        {
            pen.setColor(Qt::black);
            qp->setPen(pen);
            qp->drawText(tempPts.at(0), key);
        }
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
