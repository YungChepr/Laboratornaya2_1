#pragma once
#include <stdio.h>

//Задаем переменную структуру для создания анкеты данных о студентах.
struct ancetastud
{
    char fio[30];  //Переменная хранит имя студнта
    int nomerGrup; //Переменная хранит номер группы студнта
    int nomerStud; //Переменная хранит номер студенческого студнта
    int reiting;   //Переменная хранит рейтинг студнта
    int type;      //Переменная хранит метку активного компонента
    union          //Объединение хранит переменные компонент который различается в зависимости от рейтинга студента
    {
        struct     //Структура хранит данные для студента отличника
        {
            char dopstependia[30];
            int razmer;
        } otl;
        struct     //Структура хранит данные для студента хорошиста 
        {
            char stependia[30];
            int razmer;
        } hor;
        struct     //Структура хранит данные для студента троечника 
        {
            char stependia[30];
        } tro;
        struct     //Структура хранит данные для студента двоечника
        {
            char adres[30];
            char telephone[30];
        } dvo;
    }uch;

};

ancetastud initializationstud(ancetastud a) // Функция инициализации для студентов
{
    strcpy(a.fio, "");
    a.nomerGrup = 0;
    a.nomerStud = 0;
    a.reiting = 0;
    a.type = 0;
    return a;
}

ancetastud inputstud(ancetastud a) //Блок - ввод данных о студентах
{
    printf(" ФИО: "); gets_s(a.fio);
    do {
        printf(" Номер группы:(Введите в формате 5 цифр '22091')\n");
        while (scanf("%d", &a.nomerGrup) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
    } while (a.nomerGrup < 10000 || a.nomerGrup >99999);

    do {
        printf(" Номер студенческого(Введите в формате 7 цифр '2111851')\n");
        while (scanf("%d", &a.nomerStud) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while (a.nomerStud < 1000000 || a.nomerStud >9999999);

    do {
        printf(" Рейтинг студента:(от 0 до 100) ");
        while (scanf("%d", &a.reiting) != 1) //Проверка ввода если пользователь  введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
    } while ((a.reiting < 0) || (a.reiting > 100));

    if (a.reiting >= 75)
    {

        a.type = 1;
        strcpy(a.uch.otl.dopstependia, "Студент получает степендию ");
        printf("Введите размер Дополнительной степендии\n");
        scanf("%d", &a.uch.otl.razmer);
    }
    else
    {

        if (a.reiting >= 50)
        {
            a.type = 2;
            strcpy(a.uch.hor.stependia, "Студент  получает степендию ");
            printf("Введите размер обычной степендии\n");
            scanf("%d", &a.uch.hor.razmer);
        }
        else
        {
            if (a.reiting >= 25)
            {
                a.type = 3;
                strcpy(a.uch.hor.stependia, "Студент НЕ получает степендию ");

            }
            else
            {
                a.type = 4;
                while (getchar() != '\n');
                printf("Введите домашний адрес студента\n");
                gets_s(a.uch.dvo.adres);
                printf("Нажмите Enter\n");
                while (getchar() != '\n');
                printf("Введите телефон студента\n");
                gets_s(a.uch.dvo.telephone);
                printf("Нажмите Enter\n");


            };
        };


    }
    printf("\n");
    while (getchar() != '\n');
    return a;
}

ancetastud outputstud(ancetastud a) //Блок - вывод данных о студентах
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

int searchbynamestud(ancetastud a, ancetastud c) //Блок - поиск по имени среди студентов
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
