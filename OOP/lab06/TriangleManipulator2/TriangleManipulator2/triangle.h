#ifndef TRIANGLE_H
#define TRIANGLE_H

class TriangleViewer;

class Triangle
{
    double sideA, sideB, sideC;

    static int createdTriangles;

    bool isExist(const double sideA, const double sideB, const double sideC);
    static void increaseCreatedTriangles();

public:
    Triangle();
    Triangle(const double sideA, const double sideB, const double sideC);
    Triangle(const Triangle& other);

    void increaseSidesBy(const double delta);
    void increaseSidesBy(const double deltaA, const double deltaB, const double deltaC);
    void multiplySidesBy(const double scale);
    void setSides(const double sideA, const double sideB, const double sideC);
    void setSides(const double side);
    void getSides(double &sideA, double &sideB, double &sideC) const;
    void getSides(double &sideA) const;

    double getArea() const;
    void getAngles(double &angleA, double &angleB, double &angleC) const;
    double getPerimeter() const;
    void getMedians(double &medianA, double &medianB, double &medianC) const;
    bool isRectangular() const;

    void applyToForm(TriangleViewer& form);
    void getFromForm(const TriangleViewer& form);

    Triangle operator+(const double delta);
    Triangle operator*(const double scale);
    double& operator[](const char side);
    const double& operator[](const char side) const;
    operator double() const;

    friend const TriangleViewer &operator<<(const TriangleViewer& window, Triangle& triangle);
    friend TriangleViewer& operator>>(TriangleViewer& window, const Triangle& triangle);
    friend bool operator>(const Triangle& a, const Triangle& b);
    friend bool operator<(const Triangle& a, const Triangle& b);
    friend bool operator==(const Triangle& a, const Triangle& b);

    static int getCreatedTriangles();

};

#endif // TRIANGLE_H
