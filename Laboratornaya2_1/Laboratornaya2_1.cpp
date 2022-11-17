// Laboratornaya2_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <clocale>
#include <locale.h>

//Константа хранит количество элементов массива преподователей
const int N = 30;

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

//}spisokprepod[30]; //Массив в котором будут хранится данные преподователей
} *spisokprepod; //Указатель на массив в котором будут хранится данные преподователей


int f1()
{
    //Блок - ввод данных о студентах
    int n,//Количество студентов
        i;//Индекс массива студентов
        

    do {
        printf("\n Введите количество студентов n (n<20): ");
        while (scanf("%d", &n) != 1) //Проверка ввода если пользователь введет введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
        while (getchar() != '\n');
    } while (n < 1 || n>20);
    for (i = 0; i < n; i++)
    {
        printf("Студент %d \n", (i + 1));
        printf(" ФИО: "); gets_s(spisokstud[i].fio);

        do {
        printf(" Номер группы:(Введите в формате 5 цифр '22091')\n"); 
        while (scanf("%d", &spisokstud[i].nomerGrup) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
        } while (spisokstud[i].nomerGrup < 10000 || spisokstud[i].nomerGrup >99999);

        do {
        printf(" Номер студенческого(Введите в формате 7 цифр '2111851')\n"); 
        while (scanf("%d", &spisokstud[i].nomerStud) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число как показано в примере: ");
        }
        } while (spisokstud[i].nomerStud < 1000000 || spisokstud[i].nomerStud >9999999);

        do {
            printf(" Рейтинг студента:(от 0 до 100) ");
            while (scanf("%d", &spisokstud[i].reiting) != 1) //Проверка ввода если пользователь  введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число как показано в примере: ");
            }
        } while ((spisokstud[i].reiting < 0) || (spisokstud[i].reiting > 100));

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
    

    return n;
}

int f2()
{
    //Блок - ввод данных о преподователях
    int m,//Количество преподователей
        j;//Индекс массива преподователей
       

    do {
        printf("\n Введите количество преподователей m (m<20): ");
        while (scanf("%d", &m) != 1) //Проверка ввода если пользователь введет не цифру
        {
            while (getchar() != '\n');
            printf("Ошибка. Введите число от как показано в примере : ");
        }
       
    } while (m < 1 || m>20);
    for (j = 0; j < m; j++)
    {
        printf("Преподователь %d \n", (j + 1)); while (getchar() != '\n');
        printf(" ФИО: "); gets_s((*(spisokprepod+j)).fio);
        printf(" Факультет: "); gets_s((*(spisokprepod + j)).fakul);
        printf(" Предмет: "); gets_s((*(spisokprepod + j)).predmet);
        do {
            printf(" Номер аудитории:(Введите в формате 3 цифр '421')\n");
            while (scanf("%d", &(*(spisokprepod + j)).auditor) != 1) //Проверка ввода если пользователь введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число от как показано в примере : ");
            }
        } while (((*(spisokprepod + j)).auditor < 100) || ((*(spisokprepod + j)).auditor > 999));

        do {
            printf(" Стаж работы:(Введите в формате 2 цифр '39')\n");
            while (scanf("%d", &(*(spisokprepod + j)).stage) != 1) //Проверка ввода если пользователь введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число от как показано в примере : ");
            }
        } while (((*(spisokprepod + j)).stage < 1) || ((*(spisokprepod + j)).stage > 99));
      

        if ((*(spisokprepod + j)).stage >= 30)
        {
            (*(spisokprepod + j)).type = 1;
            strcpy((*(spisokprepod + j)).pre.dol.zvanie, "Профессор ");
            printf("Введите размер зарплаты\n");
            scanf("%d", &(*(spisokprepod + j)).pre.dol.zarplata);
            do {
                printf(" Есть ли у профессора докторская работа 1 - да, 2 - нет:)\n");
                while (scanf("%d", &(*(spisokprepod + j)).pre.dol.doctorskaya) != 1) //Проверка ввода если пользователь введет не цифру
                {
                    while (getchar() != '\n');
                    printf("Ошибка. Введите число от как показано в примере : ");
                }
            } while (((*(spisokprepod + j)).pre.dol.doctorskaya < 1) || ((*(spisokprepod + j)).pre.dol.doctorskaya > 2));
        }
        else
        {

            if ((*(spisokprepod + j)).stage >= 20)
            {
                (*(spisokprepod + j)).type = 2;
                strcpy((*(spisokprepod + j)).pre.sre.zvanie, "Доцент ");
                printf("Введите размер зарплаты\n");
                scanf("%d", &(*(spisokprepod + j)).pre.sre.zarplata); 
                do {
                    printf(" Есть ли у доцента монография 1 - да, 2 - нет:)\n");
                    while (scanf("%d", &(*(spisokprepod + j)).pre.sre.monograthiya) != 1) //Проверка ввода если пользователь введет не цифру
                    {
                        while (getchar() != '\n');
                        printf("Ошибка. Введите число от как показано в примере : ");
                    }
                } while (((*(spisokprepod + j)).pre.sre.monograthiya < 1) || ((*(spisokprepod + j)).pre.sre.monograthiya > 2));
            }
            else
                if ((*(spisokprepod + j)).stage >= 10)
                {
                    (*(spisokprepod + j)).type = 3;
                    strcpy((*(spisokprepod + j)).pre.kor.zvanie, "Старший Преподователь ");
                    printf("Введите размер зарплаты\n");
                    scanf("%d", &(*(spisokprepod + j)).pre.kor.zarplata);
                    do {
                        printf(" Введите количество групп:(Не больше 10)\n");
                        while (scanf("%d", &(*(spisokprepod + j)).pre.kor.kolgrup) != 1) //Проверка ввода если пользователь введет не цифру
                        {
                            while (getchar() != '\n');
                            printf("Ошибка. Введите число от как показано в примере : ");
                        }
                    } while (((*(spisokprepod + j)).pre.kor.kolgrup < 0) || ((*(spisokprepod + j)).pre.kor.kolgrup > 11));
                }
                else
                {
                    (*(spisokprepod + j)).type = 4;
                    strcpy((*(spisokprepod + j)).pre.ochkor.zvanie, "Преподователь ");
                    printf("Введите размер зарплаты\n");
                    scanf("%d", &(*(spisokprepod + j)).pre.ochkor.zarplata);
                    do {
                        printf(" Введите количество часов:(Не больше 40)\n");
                        while (scanf("%d", &(*(spisokprepod + j)).pre.ochkor.kolchasov) != 1) //Проверка ввода если пользователь введет не цифру
                        {
                            while (getchar() != '\n');
                            printf("Ошибка. Введите число от как показано в примере : ");
                        }
                    } while (((*(spisokprepod + j)).pre.ochkor.kolchasov < 0) || ((*(spisokprepod + j)).pre.ochkor.kolchasov > 40));
                };


        }
        printf("\n");
        while (getchar() != '\n');
    }

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
            printf(" %s ", spisokstud[i].uch.otl.dopstependia);
            printf(" %d \n ", spisokstud[i].uch.otl.razmer);
        }
        if (spisokstud[i].type == 2)
        {
            printf(" %s ", spisokstud[i].uch.hor.stependia);
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
        printf(" %s ", (*(spisokprepod + j)).fio);
        printf(" %s ", (*(spisokprepod + j)).fakul);
        printf(" %s ", (*(spisokprepod + j)).predmet);
        printf(" %d ", (*(spisokprepod + j)).auditor);
        printf(" %d ", (*(spisokprepod + j)).stage);
        if ((*(spisokprepod + j)).type == 1)
        {
            printf(" %s  ", (*(spisokprepod + j)).pre.dol.zvanie);
            printf(" %d  ", (*(spisokprepod + j)).pre.dol.zarplata);
            if ((*(spisokprepod + j)).pre.dol.doctorskaya == 1)
            {
                printf(" У профессора есть докторская работа \n  ");
            }
            else
            {
                printf(" У профессора нет докторская работы \n  ");

            }
        }
        if ((*(spisokprepod + j)).type == 2)
        {
            printf(" %s ", (*(spisokprepod + j)).pre.sre.zvanie);
            printf(" %d ", (*(spisokprepod + j)).pre.sre.zarplata);
            if ((*(spisokprepod + j)).pre.sre.monograthiya == 1)
            {
                printf(" У Доцента есть монография \n  ");
            }
            else
            {
                printf(" У Доцента нет монографии \n  ");

            }
        }
        if ((*(spisokprepod + j)).type == 3)
        {
            printf(" %s ", (*(spisokprepod + j)).pre.kor.zvanie);
            printf(" %d ", (*(spisokprepod + j)).pre.kor.zarplata);
            printf(" %d \n ", (*(spisokprepod + j)).pre.kor.kolgrup);
        }
        if ((*(spisokprepod + j)).type == 4)
        {
            printf(" %s ", (*(spisokprepod + j)).pre.ochkor.zvanie);
            printf(" %d ", (*(spisokprepod + j)).pre.ochkor.zarplata);
            printf(" %d \n ", (*(spisokprepod + j)).pre.ochkor.kolchasov);
        }
    }
}

void f5(int n)
{
    //Блок - поиск по имени среди студентов
    int i1,f1=0;
    struct ancetastud zap1;
    while (getchar() != '\n');
    printf("Введите ФИО студента\n");
    gets_s(zap1.fio);
    for (i1 = 0; i1 < n; i1++)  //блок проверки запросов
    {

        if (strcmp(zap1.fio, spisokstud[i1].fio) == 0)
        {
            printf(" %s ", spisokstud[i1].fio);
            printf(" %d ", spisokstud[i1].nomerGrup);
            printf(" %d ", spisokstud[i1].nomerStud);
            printf(" %d ", spisokstud[i1].reiting);
            if (spisokstud[i1].type == 11)
            {
                printf(" %s ", spisokstud[i1].uch.otl.dopstependia);
                printf(" %d \n ", spisokstud[i1].uch.otl.razmer);
            }
            if (spisokstud[i1].type == 2)
            {
                printf(" %s ", spisokstud[i1].uch.hor.stependia);
                printf(" %d \n ", spisokstud[i1].uch.hor.razmer);
            }
            if (spisokstud[i1].type == 3)
            {
                printf(" %s \n ", spisokstud[i1].uch.tro.stependia);
            }
            if (spisokstud[i1].type == 4)
            {
                printf(" %s ", spisokstud[i1].uch.dvo.adres);
                printf(" %s \n ", spisokstud[i1].uch.dvo.telephone);
            }
            f1 = 1;
        }
    }
    if (f1 == 0)
    {
        printf("\n По вашему запросу ничего не найдено\n ");
    }
}
void f6(int m)
{
    //Блок - поиск по имени среди преподователей
    int j1,f2=0;
    struct ancetastud zap2;
    while (getchar() != '\n');
    printf("Введите ФИО преподователя\n");
    gets_s(zap2.fio);
    for (j1 = 0; j1 < m; j1++)  //блок проверки запросов
    {

        if (strcmp(zap2.fio, (*(spisokprepod + j1)).fio) == 0)
        {
            printf(" %s ", (*(spisokprepod + j1)).fio);
            printf(" %s ", (*(spisokprepod + j1)).fakul);
            printf(" %s ", (*(spisokprepod + j1)).predmet);
            printf(" %d ", (*(spisokprepod + j1)).auditor);
            printf(" %d ", (*(spisokprepod + j1)).stage);
            if ((*(spisokprepod + j1)).type == 1)
            {
                printf(" %s  ", (*(spisokprepod + j1)).pre.dol.zvanie);
                printf(" %d  ", (*(spisokprepod + j1)).pre.dol.zarplata);
                if ((*(spisokprepod + j1)).pre.dol.doctorskaya == 1)
                {
                    printf(" У профессора есть докторская работа \n  ");
                }
                else
                {
                    printf(" У профессора нет докторская работы \n  ");

                }
            }
            if ((*(spisokprepod + j1)).type == 2)
            {
                printf(" %s ", (*(spisokprepod + j1)).pre.sre.zvanie);
                printf(" %d ", (*(spisokprepod + j1)).pre.sre.zarplata);
                if ((*(spisokprepod + j1)).pre.sre.monograthiya == 1)
                {
                    printf(" У Доцента есть монография \n  ");
                }
                else
                {
                    printf(" У Доцента нет монографии \n  ");

                }
            }
            if ((*(spisokprepod + j1)).type == 3)
            {
                printf(" %s ", (*(spisokprepod + j1)).pre.kor.zvanie);
                printf(" %d ", (*(spisokprepod + j1)).pre.kor.zarplata);
                printf(" %d \n ", (*(spisokprepod + j1)).pre.kor.kolgrup);
            }
            if ((*(spisokprepod + j1)).type == 4)
            {
                printf(" %s ", (*(spisokprepod + j1)).pre.ochkor.zvanie);
                printf(" %d ", (*(spisokprepod + j1)).pre.ochkor.zarplata);
                printf(" %d \n ", (*(spisokprepod + j1)).pre.ochkor.kolchasov);
            }
            f2 = 1;
        }
    }
    if(f2==0)
    {
    printf("\n По вашему запросу ничего не найдено\n ");
    }
}
int main()
{
    setlocale(LC_ALL, "RUS");
    int a, //Переменная отвечающая за выбор строчки в меню
        n=0,//Количество студентов
        m=0;//Количество преподователей
        
    //Выделяю память для массива преподователей
    spisokprepod = (struct ancetaprepod*)malloc(sizeof(struct ancetaprepod)*N);

    do {
        do {
            printf("Выберите действие в меню\n");
            printf(" 1 - Ввод данных о студентах\n");
            printf(" 2 - Ввод данных о преподователях \n");
            printf(" 3 - Вывод данных о студентах\n");
            printf(" 4 - Вывод данных о преподователях\n");
            printf(" 5 - Поиск по имени среди студентов\n");
            printf(" 6 - Поиск по имени среди преподователей\n");
            printf(" 7 - Выход из системы\n");
            while (scanf("%d", &a) != 1) //Проверка ввода если пользователь  введет не цифру
            {
                while (getchar() != '\n');
                printf("Ошибка. Введите число от 1 до 7 включительно: ");
            }
        } while ((a < 1) || (a > 7));

        if (a == 1)
        {
            printf("Ввод данных о студентах\n");
            n=f1();
        }
        if (a == 2)
        {
            printf("Ввод данных о преподователях\n");
            m=f2();
        }
        if (a == 3)
        {
            if (n != 0) 
            {
                printf("Вывод данных о студентах\n");
                f3(n);
            }
            else
            {
                printf("Сначала введите данные хотя бы об одном студенте\n");
            }
        }
        if (a == 4)
        {
            if (m != 0)
            {
                printf("Вывод данных о преплдователях\n");
                f4(m);
            }
            else
            {
                printf("Сначала введите данные хотя бы об одном преподователе\n");
            }
        }
        if (a == 5)
        {
            if (n != 0)
            {
            printf("Поиск по имени среди студентов\n");
            f5(n);
            }
            else
            {
                printf("Сначала введите данные хотя бы об одном студенте\n");
            }
        }
        if (a == 6)
        {
            if (m != 0)
            {
                printf("Поиск по имени среди преподователей\n");
                f6(m);
            }
            else
            {
                printf("Сначала введите данные хотя бы об одном преподователе\n");
            }
        }

    } while (a != 7);
    printf("\nВы вышли из системы\n");

    free(spisokprepod); //Очищаю память динамического массива структур
    
  

    
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
