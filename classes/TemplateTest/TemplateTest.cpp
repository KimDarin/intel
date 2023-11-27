#include <iostream>

template <typename T>
void Swap(T &a, T &b)
{
	T c = a;
	a = b;
	b = c;
}

template <typename T>
T ABS(T a)
{
	if (a < 0) return -a; return a;
}

int main()
{
	int a = 10, b = 20;
	printf("a = %d, b = %d\n", a, b);
	Swap(a, b);				//Standard: Swap<int> 안써줘도 컴파일러가 알아서 해줌
	printf("a = %d, b = %d\n", a, b);

	double a1 = 2.5, b1 = 3.6;
	printf("a1 = %.2f, b1 = %.2f\n", a1, b1);
	Swap(a1, b1);		   //Standard: Swap<double>
	printf("a = %.2f, b = %.2f\n", a1, b1);
}