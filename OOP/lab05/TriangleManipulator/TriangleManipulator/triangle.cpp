#include "triangle.h"
#include "triangleviewer.h"

bool Triangle::isExist(const double sideA, const double sideB, const double sideC)
{
    return (sideA + sideB > sideC) && (sideA + sideC > sideB) && (sideB + sideC > sideA) && (sideA > 0) && (sideB > 0) && (sideC > 0);
}

Triangle::Triangle() : sideA(1), sideB(1), sideC(1){}

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
}

Triangle::Triangle(const Triangle &other) : sideA(other.sideA), sideB(other.sideB), sideC(other.sideC){}

void Triangle::increaseSidesBy(const double delta)
{
    if(isExist(sideA + delta, sideB + delta, sideC + delta))
    {
        sideA += delta;
        sideB += delta;
        sideC += delta;
    }
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

void Triangle::getSides(double &sideA, double &sideB, double &sideC) const
{
    sideA = this->sideA;
    sideB = this->sideB;
    sideC = this->sideC;
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

