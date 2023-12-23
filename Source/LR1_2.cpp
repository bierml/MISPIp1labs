//Винокуров,А-12-19,ЛР 1(задание 2)
#include <iostream>
#include <math.h>
#include <vector>
#include <windows.h>
using namespace std;
void write_binary_code(int a,int b) //функция преобразования слова в двоичный код
{
    int s = a;
    vector<int> f;
    while( s>0 ) //цикл деления числа с остатком и записи остатков в массив
    {
        f.resize(f.size()+1);
        f[f.size()-1] = s % 2;
        s = s / 2;
    }
    for(int i = 0;i<b-int(logf(a)/logf(2))-1;i++) cout<<"0"; /*добавление необходимого количества нулей в начало*/
    for(int i = f.size()-1;i>=0;i--) cout<<f[i]; //вывод двоичного кода числа
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL,"Russian");
    vector<char> v;
    char m;
    cout<<"Введите символы словаря(@ для завершения ввода): "<<endl;
    do
    {
        cin >> m;
        if(m == '@') break; //выход из цикла ввода
        bool g = false;
        for(int i = 0;i<v.size();i++) g = g || v[i] == m; //проверка, вводился ли текущий символ ранее
        if(g) continue; //пропуск встречавшегося ранее символа
        v.resize(v.size()+1);
        v[v.size()-1] = m;
    } while(true);
    int l = ceil(logf(v.size()+1)/logf(2)); //длина кодировки каждого символа
    string h;
    cout<<"Введите слово для кодирования: "<<endl;
    cin>>h;
    cout<<"Закодированное слово: "<<endl;
    for(int i = 0;h[i]!='\0';i++) 
    {
        for(int g = 0;g<=v.size()-1;g++) //поиск символа в словаре и вывод его двоичного кода на экран
        {
            if(v[g]==h[i])
                write_binary_code(g+1,l);
        }
    }
    return 0;
}
