#pragma once
#include <iostream>

class person
{
protected:
	char *name = NULL;
public:	
	int Age;
	person(int age = 0) : Age(age) {}									//NULL 생성자
	person(const char* Nam, int age)	: Age(age)					//생성자
	{
		rename(Nam);
		name = new char[strlen(Nam) + 1];			//메모리 공간 확보
		strcpy(name, Nam);
	}

	person& rename(const char* Nam)				//이름 바꿨을 때 쓰는 함수
	{
		if (name)
		{
			delete name;
		}
			name = new char[strlen(Nam) + 1];
			strcpy(name, Nam);
			return *this;
	}

	void Show() 
	{
		printf("%s(%d세)", name, Age);
	}
	~person()								//소멸자
	{
		if (name)
		{
			delete name;					//공간 확보 삭제
		}
	}
};

class subject	//과목 이름, 점수 입력된 점수 합계, 평균
{
	char* name = NULL;
public:
	int Score;
	subject() {}
	subject(const char* Nam, int score) : Score(score)
	{
		resub(Nam);
	}
	subject& resub(const char* Nam)
	{
		if (name) delete name;
		name = new char[strlen(Nam) + 1];
		strcpy(name, Nam);
		return *this;
	}
	char* Name() {  return (char*)name; }

	void Show()
	{
		printf("과목: %s, 점수: %d\n", name, Score);
	}
};

class haksaeng : public person
{
	char* Major = NULL;
public:
	int Grade;
	int subnum = 0;		//수강과목의 수
	subject sub[10];				//실배열		//kor, eng;
	haksaeng(const char* Nam, int age, const char* major, int grade) : person(Nam, age), Grade(grade)
	{
		reMajor(major);
	}
	void SetSub(const char* Nam, int sco) 
	{
		if (subnum > 10) return;
		sub[subnum++].resub(Nam).Score = sco;
	}
	haksaeng& reMajor(const char* major)
	{
		if (Major)
		{
			delete Major;
		}
		Major = new(char[strlen(major) + 1]);
		strcpy(Major, major);
		return *this;
	}
	
	~haksaeng()
	{
		if (Major)
		{
			delete Major;
		}
	}
	void Show()
	{
		((person*)this)->Show();
		printf("%s과(%d학년)\n", Major, Grade);		//홍길서(19세), 전자공학과(1학년) 
		for (int i = 0; i < subnum; i++)
		{
			printf("과목: %s, 점수: %d\n", sub[i].Name(), sub[i].Score);
		}
	}
};

