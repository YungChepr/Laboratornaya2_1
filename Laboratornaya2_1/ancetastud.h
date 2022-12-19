#pragma once
#include <stdio.h>

const int N = 30;

struct otlichnik    //Структура хранит данные для студента отличника
{
    char dopstependia[30];
    int razmer;
};
struct horoshist    //Структура хранит данные для студента хорошиста 
{
    char stependia[30];
    int razmer;
};
struct troechnik    //Структура хранит данные для студента троечника 
{
    char stependia[30];
};
struct dvoechnik    //Структура хранит данные для студента двоечника
{
    char adres[30];
    char telephone[30];
};
enum typchik
{
    OTL,
    HOR,
    TRO,
    DVO
};
//Задаем переменную структуру для создания анкеты данных о студентах.
struct ancetastud
{
    char fio[30];  //Переменная хранит имя студнта
    int nomerGrup; //Переменная хранит номер группы студнта
    int nomerStud; //Переменная хранит номер студенческого студнта
    int reiting;   //Переменная хранит рейтинг студнта
    typchik type;      //Переменная хранит метку активного компонента
    union          //Объединение хранит переменные компонент который различается в зависимости от рейтинга студента
    {
        otlichnik otl;
        horoshist hor;
        troechnik tro;
        dvoechnik dvo;
    }uch;
};

void initializationstud1(ancetastud* a, char f[30], int ng, int ns, int r, typchik t);
void inputstud1(ancetastud*  a);
void outputstud1(ancetastud a);
int searchbynamestud1(ancetastud spisokstud[N], char[N]);
int searchbyreiting1(ancetastud spisokstud[N], int d);