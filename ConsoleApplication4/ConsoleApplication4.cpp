#include <iostream>
#include ".\\bb\\Point.h"
#define MIN(x, y)       (((x) > (y)) ? (y) : (x))
#define MAX(x, y)      (((x) < (y)) ? (y) : (x))

void printP(Point p)
{
    printf("Point(%d, %d)\n", p.x, p.y);
}

void swap_v(int a, int b)             //call by value
{   
    int temp(a);
    printf("[swap] 초기값  a = %d, 초기값  b = %d\n", a, b);
    a = b;
    b = temp;
    printf("[swap] 결과값  a = %d, 결과값  b = %d\n", a, b);
}

void swap_p(int *a, int *b)           //call by reference
{
    int temp(*a);                             //해당 주소의 값  
    printf("[swap] 초기값  a = %d, 초기값  b = %d\n", *a, *b);
    *a = *b;
    *b = temp;
    printf("[swap] 결과값  a = %d, 결과값  b = %d\n", *a, *b);

}

void swap_r(int &a, int &b)           //call by reference (using ref, variables)
                                                      //레퍼런스 변수는 호출하는 변수와 동기화(포인터가 아닌데 포인터로 동작)
{
    int temp(a);                               //선언부                              
    printf("[swap_r] 초기값  a = %d, 초기값  b = %d\n", a, b);
    a = b;
    b = temp;
    printf("[swap_r] 결과값  a = %d, 결과값  b = %d\n", a, b);

}

int main()
{
    Point arr[3];                 // 객체 배열: 3개의 Point 클래스 객체가 default로 초기화 됨.
    arr[0].SetP(10, 10);       printP(arr[0]);
    arr[1].SetP(20, 30);      printP(arr[1]);
    arr[2].SetP(40, 60);      printP(arr[2]);
    Point p1, p2(10, 10), p3(20, 30), p4;        //포인트 객체 선언, p1은 (0, 0) default값이 0이기 때문
    p4 = p3;
    double d = p1.Dist(p2);                          //기준.Dist(~까지의 거리)
    double d1 = p2.Dist(p3);
    double d2 = p1.Dist(p2, p3);                 //여기 있는 p1은 순전히 함수를 사용하기 위한 객체
    //p2에서 p3거리 구하는 법
    printP(p1); printP(p2); printP(p3); printP(p4);    
    printf("점 간의 계산: d(p1, p2) = %.2f, d1(p2, p3) = %.2f, d2(p2, p3) = %.2f\n", d, d1, d2);

    printf("class Point 객체 크기: %ld\n", sizeof(arr));
    Point* Parr[3];              // 포인터(*) 배열: 현재 객체화 X, 어디를 가르키고 있는지 모름. 반드시 초기화 해줘야 함.
    printf("Point 객체 포인터 배열 크기: %ld\n", sizeof(Parr));
    Parr[0] = new Point(10, 10);  printP(*Parr[0]);
    Parr[1] = new Point(20, 30);  printP(*Parr[1]);
    Parr[2] = new Point(40, 60);  printP(*Parr[2]);


    

      
     Rect r(p2, p3);
    printf("두 점\n");
    printP(p2); printP(p3);
   
    printP(r.LOWL);  printP(r.LOWR);  printP(r.UPL);  printP(r.UPR);
    printP (r.GetLOWL());  printP(r.GetLOWR());  printP(r.GetUPL());  printP(r.GetUPR());

    int a(10), b(20);                                                                           //변수에도 이니셜라이저 됨(C++의 새로운 대입문)
    //a = 10; b = 20; 
    swap_r(a, b);           //그냥 변수로 호출
    printf(" a = %d,  b = %d\n", a, b);

    int a1, b1;             
    printf("a1 = %d, b1 = %d\n", a1 = 20, b1 = 30);                       //변수가 상수가 아니라면 가능
    //printf("변수 a1 = %d, b1 = %d\n", a1(30), b1(40));       (X)    //"변수(값)"은 변수 초기화 시에만 가능     

    swap_v(a, b);
    printf(" [swap_v] a = %d, b = %d\n", a, b);                                            //call by value의 대표적인 예

    swap_p(&a, &b);                                                                                      //call by reference 변수 주소           
    printf(" [swap_p] a = %d, b = %d\n", a, b);

    int n = 1234;
    int &m = n;     //ref선언과 동시에 초기화     m은 n의 별명이 됨
    printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n , m);
    m = 5678;      
    printf("[레퍼런스 변수 테스트] n = %d, m = %d\n", n, m);     //m을 손 댔는데 n도 같이 바뀜 왜? 레퍼런스 변수니까~
}