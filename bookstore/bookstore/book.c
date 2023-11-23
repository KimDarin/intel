#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int key;                                                      //�޴� �� ���ϴ� ��ȣ �Է� �޴� Ű(���� ����)
int i;                                                          //for�� 
int found = 0;
//�˻� �۾��� ����� ��Ÿ���� ����(�˻��ϴ� å ã���� ��� 1�� ������, �� ã���� ��� 0���� ����)

struct book                                                // å ���� (����ü ����)
{
    int num, price;                                       // å�� ��ȣ, ����(����)
    char title[20], author[20], pub[20];        // å�� ����, ����, ���ǻ�(���ڿ� �迭)
    int borrowed;                                         // ���� ����
};

struct book list[100];                                  // å ����� �����ϴ� �迭
int count = 0;                                             // ��ϵ� å�� ��(for�� ����, �Էµ� å ���� �� ��� ��ȸ�� ��� ��ϵ� å ���ٰ� ���)                      

// �Լ� ���� ����
void menu();                                              //�޴� ���� �Լ�
void registerBook();                                    //å ����ϴ� �Լ�
void listBooks();                                         //å ��� ��ȸ�ϴ� �Լ�   
void searchBook();                                     //å �˻��ϴ� �Լ�
void printBook();                                        //��� ���, �˻� ��� �Լ�   
void borrowBook();
void returnBook();

int main()
{
    menu();

    while (1)
    {
        if (key == 0)   //����
        {
            break;
        }
        else if (key == 1)      //���
        {
            registerBook();
            menu();
        }
        else if (key == 2)      //���
        {
            listBooks();
            menu();
        }
        else if (key == 3)      //�˻�
        {
            searchBook();
            menu();
        }
        else if (key == 4)      //����
        {
            borrowBook();
            menu();
        }
        else if (key == 5)      //����
        {
            returnBook();
            menu();
        }
        else                       //0~5 ���� ���� �Է� �޾��� ��� ���� �޼��� ǥ��
        {
            printf("�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���.\n");
            menu();
        }
    }

    return 0;
}

void menu()
{
    printf("*****�޴�*****\n");
    printf(" 1. ���\n 2. ���\n 3. �˻�\n 4. ����\n 5. �ݳ�\n 0. ����\n");
    
    scanf("%d", &key);
}

void registerBook()
{
    int key2;
    while (1) {
        if (count < 100)
        {
            printf("����Ϸ��� å�� ��ȣ�� �Է��ϼ���(���� �Է�): ");
            scanf("%d", &list[count].num);
            printf("å ������ �Է��ϼ���(20�ڳ���): ");
            scanf("%s", list[count].title);
            printf("����Ϸ��� å�� ���ڸ� �Է��ϼ���(20�ڳ���): ");
            scanf("%s", list[count].author);
            printf("����Ϸ��� å�� ���ǻ縦 �Է��ϼ���(20�ڳ���): ");
            scanf("%s", list[count].pub);
            printf("����Ϸ��� å�� ������ �Է��ϼ���(���� �Է�): ");
            scanf("%d", &list[count].price);

            list[count].borrowed = 0;
            count++;                                                                   //å ����� �� ���� count���� +1
            while (1) {
                printf("�� �Է��� å�� ������ '1', ������ '2'�� �Է��ϼ���.\n");
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
                    printf("�߸� �Է��ϼ̽��ϴ�.\n");
                }
            }
        }
        else
        {
            printf("�� �̻� å�� ����� �� �����ϴ�.\n");                //å�� 100�� �̻� �ԷµǾ��� ��� ���� �޼��� ǥ��
        }

    } loop: key2;
}

void listBooks()
{
    if (count == 0)
    {
        printf("��ϵ� å�� �����ϴ�.\n");                                 //��ϵ� å�� ���� ��� ���� �޼��� ǥ��
    }
    else                                                                               //��ϵ� å�� 1�� �̻��� ���
    {
        printf("��ϵ� å ���: ");
        for (i = 0; i < count; i++) {
            printBook();
        }
    }
}

void searchBook()
{
    char search[100];
    printf("�˻��Ϸ��� å�� ������ �Է��ϼ���: ");
    scanf("%s", search);                                        //�迭�̸��� �ּ�(&�Ⱥ���!)

    for (i = 0; i < count; i++)
    {
        if (strcmp(search, list[i].title) == 0)
        {
            printf("�˻� ���: ");
            printBook();
            found = 1;                                              //�˻� ����� ���� ��� found ������ 1�� ���� => �˻� ��� ���
        }
    }

    if (found == 0)
    {
        printf("�˻� ����� �����ϴ�.\n");                //�˻� ����� ���� ��� found�� 0�� ���� => �˻� ��� ���� ���
    }
}

void printBook()
{
        printf("%d. %s %s %s %d�� �Դϴ�.\n",
            list[i].num, list[i].title, list[i].author, list[i].pub, list[i].price);  
}

void borrowBook()
{
    int book_num;

    printf("���� ������ ���� ����Դϴ�.\n");
    for (i = 0; i < count; i++) {
        if (list[i].borrowed == 0)
        {
            printBook();
        }
    }
    printf("\n");
    
    printf("�����Ϸ��� ������ ��ȣ�� �Է��ϼ���\n");
    printf("���� ��ȣ: \n");
    scanf("%d", &book_num);

    printf("�����Ϸ��� ������ ������ Ȯ���ϼ���.\n");

    for (i = 0; i < count; i++)
    {
        if (book_num == list[i].num)
        {
            printf("�˻� ���: ");
            printBook();

            if (list[i].borrowed == 1)
            {
                printf("���� ���� ���� �����Դϴ�.\n");
            }
            else
            {
                printf("���������� ����Ǿ����ϴ�\n");
                list[i].borrowed = 1;
            }

            return; // �Լ� ����
        }
    }

    printf("�˻� ����� �����ϴ�.\n");
}

void returnBook()
{
    int book_num;
    printf("�ݳ� ������ ���� ����Դϴ�.\n");
    for (i = 0; i < count; i++) {
        if (list[i].borrowed == 1)
        {
            printBook();
        }
    }
    printf("\n");
    printf("�ݳ��Ϸ��� ������ ��ȣ�� �Է��ϼ���\n");
    printf("���� ��ȣ: \n");
    scanf("%d", &book_num);

    printf("�ݳ��Ϸ��� ������ ������ Ȯ���ϼ���.\n");

    for (i = 0; i < count; i++)
    {
        if (book_num == list[i].num)
        {
            printf("�˻� ���: ");
            printBook();

            if (list[i].borrowed == 1)
            {
                printf("���������� �ݳ��Ǿ����ϴ�.\n");
                list[i].borrowed = 0;
            }
            else
            {
                printf("�װ� ������ ���� ���µ���?\n");               
            }

            return; // �Լ� ����
        }
    }

    printf("�˻� ����� �����ϴ�.\n");
}