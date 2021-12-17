//include "wector.h"
#include <string>
#include <fstream>
#include <iostream>
#include <time.h>
#include <stdio.h>
#include <vector>
#define SIZE 26
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    ifstream fh("letters.txt");
    vector<string> vs;
    string s, a = "*";
    int x = 9;

    //Текущее время и дата
    time_t ltime;
    wchar_t buf[SIZE];
    errno_t err;
    time(&ltime);
    err = _wctime_s(buf, SIZE, &ltime);
    fh >> s;


    cout << "Полные ФИО студента: Бруневич Артемий Александрович\n\nТекущие дата и время:\n"; 
    wprintf_s(buf); 
    cout << "\nФайл letters.txt:\n" << s << "\n\nФайл после преобразований:\n";

    //Сортировка
    for (int i = 0; i < s.length(); i += 10) 
    {
        s.replace(x, 1, a);
        vs.push_back(s.substr(i, 10));
        x += 9;
    }
    for (int i = 0; i < vs.size(); i++)
        cout << vs[i] << endl;
}

