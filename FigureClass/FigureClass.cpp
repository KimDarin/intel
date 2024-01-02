#include <iostream>

class Shape
{
public:
	int x, y;
	Shape(int x = 0, int y = 0) : x(x), y(y) {}
	~Shape() {}
};

class Circle : public Shape
{

};

class Rectangle : public Shape
{

};

class Triangle : public Shape
{

};

int main()
{
 
}
