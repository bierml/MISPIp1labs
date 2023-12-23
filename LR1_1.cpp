//Винокуров,А-12-19,ЛР 1(задание 1)
#include <iostream>
#include <math.h>
#include <windows.h>
using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");
    float a,b,c;
    do
    {
        cout << "Введите длительность горения красного сигнала: "; 
        cin >> a; //ввод данных
        cout << "Введите длительность горения желтого сигнала: ";
        cin >> b; //ввод данных
        cout << "Введите длительность горения зеленого сигнала: ";
        cin >> c; //ввод данных
        if(a>0 && b>0 && c>0) //проверка правильности ввода
        {
          cout << "Количество информации о красном сигнале: " << ceil(logf(float(a+b+c)/(a))/logf(2)) << endl; /*вывод количества информации о красном сигнале*/
          cout << "Количество информации о желтом сигнале: " << ceil(logf(float(a+b+c)/(b))/logf(2)) << endl; /*вывод количества информации о желтом сигнале*/
          cout << "Количество информации о любом из трех сигналов: " << ceil((float(a)/(a+b+c))*logf(float(a+b+c)/(a))/logf(2)+(float(b)/(a+b+c))*logf(float(a+b+c)/(b))/logf(2)+(float(c)/(a+b+c))*logf(float(a+b+c)/(c))/logf(2)); //расчет результата и вывод 
        }
        else
         cout << "Неверный набор входных данных!" << endl; //вывод в случае ошибки
    }while(!(a>0 && b>0 && c>0));
    return 0;
}
