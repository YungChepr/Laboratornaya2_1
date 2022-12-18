#define _CRT_SECURE_NO_WARNINGS
#include "ancetastud.h"
#include <string.h>
#include <stdio.h>

void initializationstud1(ancetastud* a, char f[30], int ng, int ns, int r, typchik t)
{
    strcpy((*a).fio, "");
    strcpy((*a).fio, f);
    (*a).nomerGrup = ng;
    (*a).nomerStud = ns;
    (*a).reiting = r;
    (*a).type = t;
    //return;
}


void inputstud1(ancetastud*  a) //���� - ���� ������ � ���������
{
    printf(" ���: "); gets_s((*a).fio);
    do {
        printf(" ����� ������:(������� � ������� 5 ���� '22091')\n");
        while (scanf("%d", &(*a).nomerGrup) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� �� ��� �������� � ������� : ");
        }
    } while ((*a).nomerGrup < 10000 || (*a).nomerGrup >99999);

    do {
        printf(" ����� �������������(������� � ������� 7 ���� '2111851')\n");
        while (scanf("%d", &(*a).nomerStud) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while ((*a).nomerStud < 1000000 || (*a).nomerStud >9999999);

    do {
        printf(" ������� ��������:(�� 0 �� 100) ");
        while (scanf("%d", &(*a).reiting) != 1) //�������� ����� ���� ������������  ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� ��� �������� � �������: ");
        }
    } while (((*a).reiting < 0) || ((*a).reiting > 100));

    if ((*a).reiting >= 75)
    {

        (*a).type = typchik::OTL;
        strcpy((*a).uch.otl.dopstependia, "������� �������� ��������� ");
        printf("������� ������ �������������� ���������\n");
        scanf("%d", &(*a).uch.otl.razmer);
    }
    else
    {

        if ((*a).reiting >= 50)
        {
            (*a).type = typchik::HOR;
            strcpy((*a).uch.hor.stependia, "�������  �������� ��������� ");
            printf("������� ������ ������� ���������\n");
            scanf("%d", &(*a).uch.hor.razmer);
        }
        else
        {
            if ((*a).reiting >= 25)
            {
                (*a).type = typchik::TRO;
                strcpy((*a).uch.hor.stependia, "������� �� �������� ��������� ");

            }
            else
            {
                (*a).type = typchik::DVO;
                while (getchar() != '\n');
                printf("������� �������� ����� ��������\n");
                gets_s((*a).uch.dvo.adres);
                printf("������� Enter\n");
                while (getchar() != '\n');
                printf("������� ������� ��������\n");
                gets_s((*a).uch.dvo.telephone);
                printf("������� Enter\n");


            };
        };


    }
    printf("\n");
    while (getchar() != '\n');
    //return a;
}

void outputstud1(ancetastud a) //���� - ����� ������ � ���������
{
    printf(" %s ", a.fio);
    printf(" %d ", a.nomerGrup);
    printf(" %d ", a.nomerStud);
    printf(" %d ", a.reiting);
    if (a.type == OTL)
    {
        printf(" %s ", a.uch.otl.dopstependia);
        printf(" %d \n ", a.uch.otl.razmer);
    }
    if (a.type == HOR)
    {
        printf(" %s ", a.uch.hor.stependia);
        printf(" %d \n ", a.uch.hor.razmer);
    }
    if (a.type == TRO)
    {
        printf(" %s \n ", a.uch.tro.stependia);
    }
    if (a.type == DVO)
    {
        printf(" %s ", a.uch.dvo.adres);
        printf(" %s \n ", a.uch.dvo.telephone);
    }
    //������ return � ��������� ������������ enum
    //return;
}

int searchbynamestud1(ancetastud spisokstud[N], char  c [N]) //���� - ����� �� ����� ����� ���������
{
    int f1 = 0;
    int i;
    for (i = 0; i < N; i++)  //���� �������� ��������
    {
        if (strcmp(c, spisokstud[i].fio) == 0)
        {
            printf(" %s ", spisokstud[i].fio);
            printf(" %d ", spisokstud[i].nomerGrup);
            printf(" %d ", spisokstud[i].nomerStud);
            printf(" %d ", spisokstud[i].reiting);
            if (spisokstud[i].type == OTL)
            {
                printf(" %s ", spisokstud[i].uch.otl.dopstependia);
                printf(" %d \n ", spisokstud[i].uch.otl.razmer);
            }
            if (spisokstud[i].type == HOR)
            {
                printf(" %s ", spisokstud[i].uch.hor.stependia);
                printf(" %d \n ", spisokstud[i].uch.hor.razmer);
            }
            if (spisokstud[i].type == TRO)
            {
                printf(" %s \n ", spisokstud[i].uch.tro.stependia);
            }
            if (spisokstud[i].type == DVO)
            {
                printf(" %s ", spisokstud[i].uch.dvo.adres);
                printf(" %s \n ", spisokstud[i].uch.dvo.telephone);
            }
            f1 = f1 + 1;
        }
    }
    if (f1 == 0)
    {
        printf("\n �� ������ ������� ������ �� �������\n ");
    }

    return f1;
}