#pragma once
#include <stdio.h>

//������ ���������� ��������� ��� �������� ������ ������ � ���������.
struct ancetastud
{
    char fio[30];  //���������� ������ ��� �������
    int nomerGrup; //���������� ������ ����� ������ �������
    int nomerStud; //���������� ������ ����� ������������� �������
    int reiting;   //���������� ������ ������� �������
    int type;      //���������� ������ ����� ��������� ����������
    union          //����������� ������ ���������� ��������� ������� ����������� � ����������� �� �������� ��������
    {
        struct     //��������� ������ ������ ��� �������� ���������
        {
            char dopstependia[30];
            int razmer;
        } otl;
        struct     //��������� ������ ������ ��� �������� ��������� 
        {
            char stependia[30];
            int razmer;
        } hor;
        struct     //��������� ������ ������ ��� �������� ��������� 
        {
            char stependia[30];
        } tro;
        struct     //��������� ������ ������ ��� �������� ���������
        {
            char adres[30];
            char telephone[30];
        } dvo;
    }uch;

};

ancetastud initializationstud(ancetastud a) // ������� ������������� ��� ���������
{
    strcpy(a.fio, "");
    a.nomerGrup = 0;
    a.nomerStud = 0;
    a.reiting = 0;
    a.type = 0;
    return a;
}

ancetastud inputstud(ancetastud a) //���� - ���� ������ � ���������
{
    printf(" ���: "); gets_s(a.fio);
    do {
        printf(" ����� ������:(������� � ������� 5 ���� '22091')\n");
        while (scanf("%d", &a.nomerGrup) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� �� ��� �������� � ������� : ");
        }
    } while (a.nomerGrup < 10000 || a.nomerGrup >99999);

    do {
        printf(" ����� �������������(������� � ������� 7 ���� '2111851')\n");
        while (scanf("%d", &a.nomerStud) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while (a.nomerStud < 1000000 || a.nomerStud >9999999);

    do {
        printf(" ������� ��������:(�� 0 �� 100) ");
        while (scanf("%d", &a.reiting) != 1) //�������� ����� ���� ������������  ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while ((a.reiting < 0) || (a.reiting > 100));

    if (a.reiting >= 75)
    {

        a.type = 1;
        strcpy(a.uch.otl.dopstependia, "������� �������� ��������� ");
        printf("������� ������ �������������� ���������\n");
        scanf("%d", &a.uch.otl.razmer);
    }
    else
    {

        if (a.reiting >= 50)
        {
            a.type = 2;
            strcpy(a.uch.hor.stependia, "�������  �������� ��������� ");
            printf("������� ������ ������� ���������\n");
            scanf("%d", &a.uch.hor.razmer);
        }
        else
        {
            if (a.reiting >= 25)
            {
                a.type = 3;
                strcpy(a.uch.hor.stependia, "������� �� �������� ��������� ");

            }
            else
            {
                a.type = 4;
                while (getchar() != '\n');
                printf("������� �������� ����� ��������\n");
                gets_s(a.uch.dvo.adres);
                printf("������� Enter\n");
                while (getchar() != '\n');
                printf("������� ������� ��������\n");
                gets_s(a.uch.dvo.telephone);
                printf("������� Enter\n");


            };
        };


    }
    printf("\n");
    while (getchar() != '\n');
    return a;
}

ancetastud outputstud(ancetastud a) //���� - ����� ������ � ���������
{
    printf(" %s ", a.fio);
    printf(" %d ", a.nomerGrup);
    printf(" %d ", a.nomerStud);
    printf(" %d ", a.reiting);
    if (a.type == 1)
    {
        printf(" %s ", a.uch.otl.dopstependia);
        printf(" %d \n ", a.uch.otl.razmer);
    }
    if (a.type == 2)
    {
        printf(" %s ", a.uch.hor.stependia);
        printf(" %d \n ", a.uch.hor.razmer);
    }
    if (a.type == 3)
    {
        printf(" %s \n ", a.uch.tro.stependia);
    }
    if (a.type == 4)
    {
        printf(" %s ", a.uch.dvo.adres);
        printf(" %s \n ", a.uch.dvo.telephone);
    }
    return a;
}

int searchbynamestud(ancetastud a, ancetastud c) //���� - ����� �� ����� ����� ���������
{
    int f1 = 0;
    
    
        if (strcmp(c.fio, a.fio) == 0)
        {
            printf(" %s ", a.fio);
            printf(" %d ", a.nomerGrup);
            printf(" %d ", a.nomerStud);
            printf(" %d ", a.reiting);
            if (a.type == 1)
            {
                printf(" %s ", a.uch.otl.dopstependia);
                printf(" %d \n ", a.uch.otl.razmer);
            }
            if (a.type == 2)
            {
                printf(" %s ", a.uch.hor.stependia);
                printf(" %d \n ", a.uch.hor.razmer);
            }
            if (a.type == 3)
            {
                printf(" %s \n ", a.uch.tro.stependia);
            }
            if (a.type == 4)
            {
                printf(" %s ", a.uch.dvo.adres);
                printf(" %s \n ", a.uch.dvo.telephone);
            }
            f1 = 1;
        }
        return f1;
}
