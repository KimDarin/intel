#include <iostream>
#include"haksaeng.h"

int main()
{
	//person p1("JamesLee", 17);
	//p1.Show();
	//p1.rename("JamesLee+HulkLee=Monster");
	//p1.Show();

	haksaeng s1("홍길서", 19, "전자공학", 1);
	s1.Show();
	s1.SetSub("국어", 100);
	s1.Show();
	s1.SetSub("영어", 100);
	s1.Show();
	s1.SetSub("수학", 100);
	s1.Show();
	s1.SetSub("미술", 100);
	s1.Show();

	
	
}