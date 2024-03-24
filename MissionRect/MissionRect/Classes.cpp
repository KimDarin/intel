#include "Classes.h"

double Point::Dist(Point p)
{
	int w = x - p.x;
	int h = y - p.y;

	return sqrt(w * w + h * h);
}

void Point::Show(const char* s)
{
	printf("%s(%d,%d)\n", s, x, y);
}

void Point::ShowEx(const char* s)
{
	std::cout << s << "(" << x << "," << y << ")" << std::endl;
	printf("%s(%d,%d)", s, x, y);							
}

Point& Point::operator+(Point p)  // ���� CurP�� p�� + �������� (���ο� Point��) ��ȯ
{
	Point* p1 = new Point(x + p.x, y + p.y);

	return *p1;
}

Rect& Rect::Show(const char* s)	// Rect(P1(x1, y1)),  P2(x2, y2))
{
	printf("%s(", s);
	LL.ShowEx("LL");
	UR.ShowEx("UR");
	printf(")\n");

	return *this;
}

double Rect::Area()	
{
	return (double)(ABS((p1.x - p2.x) * (p1.y - p2.y)));
}


Rect& Rect::operator +(Rect r)
{
	int x1 = MIN(MIN(  this-> x1, this-> x2), MIN (r.x1, r.x2));
	int x2 = MAX(MAX(this-> x1, this-> x2), MAX(r.x1, r.x2));
	int y1 = MIN(MIN(  this-> y1, this-> y2), MIN (r.y1, r.y2));
	int y2 = MAX(MAX(this-> y1, this-> y2), MAX(r.y1, r.y2));

	return *(new Rect(x1, y1, x2, y2));

}

Rect& Rect::operator -(Rect r)
{
	int x1, x2, x3, x4;
	int y1, y2, y3, y4, y5;
	Rect& rr = *this;		//�� �ڽ��� ������ �� �� rr�̶�� ���ڴ�.
	y5 = 0;
	
	///�� �簢���� ��ġ�� �ʴ� ���  0  rect�� ��ȯ
	if (rr.LR.x < rr.LL.x || rr.LL.x > r.LR.x) { return *(new Rect(0, 0, 0, 0)); }
	if (rr.UL.y < rr.LL.y || rr.LL.y > r.UL.y) { return *(new Rect(0, 0, 0, 0)); }

	x1 = MIN(MIN(rr.x1, rr.x2), MIN(r.x1, r.x2));
	x2 = MAX(rr.LL.x, r.LL.x);  
	x3 = MIN(rr.UR.x, r.UR.x);
	x4 = MAX(MAX(rr.x1, rr.x2), MAX(r.x1, r.x2));



	//if (r.LL.x == x1) { x2 = MAX(rr.LL.x, r.LL.x);  x3 = MIN(rr.LR.x, r.LR.x); }

	y1 = MIN(MIN(rr.y1, rr.y2), MIN(r.y1, r.y2));
	y2 = MAX(rr.LL.y, r.LL.y);
	y3 = MIN(r.UR.y, rr.UR.y);
	y4 = MAX(MAX(rr.y1, rr.y2), MAX(r.y1, r.y2));

	return *(new Rect(x2, y2, x3, y3));


	if (r.LL.y == y1) { y2 = rr.LL.y;  y3 = r.UL.y; }


}

double Rect::operator* (Rect r)
{
	double d1 = this-> Area();
	double d2 = r.Area();
	double d3 = (*(this)-r).Area();

	return (d1 + d2 - d3);


}



