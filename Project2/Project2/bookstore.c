#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

// å ���� ����ü
struct book
{
    int num;
    int price;
    char title[20];
    char author[20];
    char pub[20];
};

// å ����� �����ϴ� �迭�� ��ϵ� å�� ��
struct book list[100];
int count = 0;

// �Լ� ���� ����
void registerBook();
void listBooks();
void searchBook();

int main()
{
    int key;

    while (1)
    {
        printf("*****�޴�*****\n");
        printf(" 1. ���\n 2. ���\n 3. �˻�\n 0. ����\n");
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


void registerBook()                         // å ��� �Լ�
{
    if (count < 100)
    {
        printf("����Ϸ��� å�� ��ȣ�� �Է��ϼ���: ");
        scanf("%d", &list[count].num);
        printf("å ������ �Է��ϼ���: ");
        scanf("%s", list[count].title);
        printf("����Ϸ��� å�� ���ڸ� �Է��ϼ���: ");
        scanf("%s", list[count].author);
        printf("����Ϸ��� å�� ���ǻ縦 �Է��ϼ���: ");
        scanf("%s", list[count].pub);
        printf("����Ϸ��� å�� ������ �Է��ϼ���: ");
        scanf("%d", &list[count].price);
        count++;
    }
    else
    {
        printf("�� �̻� å�� ����� �� �����ϴ�. (100�� �ʰ�)\n");
    }
}


void listBooks()            // å ��� ǥ�� �Լ�
{
    if (count == 0)
    {
        printf("��ϵ� å�� �����ϴ�.\n");
    }
    else
    {
        for (int i = 0; i < count; i++)
        {
            printf("����� å�� ���: %d. %s %s %s %d �� �Դϴ�.\n",
                list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);
        }
    }
}


void searchBook()              // å �˻� �Լ�
{
    char search[100];
    printf("�˻��Ϸ��� å�� ������ �Է��ϼ���: ");
    scanf("%s", search);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(search, list[i].title) == 0)
        {
            printf("�˻� ���: %d. %s %s %s %d ��\n", list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);
            found = 1;
        }
    }

    if (!found)
    {
        printf("�˻� ����� �����ϴ�.\n");
    }
}
