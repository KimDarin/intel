#include <iostream>

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
    double Dist(Point p) 
    {
    int w = (x - p.x);                //��� ������ ���� ������ �� �� �ִ�.
    int h = (y - p.y);

    double d = sqrt(w * w + h * h);           //������ ��Ʈ


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
}                                                //��������� ��������

int main()
{
    Point p1(10, 10), p2(20, 30);                //��ü ����

    double d = p1.Dist(p2);     //p1�� ��ü, Dist�Լ��� ���� �ڱⰡ �����ִ� ��(x,y)�̶� p2������ Dist �Լ� ������ d�� ���..(?)
    //p1�̶�� ��ü�� �̹� ���� �ֱ� ������ p2 �ϳ��� ������ ��.
    printf("�� �� p1(%d, %d), p2(%d, %d)�� �Ÿ��� %.2f�Դϴ�.\n",
        p1.x, p1.y, p2.x, p2.y, d);

    double d2 = p1.Square(p2);
    printf("�簢���� ���̴� %.2f �Դϴ�.\n", d2);
}