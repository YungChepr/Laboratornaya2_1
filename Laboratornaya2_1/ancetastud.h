#pragma once
#include <stdio.h>

const int N = 30;

struct otlichnik    //��������� ������ ������ ��� �������� ���������
{
    char dopstependia[30];
    int razmer;
};
struct horoshist    //��������� ������ ������ ��� �������� ��������� 
{
    char stependia[30];
    int razmer;
};
struct troechnik    //��������� ������ ������ ��� �������� ��������� 
{
    char stependia[30];
};
struct dvoechnik    //��������� ������ ������ ��� �������� ���������
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
//������ ���������� ��������� ��� �������� ������ ������ � ���������.
struct ancetastud
{
    char fio[30];  //���������� ������ ��� �������
    int nomerGrup; //���������� ������ ����� ������ �������
    int nomerStud; //���������� ������ ����� ������������� �������
    int reiting;   //���������� ������ ������� �������
    typchik type;      //���������� ������ ����� ��������� ����������
    union          //����������� ������ ���������� ��������� ������� ����������� � ����������� �� �������� ��������
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