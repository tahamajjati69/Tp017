#ifndef POINT_H
#define POINT_H
class Point {
private:
    double x, y;
public:
    Point();
    Point(double x, double y);
    double getX() const;
    double getY() const;
};
#endif

#ifndef SEGMENT_H
#define SEGMENT_H
#include "Point.h"
class Segment {
private:
    Point a, b;
public:
    Segment(const Point& a, const Point& b);
    double longueur() const;
};
#endif

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Segment.h"
class Triangle {
private:
    Point a, b, c;
public:
    Triangle(const Point& a, const Point& b, const Point& c);
    double perimetre() const;
};
#endif

#include "Point.h"
Point::Point() : x(0), y(0) {}
Point::Point(double x, double y) : x(x), y(y) {}
double Point::getX() const { return x; }
double Point::getY() const { return y; }

#include "Segment.h"
#include <cmath>
Segment::Segment(const Point& a, const Point& b) : a(a), b(b) {}
double Segment::longueur() const {
    double dx = b.getX() - a.getX();
    double dy = b.getY() - a.getY();
    return std::sqrt(dx*dx + dy*dy);
}

#include "Triangle.h"
Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c) {}
double Triangle::perimetre() const {
    Segment ab(a,b), bc(b,c), ca(c,a);
    return ab.longueur() + bc.longueur() + ca.longueur();
}

#include <iostream>
#include "Triangle.h"
using namespace std;
int main() {
    Point A(0,0), B(3,0), C(0,4);
    Triangle t(A,B,C);
    cout << "Périmètre du triangle : " << t.perimetre() << endl;
    return 0;
}

