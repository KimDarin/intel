#include <iostream>
//class AAA
//{
//private:
//	int a1;
//protected:	
//	int a2;
//public:
//	int a3;
//	AAA() { printf("AAA\n"); }				        //생성과 동시에 호출됨.(생성자) 25행 AAA.a에 인해 호출
//	~AAA() { printf("~AAA\n"); }					//소멸자
//	virtual void name() { printf("class name = AAA\n"); }
//};
//class BBB : public AAA
//{
//public:
//	int b1;
//	int b2;
//	int b3;
//	BBB() { printf("BBB\n"); }
//	~BBB() { printf("~BBB\n"); }				 	//소멸자
//
////	void Test() { printf("a1 = % d, a2 = % d, a3 = % d\n", -1, a2, a3); }
//	void name() { printf("class name = BBB\n"); }
//};
class C
{
public:
	C() { printf("_C_\n"); }
	virtual void func1() = 0 {}			//순수 가상 함수(상속을 위한 클래스)
	virtual void func2() = 0 {}
};
class C1 : public C
{
public:
	C1() { printf("_C1_\n"); }
	virtual void func2()
	{
		printf("func2_in_C1_\n");
	}
};
//void func()
//{
//	printf("in function start. . .\n");
//	//포인터변수(<---->실변수)	Heap에 저장(자동 소멸X - 명시적 소멸자 반드시 필요)
//	//AAA *a = new AAA();			
//	BBB* b = new BBB();
//	b->name();					//상속받은 클래스 안에서 protected 이하 사용 가능
//	((AAA*)b)->name();
//	
//	
//	AAA* a = (AAA*)b;         		//복사 생성자
//	a->name();
//	
//	printf("in function end.\n");
//	//명시적 소멸자
//	delete b;				
//	//delete a;
//}
//void func1()
//{
//	printf("in function1 start. . .\n");					//포인터변수(<---->실변수)	Heap에 저장(자동 소멸X - 명시적 소멸자 반드시 필요)
//	
//	AAA *a = new AAA();			
//	a->name();							//상속받은 클래스 안에서 protected 이하 사용 가능
//
//	BBB* b = (BBB*)a;         		//복사 생성자
//	b->name();
//	printf("b1 = %d\n", ((BBB*)a)->b1);
//	delete a;
//
//	printf("in function1 end.\n");
//}
int main()
{
	printf("program start. . .\n");
	//Stack에 저장(자동 소멸)
	//AAA a;					
	//BBB b;					    //AAA,BBB 호출(상속)
	//AAA a = b;				//복사 생성자

	C1 c1;
	c1.func();
	//func(); 
	//func1();
	printf("program end.\n");
	//a.name();
	//b.name();
}
