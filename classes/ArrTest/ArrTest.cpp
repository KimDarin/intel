#include <iostream>
#include <string>

using namespace std;
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

	//ArrTest& operator+(const ArrTest& brr)
	//{
	//	T* arr1 = new T[Len + brr.Len];  // 새로운 배열 할당

	//	// 현재 배열 복사
	//	for (int i = 0; i < Len; ++i)
	//		arr1[i] = arr[i];

	//	// 두 번째 배열 추가 복사
	//	for (int i = 0; i < brr.Len; ++i)
	//		arr1[Len + i] = brr.arr[i];

	//	delete[] arr;
	//	arr = arr1;

	//	Len += brr.Len;

	//	return *this;
	//}

	ArrTest<T>& operator+(ArrTest<T>& br)
	{
		int l = Len + br.length();										//총 길이
		ArrTest<T> *cr = new ArrTest<T>(l);					//this가 아닌 새로운 객체 생성
		//T* arr1 = new T[Len + size];								//확장된 메모리
		memcpy(cr->arr, arr, Len * sizeof(T));
		memcpy(cr->arr + Len, br.arr, br.length() * sizeof(T));

		return *cr;
	}

	ArrTest<T>& operator+=(ArrTest<T>& br)				//arr += brr
	{
		return this->append(br);
	}

	bool operator==(ArrTest<T>& br)							//if(arr == brr)
	{
		if (Len != br.length())	return false;
		for (int i = 0; i < Len; i++)
		{
			if (arr[i] != br[i])		return false;		return true;
		}
	}

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

	ArrTest& append(int size)						//size : total?
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

	friend std::ostream& operator <<(std::ostream& os, ArrTest& ar)
	{
		int i;
		printf("배열 요소 = {");
		for (int i = 0; i < ar.Len - 1; i++) {
			if (i != 0) {
				printf(", ");
			}
			std::cout << ar.arr[i];		cout << ar.arr[i];
		}
		printf("}");
		return os;
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
	ArrTest<int> arr(5);									//클래스는 명시적으로 <int> 적어줘야함	
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
	if (arr == brr)	printf("Same sequence\n");

	ArrTest<int> crr = arr + brr;

	func mul;
	std::cout << mul(2, 3) << "\n";
	std::cout << mul(2.5, 3.7) << "\n";
	std::cout << mul(arr, brr) << "\n";
	std::cout << crr << "\n";
	std::cout << (arr += brr) << "\n";

	//arr = arr + brr;
	//arr.show();

	string s = "안녕하세요";
	std::cout << s << "\n";
	std::cout << s.substr(2, 2) << "\n";
	
}

