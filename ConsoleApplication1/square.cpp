#include <iostream>
#define ABS(y)    ( ((y) < 0) ? -(y) : (y) )       //����

class Point                           //class ���� (����: Ʋ ����)
{
public:
    int x;
    int y;                            //��״� ���� �������� ���� (only ����)
    //�� �ڽ�(x,y)

    Point(int x1, int y1)             //������ �̸� = Ŭ���� �̸��� �����ؾ���
    {
        x = x1;  y = y1;              //��üȭ�� �ʱ�ȭ ���� ���ٰ� �����ϸ� ��. 
    }

    double Square(Point p);
};

double Point::Square(Point p)
{
    int w = ABS(x - p.x);
    int h = ABS(y - p.y);
    double d = w * h;

    return d;
}                                                //��������� ��������

int main()
{
    Point p1(10, 10), p2(20, 30);                //��ü ����

    double d = p1.Square(p2);
    printf("�� �� p1(%d, %d), p2(%d,%d)�� �簢�� ���̴� %.2f �Դϴ�.\n", p1.x, p1.y, p2.x, p2.y, d);
}