#pragma once
#include <stdio.h>

//Задаем переменную структуру для создания анкеты данных о преподователях.
struct ancetaprepod
{
    char fio[20];    //Переменная хранит имя преподователя
    char fakul[20];  //Переменная хранит название факультета
    char predmet[30];//Переменная хранит предмет преподователя
    int auditor;     //Переменная хранит номер аудитории
    int stage;       //Переменная хранит стаж преподователя
    int type;        //Переменная хранит метку активного компонента
    union
    {
        struct    //Структура хранит данные для профессора
        {
            char zvanie[30];
            int zarplata;
            int doctorskaya;

        } dol;
        struct    //Структура хранит данные для доцента
        {
            char zvanie[30];
            int zarplata;
            int monograthiya;

        } sre;
        struct    //Структура хранит данные для старшего преподователя
        {
            char zvanie[30];
            int zarplata;
            int kolgrup;

        } kor;
        struct    //Структура хранит данные для преподователя
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
    printf(" ФИО: "); gets_s(b.fio);
    printf(" Факультет: "); gets_s(b.fakul);
    printf(" Предмет: "); gets_s(b.predmet);
    do {
        printf(" Номер аудитории:(Введите в формате 3 цифр '421')\n");
        while (scanf("%d", &b.auditor) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
    } while ((b.auditor < 100) || (b.auditor > 999));

    do {
        printf(" Стаж работы:(Введите в формате 2 цифр '39')\n");
        while (scanf("%d", &b.stage) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
    } while ((b.stage < 1) || (b.stage > 99));


    if (b.stage >= 30)
    {
        b.type = 1;
        strcpy(b.pre.dol.zvanie, "Профессор ");
        printf("Введите размер зарплаты\n");
        scanf("%d", &b.pre.dol.zarplata);
        do {
            printf(" Есть ли у профессора докторская работа 1 - да, 2 - нет:)\n");
            while (scanf("%d", &b.pre.dol.doctorskaya) != 1) //Проверка ввода если пользователь введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число от как показано в примере : ");
            }
        } while ((b.pre.dol.doctorskaya < 1) || (b.pre.dol.doctorskaya > 2));
    }
    else
    {

        if (b.stage >= 20)
        {
            b.type = 2;
            strcpy(b.pre.sre.zvanie, "Доцент ");
            printf("Введите размер зарплаты\n");
            scanf("%d", &b.pre.sre.zarplata);
            do {
                printf(" Есть ли у доцента монография 1 - да, 2 - нет:)\n");
                while (scanf("%d", &b.pre.sre.monograthiya) != 1) //Проверка ввода если пользователь введет не цифру
                {
                    while (getchar() != '\n');
                    printf("Ошибка. Введите число от как показано в примере : ");
                }
            } while ((b.pre.sre.monograthiya < 1) || (b.pre.sre.monograthiya > 2));
        }
        else
            if (b.stage >= 10)
            {
                b.type = 3;
                strcpy(b.pre.kor.zvanie, "Старший Преподователь ");
                printf("Введите размер зарплаты\n");
                scanf("%d", &b.pre.kor.zarplata);
                do {
                    printf(" Введите количество групп:(Не больше 10)\n");
                    while (scanf("%d", &b.pre.kor.kolgrup) != 1) //Проверка ввода если пользователь введет не цифру
                    {
                        while (getchar() != '\n');
                        printf("Ошибка. Введите число от как показано в примере : ");
                    }
                } while ((b.pre.kor.kolgrup < 0) || (b.pre.kor.kolgrup > 11));
            }
            else
            {
                b.type = 4;
                strcpy(b.pre.ochkor.zvanie, "Преподователь ");
                printf("Введите размер зарплаты\n");
                scanf("%d", &b.pre.ochkor.zarplata);
                do {
                    printf(" Введите количество часов:(Не больше 40)\n");
                    while (scanf("%d", &b.pre.ochkor.kolchasov) != 1) //Проверка ввода если пользователь введет не цифру
                    {
                        while (getchar() != '\n');
                        printf("Ошибка. Введите число от как показано в примере : ");
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
            printf(" У профессора есть докторская работа \n  ");
        }
        else
        {
            printf(" У профессора нет докторская работы \n  ");

        }
    }
    if (b.type == 2)
    {
        printf(" %s ", b.pre.sre.zvanie);
        printf(" %d ", b.pre.sre.zarplata);
        if (b.pre.sre.monograthiya == 1)
        {
            printf(" У Доцента есть монография \n  ");
        }
        else
        {
            printf(" У Доцента нет монографии \n  ");

        }
    }
    if (b.type == 3)
    {
        printf(" %s ", b.pre.kor.zvanie);
        printf(" %d ", b.pre.kor.zarplata);
        printf(" Количество групп: %d \n ", b.pre.kor.kolgrup);
    }
    if (b.type == 4)
    {
        printf(" %s ", b.pre.ochkor.zvanie);
        printf(" %d ", b.pre.ochkor.zarplata);
        printf(" Количество часов: %d \n ", b.pre.ochkor.kolchasov);
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
                    printf(" У профессора есть докторская работа \n  ");
                }
                else
                {
                    printf(" У профессора нет докторская работы \n  ");

                }
            }
            if (b.type == 2)
            {
                printf(" %s ", b.pre.sre.zvanie);
                printf(" %d ", b.pre.sre.zarplata);
                if (b.pre.sre.monograthiya == 1)
                {
                    printf(" У Доцента есть монография \n  ");
                }
                else
                {
                    printf(" У Доцента нет монографии \n  ");

                }
            }
            if (b.type == 3)
            {
                printf(" %s ",b.pre.kor.zvanie);
                printf(" %d ", b.pre.kor.zarplata);
                printf(" Количество групп: %d \n ", b.pre.kor.kolgrup);
            }
            if (b.type == 4)
            {
                printf(" %s ", b.pre.ochkor.zvanie);
                printf(" %d ", b.pre.ochkor.zarplata);
                printf(" Количество часов: %d \n ", b.pre.ochkor.kolchasov);
            }
            f2 = 1;
        }

    return f2;
}