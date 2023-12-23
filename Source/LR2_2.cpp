#include <iostream>
#include <windows.h>
using namespace std;
bool chetn(string h)
{
    int g = 0;
    for(int i = 0;h[i]!='\0';i++)
        if(h[i]-'0') g++;
    return (g+1) % 2;
}
bool check(string h)
{
    bool m = true;
    for(int i = 0;h[i]!='\0';i++)
        if(h[i]!='0' && h[i]!='1') m = false;
    return m;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string h;
    char m;
    int l;
    do
    {
        cout<<"Введите слово: ";
        cin >> h;
        if(check(h)) break;
        else
            cout << "Произошла ошибка! Повторите ввод. " << endl;
    }while(true);
    if(chetn(h)) cout<<"Ошибки не найдены!"<<endl;
    else cout<<"Обнаружена ошибка(и)!"<<endl;
    do
    {
        cout<<"Изменить разряд(иначе выход из программы)?Y/N"<<endl;
        cin>>m;
        if(toupper(m)=='N') break;
        if(toupper(m)=='Y')
        {
            cout << "Введите индекс изменяемого разряда: ";
            cin>>l;
            if(l-1>h.length())
            {
                cout << "Неверный ввод!"<<endl;
                continue;
            }
            h[l-1]='0'+(h[l-1]-'0'+1) % 2;
            cout<<"Измененное слово: "<<h<<endl;
            if(chetn(h)) cout<<"Ошибки не найдены!"<<endl;
            else cout<<"Обнаружена ошибка(и)!"<<endl;
        }
        if(toupper(m)!='N' && toupper(m)!='Y')
        {
            cout << "Неверный ввод!"<<endl;
            fflush(stdin);
            continue;
        }
    }while(true);
    return 0;
}
