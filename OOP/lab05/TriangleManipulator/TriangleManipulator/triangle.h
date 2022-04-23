#ifndef TRIANGLE_H
#define TRIANGLE_H

class TriangleViewer;

class Triangle
{
    double sideA, sideB, sideC;

    bool isExist(const double sideA, const double sideB, const double sideC);

public:
    Triangle();
    Triangle(const double sideA, const double sideB, const double sideC);
    Triangle(const Triangle& other);

    void increaseSidesBy(const double delta);
    void setSides(const double sideA, const double sideB, const double sideC);
    void getSides(double &sideA, double &sideB, double &sideC) const;

    double getArea() const;
    void getAngles(double &angleA, double &angleB, double &angleC) const;
    double getPerimeter() const;
    void getMedians(double &medianA, double &medianB, double &medianC) const;
    bool isRectangular() const;

    void applyToForm(TriangleViewer& form);
    void getFromForm(const TriangleViewer& form);
};

#endif // TRIANGLE_H
