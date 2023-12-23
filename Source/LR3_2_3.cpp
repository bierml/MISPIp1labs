#include <iostream>
#include <windows.h>
#include <ctype.h>
using namespace std;
string xor_func(string a,string b)
{
   string c = a;
   string d;
   int i = -1;
   while(c[++i]!='\0')
    if(c[i]=='1')
     c[i]=0;
   c[i+1]='\0';
   i = -1;
   while(b[++i]) c[i+a.length()-b.length()]=b[i];
   i = -1;
   d = c;
   while(a[++i]!='\0')
   {
       if(a[i]==c[i])
                 d[i]='0';
       else
           d[i]='1';
   }
   return d;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    string b;
    int f,g;
    char m;
    cout<<"Введите основание системы счисления(a - 2,b - 10): "<<endl;
    cin>>m;
    if(toupper(m)=='A')
    {
            cout<<"Введите кодируемую строку: "<<endl;
            cin>>a;
            cout << "Введите ключ: " << endl;
            cin>>b;
            cout<<"Закодированное слово: "<<xor_func(a,b)<<endl;
            cout<<"Введите декодируемую строку: "<<endl;
            cin>>a;
            cout << "Введите ключ: " << endl;
            cin>>b;
            cout<<"Декодированное слово: "<<xor_func(a,b)<<endl;
    }
    else if(toupper(m)=='B')
    {
            cout<<"Введите кодируемую строку: "<<endl;
            cin>>f;
            cout<<"Введите ключ: " << endl;
            cin>>g;
            int e = f^g;
            cout<<"Закодированное слово: "<<e<<endl;
            cout<<"Введите декодируемую строку: "<<endl;
            cin>>f;
            cout << "Введите ключ: " << endl;
            cin>>g;
            e = f^g;
            cout<<"Декодированное слово: "<<e<<endl;
    }
    else
        cout<<"Ошибка! Неверная команда"<<endl;
    return 0;
}
