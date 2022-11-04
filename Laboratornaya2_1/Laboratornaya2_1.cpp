// Laboratornaya2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <locale.h>


int main()
{
    setlocale(LC_ALL, "RUS");
    //Задаем переменную структуру для создания анкеты данных о студентах.
    struct ancetastud
    {
        char fio[20]; //Переменная хранит имя студнта
        int nomerGrup; //Переменная хранит номер группы студнта
        int nomerStud; //Переменная хранит номер студенческого студнта
        int reiting; //Переменная хранит рейтинг студнта
        int type; //Переменная хранит метку активного компонента
        union          //Объединение хранит переменные компонент который различается в зависимости от рейтинга студента
        {
            struct     //Структура хранит данные для студента отличника
            {
                char dopstependia[30];
                int razmer;
            } otl;
            struct    //Структура хранит данные для студента хорошиста 
            {
                char stependia[30];
                int razmer;
            } hor;
            struct    //Структура хранит данные для студента троечника 
            {
                char stependia[30];
            } tro;
            struct    //Структура хранит данные для студента двоечника
            {
                char adres[30];
                int telephone[30];
            } dvo;
        }uch;
       
    }spisokstud[30]; //Массив в котором будут хранится данные студентов


    

    int n,//Количество студентов
        i,//Индекс массива студентов
        flag;//Переменная для цикла do

    do {
        printf("\n Введите количество студентов n (n<20): ");
        scanf("%d", &n); while (getchar() != '\n');
    } while (n < 1 || n>20);
    for (i = 0; i < n; i++)
    {
        printf("Студент %d \n", (i + 1));
        printf(" ФИО: "); gets_s(spisokstud[i].fio);
        printf(" Номер группы: "); scanf("%d", &spisokstud[i].nomerGrup);
        printf(" Номер студенческого "); scanf("%d", &spisokstud[i].nomerStud);
        printf(" Рейтинг студента: "); scanf("%d", &spisokstud[i].reiting);

        if (spisokstud[i].reiting >= 75)
        {

            spisokstud[i].type = 1;
            strcpy(spisokstud[i].uch.otl.dopstependia, "Студент получает степендию ");
            printf("Введите размер Дополнительной степендии\n");
            scanf("%d", &spisokstud[i].uch.otl.razmer);
        }
        else
        {

            if (spisokstud[i].reiting >= 50)
            {
                spisokstud[i].type = 2;
                strcpy(spisokstud[i].uch.hor.stependia, "Студент  получает степендию ");
                printf("Введите размер обычной степендии\n");
                scanf("%d", &spisokstud[i].uch.hor.razmer);
            }
            else
            {
                if (spisokstud[i].reiting >= 25)
                {
                    spisokstud[i].type = 3;
                    strcpy(spisokstud[i].uch.hor.stependia, "Студент НЕ получает степендию ");

                }
                else
                {
                    spisokstud[i].type = 4;
                    while (getchar() != '\n');
                    printf("Введите домашний адрес студента\n");
                    gets_s(spisokstud[i].uch.dvo.adres);
                    printf("Нажмите Enter\n");
                    while (getchar() != '\n');
                    printf("Введите телефон студента\n");
                    scanf("%d", &spisokstud[i].uch.dvo.telephone);
                };
            };


        }
        printf("\n");
        while (getchar() != '\n');
    }
    printf("\nКонец цикла");
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
