// Laboratornaya2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <locale.h>

//Задаем переменную структуру для создания анкеты данных о студентах.
struct ancetastud
{
    char fio[20];  //Переменная хранит имя студнта
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

}spisokstud[30]; //Массив в котором будут хранится данные студентов


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

        } dol;
        struct    //Структура хранит данные для доцента
        {
            char zvanie[30];
            int zarplata;

        } sre;
        struct    //Структура хранит данные для старшего преподователя
        {
            char zvanie[30];
            int zarplata;

        } kor;
        struct    //Структура хранит данные для преподователя
        {
            char zvanie[30];
            int zarplata;

        } ochkor;
    }pre;

}spisokprepod[30]; //Массив в котором будут хранится данные преподователей


int f1()
{
    //Блок - ввод данных о студентах
    int n,//Количество студентов
        i;//Индекс массива студентов
        

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
                    gets_s(spisokstud[i].uch.dvo.telephone);
                };
            };


        }
        printf("\n");
        while (getchar() != '\n');
    }
    printf("\nКонец цикла");

    return n;
}

int f2()
{
    //Блок - ввод данных о преподователях
    int m,//Количество преподователей
        j;//Индекс массива преподователей
       

    do {
        printf("\n Введите количество преподователей m (m<20): ");
        scanf("%d", &m); while (getchar() != '\n');
    } while (m < 1 || m>20);
    for (j = 0; j < m; j++)
    {
        printf("Преподователь %d \n", (j + 1));
        printf(" ФИО: "); gets_s(spisokprepod[j].fio);
        printf(" Факультет: "); gets_s(spisokprepod[j].fakul);
        printf(" Предмет: "); gets_s(spisokprepod[j].predmet);
        printf(" Номер аудитории: "); scanf("%d", &spisokprepod[j].auditor);
        printf(" Стаж работы: "); scanf("%d", &spisokprepod[j].stage);

        if (spisokprepod[j].stage >= 30)
        {
            spisokprepod[j].type = 1;
            strcpy(spisokprepod[j].pre.dol.zvanie, "Профессор ");
            printf("Введите размер зарплаты\n");
            scanf("%d", &spisokprepod[j].pre.dol.zarplata);
        }
        else
        {

            if (spisokprepod[j].stage >= 20)
            {
                spisokprepod[j].type = 2;
                strcpy(spisokprepod[j].pre.sre.zvanie, "Доцент ");
                printf("Введите размер зарплаты\n");
                scanf("%d", &spisokprepod[j].pre.sre.zarplata);
            }
            else
                if (spisokprepod[j].stage >= 10)
                {
                    spisokprepod[j].type = 3;
                    strcpy(spisokprepod[j].pre.kor.zvanie, "Старший Преподователь ");
                    printf("Введите размер зарплаты\n");
                    scanf("%d", &spisokprepod[j].pre.kor.zarplata);
                }
                else
                {
                    spisokprepod[j].type = 4;
                    strcpy(spisokprepod[j].pre.ochkor.zvanie, "Преподователь ");
                    printf("Введите размер зарплаты\n");
                    scanf("%d", &spisokprepod[j].pre.ochkor.zarplata);
                };


        }
        printf("\n");
        while (getchar() != '\n');
    }
    printf("\nКонец цикла");

    return m;
}

void f3(int n)
{
    //Блок - вывод данных о студентах
    int i;//Индекс массива студентов
    for (i = 0; i < n; i++)
    {
        printf(" %s ", spisokstud[i].fio);
        printf(" %d ", spisokstud[i].nomerGrup);
        printf(" %d ", spisokstud[i].nomerStud);
        printf(" %d ", spisokstud[i].reiting);
        if (spisokstud[i].type == 1)
        {
            printf(" %s  ", spisokstud[i].uch.otl.dopstependia);
            printf(" %d \n ", spisokstud[i].uch.otl.razmer);
        }
        if (spisokstud[i].type == 2)
        {
            printf(" %s \n ", spisokstud[i].uch.hor.stependia);
            printf(" %d \n ", spisokstud[i].uch.hor.razmer);
        }
        if (spisokstud[i].type == 3)
        {
            printf(" %s \n ", spisokstud[i].uch.tro.stependia);
        }
        if (spisokstud[i].type == 4)
        {
            printf(" %s ", spisokstud[i].uch.dvo.adres);
            printf(" %s \n ", spisokstud[i].uch.dvo.telephone);
        }
    }
}

void f4(int m)
{
    //Блок - вывод данных о преподователей
    int j;//Индекс массива преподователей
    for (j = 0; j < m; j++)
    {
        printf(" %s ", spisokprepod[j].fio);
        printf(" %s ", spisokprepod[j].fakul);
        printf(" %s ", spisokprepod[j].predmet);
        printf(" %d ", spisokprepod[j].auditor);
        printf(" %d ", spisokprepod[j].stage);
        if (spisokprepod[j].type == 1)
        {
            printf(" %s  ", spisokprepod[j].pre.dol.zvanie);
            printf(" %d \n ", spisokprepod[j].pre.dol.zarplata);
        }
        if (spisokprepod[j].type == 2)
        {
            printf(" %s \n ", spisokprepod[j].pre.sre.zvanie);
            printf(" %d \n ", spisokprepod[j].pre.sre.zarplata);
        }
        if (spisokprepod[j].type == 3)
        {
            printf(" %s \n ", spisokprepod[j].pre.kor.zvanie);
            printf(" %d \n ", spisokprepod[j].pre.kor.zarplata);
        }
        if (spisokprepod[j].type == 4)
        {
            printf(" %s ", spisokprepod[j].pre.ochkor.zvanie);
            printf(" %d \n ", spisokprepod[j].pre.ochkor.zarplata);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "RUS");

    
  

    
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
