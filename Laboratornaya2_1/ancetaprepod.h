#pragma once
#include <stdio.h>

//������ ���������� ��������� ��� �������� ������ ������ � ��������������.
struct ancetaprepod
{
    char fio[20];    //���������� ������ ��� �������������
    char fakul[20];  //���������� ������ �������� ����������
    char predmet[30];//���������� ������ ������� �������������
    int auditor;     //���������� ������ ����� ���������
    int stage;       //���������� ������ ���� �������������
    int type;        //���������� ������ ����� ��������� ����������
    union
    {
        struct    //��������� ������ ������ ��� ����������
        {
            char zvanie[30];
            int zarplata;
            int doctorskaya;

        } dol;
        struct    //��������� ������ ������ ��� �������
        {
            char zvanie[30];
            int zarplata;
            int monograthiya;

        } sre;
        struct    //��������� ������ ������ ��� �������� �������������
        {
            char zvanie[30];
            int zarplata;
            int kolgrup;

        } kor;
        struct    //��������� ������ ������ ��� �������������
        {
            char zvanie[30];
            int zarplata;
            int kolchasov;

        } ochkor;
    }pre;

};

ancetaprepod initializationprepod(ancetaprepod b)
{
    strcpy((b).fio, "");
    strcpy((b).fakul, "");
    strcpy((b).predmet, "");
    b.auditor = 0;
    b.stage = 0;
    b.type = 0;
    return b;
}

/*ancetaprepod initializationprepod2(char f[30], char fa[30], char pre[30], int aur, int sta, int ty)
{
    strcpy((b).fio, f);
    strcpy((b).fakul, fa);
    strcpy((b).predmet, pre);
    b.auditor = aur;
    b.stage = sta;
    b.type = ty;
    return b;
} */

ancetaprepod inputprepod(ancetaprepod b)
{
    printf(" ���: "); gets_s(b.fio);
    printf(" ���������: "); gets_s(b.fakul);
    printf(" �������: "); gets_s(b.predmet);
    do {
        printf(" ����� ���������:(������� � ������� 3 ���� '421')\n");
        while (scanf("%d", &b.auditor) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� �� ��� �������� � ������� : ");
        }
    } while ((b.auditor < 100) || (b.auditor > 999));

    do {
        printf(" ���� ������:(������� � ������� 2 ���� '39')\n");
        while (scanf("%d", &b.stage) != 1) //�������� ����� ���� ������������ ������ �� �����
        {
            while (getchar() != '\n');
            printf("������. ������� ����� �� ��� �������� � ������� : ");
        }
    } while ((b.stage < 1) || (b.stage > 99));


    if (b.stage >= 30)
    {
        b.type = 1;
        strcpy(b.pre.dol.zvanie, "��������� ");
        printf("������� ������ ��������\n");
        scanf("%d", &b.pre.dol.zarplata);
        do {
            printf(" ���� �� � ���������� ���������� ������ 1 - ��, 2 - ���:)\n");
            while (scanf("%d", &b.pre.dol.doctorskaya) != 1) //�������� ����� ���� ������������ ������ �� �����
            {
                while (getchar() != '\n');
                printf("������. ������� ����� �� ��� �������� � ������� : ");
            }
        } while ((b.pre.dol.doctorskaya < 1) || (b.pre.dol.doctorskaya > 2));
    }
    else
    {

        if (b.stage >= 20)
        {
            b.type = 2;
            strcpy(b.pre.sre.zvanie, "������ ");
            printf("������� ������ ��������\n");
            scanf("%d", &b.pre.sre.zarplata);
            do {
                printf(" ���� �� � ������� ���������� 1 - ��, 2 - ���:)\n");
                while (scanf("%d", &b.pre.sre.monograthiya) != 1) //�������� ����� ���� ������������ ������ �� �����
                {
                    while (getchar() != '\n');
                    printf("������. ������� ����� �� ��� �������� � ������� : ");
                }
            } while ((b.pre.sre.monograthiya < 1) || (b.pre.sre.monograthiya > 2));
        }
        else
            if (b.stage >= 10)
            {
                b.type = 3;
                strcpy(b.pre.kor.zvanie, "������� ������������� ");
                printf("������� ������ ��������\n");
                scanf("%d", &b.pre.kor.zarplata);
                do {
                    printf(" ������� ���������� �����:(�� ������ 10)\n");
                    while (scanf("%d", &b.pre.kor.kolgrup) != 1) //�������� ����� ���� ������������ ������ �� �����
                    {
                        while (getchar() != '\n');
                        printf("������. ������� ����� �� ��� �������� � ������� : ");
                    }
                } while ((b.pre.kor.kolgrup < 0) || (b.pre.kor.kolgrup > 11));
            }
            else
            {
                b.type = 4;
                strcpy(b.pre.ochkor.zvanie, "������������� ");
                printf("������� ������ ��������\n");
                scanf("%d", &b.pre.ochkor.zarplata);
                do {
                    printf(" ������� ���������� �����:(�� ������ 40)\n");
                    while (scanf("%d", &b.pre.ochkor.kolchasov) != 1) //�������� ����� ���� ������������ ������ �� �����
                    {
                        while (getchar() != '\n');
                        printf("������. ������� ����� �� ��� �������� � ������� : ");
                    }
                } while ((b.pre.ochkor.kolchasov < 0) || (b.pre.ochkor.kolchasov > 40));
            };


    }
    printf("\n");
    while (getchar() != '\n');
    return b;
}

ancetaprepod outputprepod(ancetaprepod b)
{
    printf(" %s ", b.fio);
    printf(" %s ", b.fakul);
    printf(" %s ", b.predmet);
    printf(" %d ", b.auditor);
    printf(" %d ", b.stage);
    if (b.type == 1)
    {
        printf(" %s  ", b.pre.dol.zvanie);
        printf(" %d  ", b.pre.dol.zarplata);
        if (b.pre.dol.doctorskaya == 1)
        {
            printf(" � ���������� ���� ���������� ������ \n  ");
        }
        else
        {
            printf(" � ���������� ��� ���������� ������ \n  ");

        }
    }
    if (b.type == 2)
    {
        printf(" %s ", b.pre.sre.zvanie);
        printf(" %d ", b.pre.sre.zarplata);
        if (b.pre.sre.monograthiya == 1)
        {
            printf(" � ������� ���� ���������� \n  ");
        }
        else
        {
            printf(" � ������� ��� ���������� \n  ");

        }
    }
    if (b.type == 3)
    {
        printf(" %s ", b.pre.kor.zvanie);
        printf(" %d ", b.pre.kor.zarplata);
        printf(" ���������� �����: %d \n ", b.pre.kor.kolgrup);
    }
    if (b.type == 4)
    {
        printf(" %s ", b.pre.ochkor.zvanie);
        printf(" %d ", b.pre.ochkor.zarplata);
        printf(" ���������� �����: %d \n ", b.pre.ochkor.kolchasov);
    }
    return b;
}

int searchbynameprepod(ancetaprepod b, ancetaprepod d)
{
    int f2 = 0;
    
        if (strcmp(d.fio, b.fio) == 0)
        {
            printf(" %s ", b.fio);
            printf(" %s ", b.fakul);
            printf(" %s ", b.predmet);
            printf(" %d ", b.auditor);
            printf(" %d ", b.stage);
            if (b.type == 1)
            {
                printf(" %s  ", b.pre.dol.zvanie);
                printf(" %d  ", b.pre.dol.zarplata);
                if (b.pre.dol.doctorskaya == 1)
                {
                    printf(" � ���������� ���� ���������� ������ \n  ");
                }
                else
                {
                    printf(" � ���������� ��� ���������� ������ \n  ");

                }
            }
            if (b.type == 2)
            {
                printf(" %s ", b.pre.sre.zvanie);
                printf(" %d ", b.pre.sre.zarplata);
                if (b.pre.sre.monograthiya == 1)
                {
                    printf(" � ������� ���� ���������� \n  ");
                }
                else
                {
                    printf(" � ������� ��� ���������� \n  ");

                }
            }
            if (b.type == 3)
            {
                printf(" %s ",b.pre.kor.zvanie);
                printf(" %d ", b.pre.kor.zarplata);
                printf(" ���������� �����: %d \n ", b.pre.kor.kolgrup);
            }
            if (b.type == 4)
            {
                printf(" %s ", b.pre.ochkor.zvanie);
                printf(" %d ", b.pre.ochkor.zarplata);
                printf(" ���������� �����: %d \n ", b.pre.ochkor.kolchasov);
            }
            f2 = 1;
        }

    return f2;
}