#pragma once
#include <iostream>
#define ABS(x) (((x)<0)?(-(x)):(x))

template <typename T>
class Point
{
private:
    T x;
    T y;
public:
    Point(T x1 = 0, T y1 = 0) : x(x1), y(y1) {}

    Point& SetP(Point p);
    Point& SetP(T x1, T y1);
    Point& MoveP(int dx, int dy);
    double Dist(Point p);
    void viewP(const char* s = NULL);
    int& X() { return x; };
    int& Y() { return y; };
    Point& operator+(Point p);
    Point& operator++();
    Point& operator++(int);
    double operator*(Point p);
};

template <typename T>
class Point3D : public Point<T>
{
private:
    T z;

public:
    Point3D(T x = 0, T y = 0, T z = 0) : Point<T>(x, y), z(z) {}

    Point3D& SetP(Point3D p);
    double Dist3D(Point3D p);
};

