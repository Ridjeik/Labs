#include "triangle.h"
#include "triangleviewer.h"

int Triangle::createdTriangles = 0;

bool Triangle::isExist(const double sideA, const double sideB, const double sideC)
{
    return (sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA) && (sideA > 0) && (sideB > 0) && (sideC > 0);
}

void Triangle::increaseCreatedTriangles()
{
    Triangle::createdTriangles++;
}

Triangle::Triangle() : sideA(1), sideB(1), sideC(1){increaseCreatedTriangles();}

Triangle::Triangle(const double sideA, const double sideB, const double sideC)
{
    if(isExist(sideA, sideB, sideC))
    {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
    }
    else
    {
        this->sideA = this->sideB = this->sideC = 1;
    }
    increaseCreatedTriangles();
}

Triangle::Triangle(const Triangle &other) : sideA(other.sideA), sideB(other.sideB), sideC(other.sideC){increaseCreatedTriangles();}

void Triangle::increaseSidesBy(const double delta)
{
    if(isExist(sideA + delta, sideB + delta, sideC + delta))
    {
        sideA += delta;
        sideB += delta;
        sideC += delta;
    }
}

void Triangle::increaseSidesBy(const double deltaA, const double deltaB, const double deltaC)
{
    if(isExist(sideA + deltaA, sideB + deltaB, sideC + deltaC))
    {
        sideA += deltaA;
        sideB += deltaB;
        sideC += deltaC;
    }
}

void Triangle::multiplySidesBy(const double scale)
{
    if(scale <= 0) return;
    sideA *= scale;
    sideB *= scale;
    sideC *= scale;
}

void Triangle::setSides(const double sideA, const double sideB, const double sideC)
{
    if(isExist(sideA, sideB, sideC))
    {
        this->sideA = sideA;
        this->sideB = sideB;
        this->sideC = sideC;
    }
}

void Triangle::setSides(const double side)
{
    if(side > 0)
    {
        this->sideA = side;
        this->sideB = side;
        this->sideC = side;
    }
}

void Triangle::getSides(double &sideA, double &sideB, double &sideC) const
{
    sideA = this->sideA;
    sideB = this->sideB;
    sideC = this->sideC;
}

void Triangle::getSides(double &sideA) const
{
    sideA = this->sideA;
}

double Triangle::getArea() const
{
    const double p = (this->sideA + this->sideB + this->sideC)/2;
    return sqrt(p*(p-sideA)*(p-sideB)*(p-sideC));
}

void Triangle::getAngles(double &angleA, double &angleB, double &angleC) const
{
    angleA = acos((sideB * sideB + sideC * sideC - sideA * sideA)/(2*sideB*sideC));
    angleB = acos((sideA * sideA + sideC * sideC - sideB * sideB)/(2*sideA*sideC));
    angleC = acos((sideA * sideA + sideB * sideB - sideC * sideC)/(2*sideA*sideB));
}

double Triangle::getPerimeter() const
{
    return sideA + sideB + sideC;
}

void Triangle::getMedians(double &medianA, double &medianB, double &medianC) const
{
    medianA = sqrt(2*sideB*sideB + 2*sideC*sideC - sideA*sideA)/2;
    medianB = sqrt(2*sideA*sideA + 2*sideC*sideC - sideB*sideB)/2;
    medianC = sqrt(2*sideA*sideA + 2*sideB*sideB - sideC*sideC)/2;
}

bool Triangle::isRectangular() const
{
    const double eps = 1e-6;
    return (fabs(sideA*sideA + sideB*sideB - sideC*sideC) < eps ||
            fabs(sideA*sideA + sideC*sideC - sideB*sideB) < eps ||
            fabs(sideB*sideB + sideC*sideC - sideA*sideA) < eps);
}

void Triangle::applyToForm(TriangleViewer &form)
{
    form.setTriangle(*this);
}

void Triangle::getFromForm(const TriangleViewer &form)
{
    Triangle triangle = form.getTriangle();
    setSides(triangle.sideA, triangle.sideB, triangle.sideC);
}

Triangle Triangle::operator+(const double delta)
{
    Triangle result(*this);
    result.increaseSidesBy(delta);

    return result;
}

Triangle Triangle::operator*(const double scale)
{
    Triangle result(*this);
    result.multiplySidesBy(scale);

    return result;
}

double& Triangle::operator[](const char side)
{
    switch (tolower(side)) {
    case 'a':
        return sideA;
    case 'b':
        return sideB;
    case 'c':
        return sideC;
    default:
        return sideA;
    }
}

Triangle::operator double() const
{
    return this->getPerimeter();
}

int Triangle::getCreatedTriangles()
{
    return createdTriangles;
}

const double &Triangle::operator[](const char side) const
{
    switch (tolower(side)) {
    case 'a':
        return sideA;
    case 'b':
        return sideB;
    case 'c':
        return sideC;
    default:
        return sideA;
    }
}

const TriangleViewer &operator<<(const TriangleViewer& window, Triangle& triangle)
{
    triangle = window.getTriangle();
    return window;
}

TriangleViewer& operator>>(TriangleViewer& window, const Triangle& triangle)
{
    window.setTriangle(triangle);
    return window;
}

bool operator>(const Triangle& a, const Triangle& b)
{
    return a.getPerimeter() > b.getPerimeter();
}

bool operator<(const Triangle& a, const Triangle& b)
{
    return a.getPerimeter() < b.getPerimeter();
}

bool operator==(const Triangle& a, const Triangle& b)
{
    return a.getPerimeter() == b.getPerimeter();
}

