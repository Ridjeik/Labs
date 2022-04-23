#include "viewwidget.h"
#include <QDebug>

ViewWidget::ViewWidget(QWidget *parent)
    : QWidget{parent}
{}

void ViewWidget::setTriangle(const Triangle &triangle)
{
    this->triangle = triangle;
}

void ViewWidget::setShowSides(const bool state)
{
    this->showSides = state;
    update();
}

void ViewWidget::setShowMedians(const bool state)
{
    this->showMedians = state;
    update();
}

void ViewWidget::setShowVertices(const bool state)
{
    this->showVertices = state;
    update();
}

void ViewWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    double a,b,c;
    double alpha, beta, gamma;

    triangle.getSides(a,b,c);
    triangle.getAngles(alpha, beta, gamma);

    QPointF points[3];
    points[0] = QPointF(0,0);

    if(a >= b && a >= c)
    {
        points[1] = QPointF(a, 0);
        points[2] = QPointF(a - b * cos(gamma), b * sin(gamma));
    }

    else if(b >= c && b >= a)
    {
        points[1] = QPointF(b, 0);
        points[2] = QPointF(b - c * cos(alpha), c * sin(alpha));
    }

    else if(c >= a && c >= b)
    {
        points[1] = QPointF(c, 0);
        points[2] = QPointF(c - a * cos(beta), a * sin(beta));
    }

    double maxWidth = std::max(points[0].x(), std::max(points[1].x(), points[2].x()));
    double maxHeight = std::max(points[0].y(), std::max(points[1].y(), points[2].y()));
    double widthFactor = this->width()/maxWidth;
    double heightFactor = this->height()/maxHeight;

    double factor = widthFactor < heightFactor ? widthFactor : heightFactor;

    points[0] *= factor;
    points[1] *= factor;
    points[2] *= factor;

    points[0].setY(this->height() - 1 - points[0].y());
    points[1].setY(this->height() - 1 - points[1].y());
    points[2].setY(this->height() - 1 - points[2].y());

    QPointF mid01((points[0].x() + points[1].x())/2, (points[0].y() + points[1].y())/2);
    QPointF mid12((points[1].x() + points[2].x())/2, (points[1].y() + points[2].y())/2);
    QPointF mid20((points[2].x() + points[0].x())/2, (points[2].y() + points[0].y())/2);

    if(showSides)
    {
        if(a >= b && a >= c)
        {
            painter.drawText(mid01, "a");
            painter.drawText(mid12, "b");
            painter.drawText(mid20, "c");
        }

        else if(b >= c && b >= a)
        {
            painter.drawText(mid01, "b");
            painter.drawText(mid12, "c");
            painter.drawText(mid20, "a");
        }

        else if(c >= a && c >= b)
        {
            painter.drawText(mid01, "c");
            painter.drawText(mid12, "a");
            painter.drawText(mid20, "b");
        }
    }

    if(showVertices)
    {
        if(a >= b && a >= c)
        {
            painter.drawText(points[0] + QPointF(4, 0), "B");
            painter.drawText(points[1] - QPointF(12, 0), "C");
            painter.drawText(points[2] + QPointF(6, 10), "A");
        }

        else if(b >= c && b >= a)
        {
            painter.drawText(points[0] + QPointF(4, 0), "C");
            painter.drawText(points[1] - QPointF(12, 0), "A");
            painter.drawText(points[2] + QPointF(6, 10), "B");
        }

        else if(c >= a && c >= b)
        {
            painter.drawText(points[0] + QPointF(4, 0), "A");
            painter.drawText(points[1] - QPointF(12, 0), "B");
            painter.drawText(points[2] + QPointF(6, 10), "C");
        }
    }

    qDebug() << points[0] << points[1] << points[2];


    painter.setPen(Qt::red);
    painter.drawPolygon(points, 3);
    if(showMedians)
    {
        painter.drawLine(points[0], mid12);
        painter.drawLine(points[1], mid20);
        painter.drawLine(points[2], mid01);
    }
}
