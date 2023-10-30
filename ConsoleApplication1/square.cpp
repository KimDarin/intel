#include <iostream>
#define ABS(y)    ( ((y) < 0) ? -(y) : (y) )       //절댓값

class Point                           //class 선언 (선언: 틀 정의)
{
public:
    int x;
    int y;                            //얘네는 값이 들어가있지는 않음 (only 선언)
    //나 자신(x,y)

    Point(int x1, int y1)             //생성자 이름 = 클래스 이름과 동일해야함
    {
        x = x1;  y = y1;              //객체화와 초기화 거의 같다고 생각하면 됨. 
    }

    double Square(Point p);
};

double Point::Square(Point p)
{
    int w = ABS(x - p.x);
    int h = ABS(y - p.y);
    double d = w * h;

    return d;
}                                                //여기까지는 껍데기임

int main()
{
    Point p1(10, 10), p2(20, 30);                //객체 생성

    double d = p1.Square(p2);
    printf("두 점 p1(%d, %d), p2(%d,%d)의 사각형 넓이는 %.2f 입니다.\n", p1.x, p1.y, p2.x, p2.y, d);
}