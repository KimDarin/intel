#pragma once
#include <iostream>
#define MIN(x, y)       (((x) > (y)) ? (y) : (x))
#define MAX(x, y)      (((x) < (y)) ? (y) : (x))

class Point
{
private:         //접근 지시자(외부 참조 불가)

public:          //접근 지시자(외부 참조 가능)   
    int x, y, z;    //멤버 변수 선언, 객체(나 자신)의 좌표, 두 점 중 한 점은 나 자신   
    Point(int x = 0, int y = 0) : x(x), y(y)     //이니셜라이저(너무 많은 것 넣지 않기)
        //생성자 정의(멤버 변수와 arg로 받는 변수 구별), 함수적 특성(overload, default  등) 
        //cf. 이니셜라이저 할 때 에는 이름 같게 해도 됨.
        //ex) (int x = 0, int y = 0) : x(x), y(y)   (O)
    {
        z = 0; //x = x1; y = y1;          
    }
    void SetP(int x1 = 0, int y1 = 0) { x = x1;  y = y1; }
    double Dist(Point p)                     //멤버 함수: 두 점(자신 포함) 간의 거리 계산, double 값으로 리턴
    {
        int w = x - p.x;
        int h = y - p.y;
        double d = sqrt((w * w) + (h * h));

        return d;
        //return sqrt((w * w) + (h * h));
    }
    double Dist(Point p1, Point p2)         //멤버 함수: 두 점(자신 제외) 간의 거리 계산, double 값으로 리턴
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
    Point p11, p22;                                    //클래스 변수의 선언
    Point LOWL, LOWR, UPL, UPR;         //초기화 가능, 외부 참조 대상
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
    //멤버 변수가  p11, p22로 되어있기 때문(p1, p2는 로컬변수)     
    Point GetLOWR() { return Point(MAX(p11.x, p22.x), MIN(p11.y, p22.y)); }
    Point GetUPL() { return Point(MIN(p11.x, p22.x), MAX(p11.y, p22.y)); }
    Point GetUPR() { return Point(MAX(p11.x, p22.x), MAX(p11.y, p22.y)); }
};