#pragma once
#include <iostream>

class person
{
protected:
	char *name = NULL;
public:	
	int Age;
	person(int age = 0) : Age(age) {}									//NULL ������
	person(const char* Nam, int age)	: Age(age)					//������
	{
		rename(Nam);
		name = new char[strlen(Nam) + 1];			//�޸� ���� Ȯ��
		strcpy(name, Nam);
	}

	person& rename(const char* Nam)				//�̸� �ٲ��� �� ���� �Լ�
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
		printf("%s(%d��)", name, Age);
	}
	~person()								//�Ҹ���
	{
		if (name)
		{
			delete name;					//���� Ȯ�� ����
		}
	}
};

class subject	//���� �̸�, ���� �Էµ� ���� �հ�, ���
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
		printf("����: %s, ����: %d\n", name, Score);
	}
};

class haksaeng : public person
{
	char* Major = NULL;
public:
	int Grade;
	int subnum = 0;		//���������� ��
	subject sub[10];				//�ǹ迭		//kor, eng;
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
		printf("%s��(%d�г�)\n", Major, Grade);		//ȫ�漭(19��), ���ڰ��а�(1�г�) 
		for (int i = 0; i < subnum; i++)
		{
			printf("����: %s, ����: %d\n", sub[i].Name(), sub[i].Score);
		}
	}
};

