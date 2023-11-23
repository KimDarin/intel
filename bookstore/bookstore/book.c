#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int key;                                                      //메뉴 중 원하는 번호 입력 받는 키(전역 변수)
int i;                                                          //for문 
int found = 0;
//검색 작업의 결과를 나타내는 변수(검색하는 책 찾았을 경우 1로 설정됨, 못 찾았을 경우 0으로 유지)

struct book                                                // 책 정보 (구조체 변수)
{
    int num, price;                                       // 책의 번호, 가격(정수)
    char title[20], author[20], pub[20];        // 책의 제목, 저자, 출판사(문자열 배열)
    int borrowed;                                         // 대출 상태
};

struct book list[100];                                  // 책 목록을 저장하는 배열
int count = 0;                                             // 등록된 책의 수(for문 제어, 입력된 책 없을 때 목록 조회할 경우 등록된 책 없다고 출력)                      

// 함수 원형 선언
void menu();                                              //메뉴 띄우는 함수
void registerBook();                                    //책 등록하는 함수
void listBooks();                                         //책 목록 조회하는 함수   
void searchBook();                                     //책 검색하는 함수
void printBook();                                        //등록 목록, 검색 출력 함수   
void borrowBook();
void returnBook();

int main()
{
    menu();

    while (1)
    {
        if (key == 0)   //종료
        {
            break;
        }
        else if (key == 1)      //등록
        {
            registerBook();
            menu();
        }
        else if (key == 2)      //목록
        {
            listBooks();
            menu();
        }
        else if (key == 3)      //검색
        {
            searchBook();
            menu();
        }
        else if (key == 4)      //대출
        {
            borrowBook();
            menu();
        }
        else if (key == 5)      //대출
        {
            returnBook();
            menu();
        }
        else                       //0~5 외의 숫자 입력 받았을 경우 오류 메세지 표시
        {
            printf("잘못된 입력입니다. 다시 시도하세요.\n");
            menu();
        }
    }

    return 0;
}

void menu()
{
    printf("*****메뉴*****\n");
    printf(" 1. 등록\n 2. 목록\n 3. 검색\n 4. 대출\n 5. 반납\n 0. 종료\n");
    
    scanf("%d", &key);
}

void registerBook()
{
    int key2;
    while (1) {
        if (count < 100)
        {
            printf("등록하려는 책의 번호를 입력하세요(숫자 입력): ");
            scanf("%d", &list[count].num);
            printf("책 제목을 입력하세요(20자내외): ");
            scanf("%s", list[count].title);
            printf("등록하려는 책의 저자를 입력하세요(20자내외): ");
            scanf("%s", list[count].author);
            printf("등록하려는 책의 출판사를 입력하세요(20자내외): ");
            scanf("%s", list[count].pub);
            printf("등록하려는 책의 가격을 입력하세요(숫자 입력): ");
            scanf("%d", &list[count].price);

            list[count].borrowed = 0;
            count++;                                                                   //책 등록할 때 마다 count변수 +1
            while (1) {
                printf("더 입력할 책이 있으면 '1', 없으면 '2'를 입력하세요.\n");
                scanf("%d", &key2);

                if (key2 == 1)
                {
                    break;
                }
                else if (key2 == 2)
                {
                    goto loop;
                }
                else
                {
                    printf("잘못 입력하셨습니다.\n");
                }
            }
        }
        else
        {
            printf("더 이상 책을 등록할 수 없습니다.\n");                //책이 100권 이상 입력되었을 경우 오류 메세지 표시
        }

    } loop: key2;
}

void listBooks()
{
    if (count == 0)
    {
        printf("등록된 책이 없습니다.\n");                                 //등록된 책이 없을 경우 오류 메세지 표시
    }
    else                                                                               //등록된 책이 1권 이상인 경우
    {
        printf("등록된 책 목록: ");
        for (i = 0; i < count; i++) {
            printBook();
        }
    }
}

void searchBook()
{
    char search[100];
    printf("검색하려는 책의 제목을 입력하세요: ");
    scanf("%s", search);                                        //배열이름은 주소(&안붙임!)

    for (i = 0; i < count; i++)
    {
        if (strcmp(search, list[i].title) == 0)
        {
            printf("검색 결과: ");
            printBook();
            found = 1;                                              //검색 결과가 있을 경우 found 변수에 1을 대입 => 검색 결과 출력
        }
    }

    if (found == 0)
    {
        printf("검색 결과가 없습니다.\n");                //검색 결과가 없을 경우 found는 0을 유지 => 검색 결과 없음 출력
    }
}

void printBook()
{
        printf("%d. %s %s %s %d원 입니다.\n",
            list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);  
}

void borrowBook()
{
    int book_num;

    printf("대출 가능한 도서 목록입니다.\n");
    for (i = 0; i < count; i++) {
        if (list[i].borrowed == 0)
        {
            printBook();
        }
    }
    printf("\n");
    
    printf("대출하려는 도서의 번호를 입력하세요\n");
    printf("도서 번호: \n");
    scanf("%d", &book_num);

    printf("대출하려는 도서의 정보를 확인하세요.\n");

    for (i = 0; i < count; i++)
    {
        if (book_num == list[i].num)
        {
            printf("검색 결과: ");
            printBook();

            if (list[i].borrowed == 1)
            {
                printf("현재 대출 중인 도서입니다.\n");
            }
            else
            {
                printf("정상적으로 대출되었습니다\n");
                list[i].borrowed = 1;
            }

            return; // 함수 종료
        }
    }

    printf("검색 결과가 없습니다.\n");
}

void returnBook()
{
    int book_num;
    printf("반납 가능한 도서 목록입니다.\n");
    for (i = 0; i < count; i++) {
        if (list[i].borrowed == 1)
        {
            printBook();
        }
    }
    printf("\n");
    printf("반납하려는 도서의 번호를 입력하세요\n");
    printf("도서 번호: \n");
    scanf("%d", &book_num);

    printf("반납하려는 도서의 정보를 확인하세요.\n");

    for (i = 0; i < count; i++)
    {
        if (book_num == list[i].num)
        {
            printf("검색 결과: ");
            printBook();

            if (list[i].borrowed == 1)
            {
                printf("정상적으로 반납되었습니다.\n");
                list[i].borrowed = 0;
            }
            else
            {
                printf("그건 빌려준 적이 없는데용?\n");               
            }

            return; // 함수 종료
        }
    }

    printf("검색 결과가 없습니다.\n");
}