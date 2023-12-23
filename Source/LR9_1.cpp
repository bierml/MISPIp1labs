#include <iostream>
#include <windows.h>
using namespace std;
int weight(int** matr,int str,int b)
{
    int k = 0;
    for(int j = 0;j<b;j++)
     if(matr[str][j]==1)
        k++;
    return k;
}
bool compare(int** matr,string n,int a,int b)
{
    bool result;
    for(int i = 0;i<a;i++)
    {
       result = true;
       for(int j = 0;j<b;j++)
         if(n[j]!=matr[i][j]+'0')
            result = false;
       if(result)
        return result;
    }
    return false;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a,b;
    do
    {
      cout<<"Введите количество кодовых слов: "<<endl;
      cin>>a;
      cout<<"Введите длины кодовых слов: "<<endl;
      cin>>b;
      if(a<=1 || b<=1)
        cout<<"Введены неверные данные. Повторите ввод."<<endl;
    }while(a<=1 || b<=1);
    string m;
    string n;
    int** matr = new int*[a];
    for(int j = 0;j<a;j++)
    {
        matr[j] = new int[b];
    }
    for(int i = 0;i<a;i++)
    {
         cout<<"Введите строку кодовой матрицы: "<<endl;
         cin>>m;
         for(int j = 0;j<b;j++)
            matr[i][j]=m[j]-'0';
    }
    do
    {
       cout<<"Введите некодовое слово: "<<endl;
       cin>>n;
       if(compare(matr,n,a,b) ||  n.length()!=b)
        cout<<"Данное слово является кодовым или не согласовано с кодовой матрицей!"<<endl;
    }while(compare(matr,n,a,b) ||  n.length()!=b);
    cout<<"Смежный класс: "<<endl;
    for(int i = 0;i<a;i++)
     for(int j = 0;j<b;j++)
      matr[i][j]=(matr[i][j]+n[j]) % 2;
    for(int i = 0;i<a;i++)
    {
        for(int j = 0;j<b;j++)
         cout<<matr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Лидеры смежного класса: "<<endl;
    int lider = weight(matr,0,b);
    for(int i = 1;i<a;i++)
      if(weight(matr,i,b)<lider)
        lider = weight(matr,i,b);
    for(int i = 0;i<a;i++)
    {
        if(weight(matr,i,b)==lider)
        {
            for(int j = 0;j<b;j++)
             cout<<matr[i][j]<<" ";
            cout<<endl;
        }
    }
    return 0;
}
