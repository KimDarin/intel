#pragma once
#include <iostream>
#define MIN(x, y)       (((x) > (y)) ? (y) : (x))
#define MAX(x, y)      (((x) < (y)) ? (y) : (x))

class Point
{
private:         //���� ������(�ܺ� ���� �Ұ�)

public:          //���� ������(�ܺ� ���� ����)   
    int x, y, z;    //��� ���� ����, ��ü(�� �ڽ�)�� ��ǥ, �� �� �� �� ���� �� �ڽ�   
    Point(int x = 0, int y = 0) : x(x), y(y)     //�̴ϼȶ�����(�ʹ� ���� �� ���� �ʱ�)
        //������ ����(��� ������ arg�� �޴� ���� ����), �Լ��� Ư��(overload, default  ��) 
        //cf. �̴ϼȶ����� �� �� ���� �̸� ���� �ص� ��.
        //ex) (int x = 0, int y = 0) : x(x), y(y)   (O)
    {
        z = 0; //x = x1; y = y1;          
    }
    void SetP(int x1 = 0, int y1 = 0) { x = x1;  y = y1; }
    double Dist(Point p)                     //��� �Լ�: �� ��(�ڽ� ����) ���� �Ÿ� ���, double ������ ����
    {
        int w = x - p.x;
        int h = y - p.y;
        double d = sqrt((w * w) + (h * h));

        return d;
        //return sqrt((w * w) + (h * h));
    }
    double Dist(Point p1, Point p2)         //��� �Լ�: �� ��(�ڽ� ����) ���� �Ÿ� ���, double ������ ����
    {
        int w = p1.x - p2.x;
        int h = p1.y - p2.y;
        double d = sqrt((w * w) + (h * h));

        return d;
        //return sqrt((w * w) + (h * h));
    }
};

class Rect
{
public:
    Point p11, p22;                                    //Ŭ���� ������ ����
    Point LOWL, LOWR, UPL, UPR;         //�ʱ�ȭ ����, �ܺ� ���� ���
    Rect(Point p1, Point p2)
    {
        int xlow = MIN(p1.x, p2.x);
        int xup = MAX(p1.x, p2.x);
        int ylow = MIN(p1.y, p2.y);
        int yup = MAX(p1.y, p2.y);

        LOWL = Point(xlow, ylow);
        LOWR = Point(xup, ylow);
        UPL = Point(xlow, yup);
        UPR = Point(xup, yup);
        p11 = p1; p22 = p2;
    }
    Point GetLOWL() { return Point(MIN(p11.x, p22.x), MIN(p11.y, p22.y)); }
    //��� ������  p11, p22�� �Ǿ��ֱ� ����(p1, p2�� ���ú���)     
    Point GetLOWR() { return Point(MAX(p11.x, p22.x), MIN(p11.y, p22.y)); }
    Point GetUPL() { return Point(MIN(p11.x, p22.x), MAX(p11.y, p22.y)); }
    Point GetUPR() { return Point(MAX(p11.x, p22.x), MAX(p11.y, p22.y)); }
};