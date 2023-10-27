#include <iostream>

#define SQUARE(x)  (x) * (x)       //제곱
#define ABS(y)    ( ((y) < 0) ? -(y) : (y) )            //절댓값

int main()
{
    printf("안녕하세요. C++의 세계에 오신 걸 환영합니다.\n\n");

    printf("2의 제곱 = %d\n", SQUARE(2));
    printf("5의 제곱 = %d\n", SQUARE(5));
    printf("1.2의 제곱 = %f\n", SQUARE(1.2));  //매크로 함수의 장점: 정수와 실수 모두 쓸 수 있다.

    int x = 7;
    printf("%d의 제곱 : %d\n", x, SQUARE(x));  
    printf("%d의 제곱 = %d\n", x + 1, SQUARE(x + 1));

    int y = -9;
    printf("%d의 절댓값 = %d\n", y, ABS(y));
    printf("-2의 절댓값 = %d\n", ABS(-2));

    //std::cout << "안녕하세요. C++의 세계에 오신 걸 환영합니다.\n";
}

