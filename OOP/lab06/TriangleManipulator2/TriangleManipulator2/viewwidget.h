#ifndef VIEWWIDGET_H
#define VIEWWIDGET_H

#include <QPainter>
#include <QWidget>
#include "triangle.h"

class ViewWidget : public QWidget
{
    Q_OBJECT

    Triangle triangle;
    bool showSides = false;
    bool showMedians = false;
    bool showVertices = false;

public:
    explicit ViewWidget(QWidget *parent = nullptr);

    void setTriangle(const Triangle& triangle);
    void setShowSides(const bool state);
    void setShowMedians(const bool state);
    void setShowVertices(const bool state);

    void paintEvent(QPaintEvent *event) override;
};

#endif // VIEWWIDGET_H
