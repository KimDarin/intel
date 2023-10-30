#include <iostream>

#define SQUARE(x)  (x) * (x)                       //제곱
//매크로 함수 예제
#define ABS(y)    ( ((y) < 0) ? -(y) : (y) )       //절댓값
//모든 인수에 반드시 괄호 

//전역변수, 데이터 타입 선언
/*typedef struct Point        //구조체 이름이 Point
{
    int x;
    int y;
    //x와 y가 합쳐져서 하나의 점을 이룸
} Point2D; 
double Dist(Point2D p1, Point2D p2);*/

class Point     
{
public:
    int x;
    int y;
    //나 자신(x,y)

    Point(int x1, int y1)          //생성자 이름 = 클래스 이름과 동일해야함
    {
        x = x1;  y = y1;
    }                           
    double Dist(Point p);   //함수 원형 선언
    double Square(Point p1);
  };


double Point::Dist(Point p)                   //두 점 간의 거리,  class 이름 + 콜론콜론
{    
    int w = (x - p.x);
    int h = (y - p.y);

    double d = sqrt(w * w + h * h);           //스퀘어 루트


    return d;
}

double Point::Square(Point q)
{
    int w1 = x - q.x;
    int h1 = y - q.y;

    double d2 = w1 * h1;

    return d2;
}
int main()
{
/*    printf("안녕하세요. C++의 세계에 오신 걸 환영합니다.\n\n");

    printf("2의 제곱 = %d\n", SQUARE(2));
    printf("5의 제곱 = %d\n", SQUARE(5));
    printf("1.2의 제곱 = %f\n", SQUARE(1.2));  //매크로 함수의 장점: 정수와 실수 모두 쓸 수 있다.

    int x = 7;
    printf("%d의 제곱 : %d\n", x, SQUARE(x));  
    printf("%d의 제곱 = %d\n", x + 1, SQUARE(x + 1));

    int y = -9;
    printf("%d의 절댓값 = %d\n", y, ABS(y));
    printf("-2의 절댓값 = %d\n", ABS(-2));
    */

    Point p1(10, 10), p2(20, 30);
    //p1.x = 10, p1.y = 10;
    //p2.x = 20; p2.y = 30;

    double d = p1.Dist(p2);     //p1은 객체, Dist함수가 원래 자기가 갖고있던 값(x,y)이랑 p2값으로 Dist 함수 돌려서 d로 출력..(?)

    printf("두 점 p1(%d, %d), p2(%d, %d)의 거리는 %.2f입니다.\n", 
        p1.x, p1.y, p2.x, p2.y, d);

    double d2 = p1.Square(p2);
    printf("사각형의 넓이는 %.2f 입니다.\n", d2);

 //std::cout << "안녕하세요. C++의 세계에 오신 걸 환영합니다.\n";
}

