#include <iostream>

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
    double Dist(Point p) 
    {
    int w = (x - p.x);                //멤버 변수를 로컬 변수로 쓸 수 있다.
    int h = (y - p.y);

    double d = sqrt(w * w + h * h);           //스퀘어 루트


    return d;
    }            
    double Square(Point p);          
};



double Point::Square(Point p)
{
    int w1 = x - p.x;
    int h1 = y - p.y;

    double d2 = w1 * h1;

    return d2;
}                                                //여기까지는 껍데기임

int main()
{
    Point p1(10, 10), p2(20, 30);                //객체 생성

    double d = p1.Dist(p2);     //p1은 객체, Dist함수가 원래 자기가 갖고있던 값(x,y)이랑 p2값으로 Dist 함수 돌려서 d로 출력..(?)
    //p1이라는 객체는 이미 갖고 있기 때문에 p2 하나만 받으면 됨.
    printf("두 점 p1(%d, %d), p2(%d, %d)의 거리는 %.2f입니다.\n",
        p1.x, p1.y, p2.x, p2.y, d);

    double d2 = p1.Square(p2);
    printf("사각형의 넓이는 %.2f 입니다.\n", d2);
}