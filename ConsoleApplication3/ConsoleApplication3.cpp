#include <iostream>

class Point
{
private:         //접근 지시자(외부 참조 불가)
    
public:          //접근 지시자(외부 참조 가능)   
    int x, y;    //멤버 변수 선언, 객체(나 자신)의 좌표, 두 점 중 한 점은 나 자신   
    Point(int x1 = 0, int y1 = 0): x(x1), y(y1)     //이니셜라이져(너무 많은 것 넣지 않기)
    //생성자 정의(멤버 변수와 arg로 받는 변수 구별), 함수적 특성(overload, default  등) 
    {
       //x = x1; y = y1;          
    }
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
void printP(Point p)
{
    printf("Point(%d, %d)\n", p.x, p.y);
}
int main()
{
    Point p1, p2(10, 10), p3(20, 30);       //포인트 객체 선언, p1은 (0, 0) default값이 0이기 때문
    double d = p1.Dist(p2);                 //기준.Dist(~까지의 거리)
    double d1 = p2.Dist(p3);
    double d2 = p1.Dist(p2, p3);            //여기 있는 p1은 순전히 함수를 사용하기 위한 객체
    //p2에서 p3거리 구하는 법
    printP(p1);   printP(p2);   printP(p3);
    
    printf("점 간의 계산: d(p1, p2) = %.2f, d1(p2, p3) = %.2f, d2(p2, p3) = %.2f\n", d, d1, d2);
}