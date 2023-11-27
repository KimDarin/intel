#include <iostream>

template <typename T>
class ArrTest
{
private:
	T* arr;
	int Len;		//정수여야만함(배열 요소의 수)
public:
	ArrTest(int size) : Len(size)			//생성자
	{
		arr = new T[size];
	}
	~ArrTest() 									//소멸자
	{
		delete[] arr;					
	}

	int length() {
		return Len;
	}

	T& operator[](int idx)			// calling sequence: arr[n]  &: 참조 변수
	{
		if (idx < 0 || idx > Len - 1)
		{
			std::cout << "Out of bound\n";
			exit(1);
		}

		//return *(arr + idx);		//포인터 타입
		return arr[idx];				//배열 타입(read only)
	}
	void show();
	ArrTest& append(int size);						//arr 재생성
	ArrTest& append(ArrTest brr);

	void show()
	{
		printf("배열 요소 = {");
		for (int i = 0; i < Len; i++) {
			if (i != 0) {
				printf(", ");
			}
			std::cout << arr[i];
		}
		printf("}\n");
	}

	ArrTest& append(int size)				//size : total?
	{
		T* arr1 = new T[Len + size];				//확장된 메모리
		memcpy(arr1, arr, Len * sizeof(T));
		delete[] arr;
		arr = arr1;
		Len += size;

		return *this;
	}

	ArrTest& append(ArrTest& brr)	 		 //size : total?
	{
		T* arr1 = new T[Len + brr.length()];			//확장될 메모리 공간
		memcpy(arr1, arr, Len * sizeof(T));
		memcpy(arr1 + Len, brr.arr, brr.length() * sizeof(T));
		delete[] arr;
		arr = arr1;
		Len += brr.length();

		return *this;
	}
};

class func
{
public:
	int operator() (int a, int b)
	{
		return a * b;
	}
	double operator() (double a, double b)
	{
		return a * b;
	}
	ArrTest<int>& operator()(ArrTest<int>& b1, ArrTest<int>& b2)
	{
		return b1.append(b2);
	}
};

int main()
{
	int a1[] = { 1, 2, 3, 4, 5 };
	ArrTest<int> arr(5);			//클래스는 명시적으로 <int> 적어줘야함
	
	for (int i = 0; i < 5; i++)							arr[i] = a1[i];
	//for (int i = 0; i < arr.length(); i++)			printf("ArrTest[%d] = %d\n", i, arr[i]);
	//
	//int a2[] = { 21, 22, 23, 24, 25 };
	//int n = arr.length();
	//printf("배열 확장 %d --> %d\n", arr.length(), arr.append(10).length());
	//for (int i = 5; i < 10; i++)							arr[i] = a2[i-5];
	//for (int i = 0; i < arr.length(); i++)			printf("ArrTest[%d] = %d\n", i, arr[i]);
	int a2[] = { 6, 7, 8, 9, 10 };
	ArrTest<int> brr(5);
	for (int i = 0; i < 5; i++)							brr[i] = a2[i];
	//int n = arr.length();
	//printf("배열 확장 %d --> %d\n", n, arr.append(brr).length());
	//
	//for (int i = 0; i < arr.length(); i++)					printf("ArrTest[%d] = %d\n", i, arr[i]);
	func mul;
	std::cout << mul(2, 3) << "\n";
	std::cout << mul(2.5, 3.7) << "\n";
	mul(arr, brr).show();

}

