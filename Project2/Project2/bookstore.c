#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// 책 정보 구조체
struct book
{
    int num;
    int price;
    char title[20];
    char author[20];
    char pub[20];
};

// 책 목록을 저장하는 배열과 등록된 책의 수
struct book list[100];
int count = 0;

// 함수 원형 선언
void registerBook();
void listBooks();
void searchBook();

int main()
{
    int key;

    while (1)
    {
        printf("*****메뉴*****\n");
        printf(" 1. 등록\n 2. 목록\n 3. 검색\n 0. 종료\n");
        scanf("%d", &key);

        if (key == 0)
        {
            break;
        }
        else if (key == 1) 
        {   
            registerBook();
        }
        else if (key == 2)
        {
            listBooks();
        }
        else if (key == 3)
        {
            searchBook();
        }
    }

    return 0;
}


void registerBook()                         // 책 등록 함수
{
    if (count < 100)
    {
        printf("등록하려는 책의 번호를 입력하세요: ");
        scanf("%d", &list[count].num);
        printf("책 제목을 입력하세요: ");
        scanf("%s", list[count].title);
        printf("등록하려는 책의 저자를 입력하세요: ");
        scanf("%s", list[count].author);
        printf("등록하려는 책의 출판사를 입력하세요: ");
        scanf("%s", list[count].pub);
        printf("등록하려는 책의 가격을 입력하세요: ");
        scanf("%d", &list[count].price);
        count++;
    }
    else
    {
        printf("더 이상 책을 등록할 수 없습니다. (100개 초과)\n");
    }
}


void listBooks()            // 책 목록 표시 함수
{
    if (count == 0)
    {
        printf("등록된 책이 없습니다.\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("등록한 책의 목록: %d. %s %s %s %d 원 입니다.\n",
                list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);
        }
    }
}


void searchBook()              // 책 검색 함수
{
    char search[100];
    printf("검색하려는 책의 제목을 입력하세요: ");
    scanf("%s", search);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(search, list[i].title) == 0)
        {
            printf("검색 결과: %d. %s %s %s %d 원\n", list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);
            found = 1;
        }
    }

    if (!found)
    {
        printf("검색 결과가 없습니다.\n");
    }
}
