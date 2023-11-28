#include <iostream>
#include "Point.h"

int main()
{
    Point<int> p1(10, 10), p2, p3;
    p1.viewP("P1");
    p2.viewP();
    p3.viewP();
    Point<int> p4 = p3, p5(p2);

    p2.SetP(Point<int>(20, 30)).viewP("P2");
    p3.SetP(40, 70).viewP("P3");
    printf("두 점으로 정의되는 사각형의 넓이는 %f 입니다\r\n", p2 * p3);

    Point<int> p6 = p1 + p2;
    printf("Point [Operator+] Test...");
    p6.viewP("_P6");
    printf("Point [Operator++] 후행연산 Test...");
    p6++.viewP("_P6");
    printf("Point [Operator++] 선행연산 Test...");
    (++p6).viewP("_P6");
}
