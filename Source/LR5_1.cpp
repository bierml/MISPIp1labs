#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
bool check_string(string a)
{
    bool m = true;
    for(int i = 0;i<a.length();i++) m = m && (a[i]=='0' || a[i]=='1');
    return m;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string c;
    cout<<"Введите строку для кодирования: ";
    do
    {
        cin>>c;
        if(c.empty() || c.length() % 2 == 1 || !check_string(c))
            cout<<"Неверные данные! Повторите ввод"<<endl;
    }
    while(c.empty() || c.length() % 2 == 1 || !check_string(c));
    int m = c.length()/2;
    int matr[3][m+1];
    for(int i = 0;i<3;i++)
        for(int j = 0;j<m+1;j++)
         matr[i][j]=0;
    for(int i = 0;i<c.length()/2;i++) matr[0][i] = c[i]-'0';
    for(int i = 0;i<c.length()/2;i++) matr[1][i] = c[c.length()/2+i]-'0';
    for(int i = 0;i<c.length()/2;i++)
        matr[0][c.length()/2]+= matr[0][i];
    matr[0][c.length()/2] %= 2;
    for(int i = 0;i<c.length()/2;i++)
     matr[1][c.length()/2]+= matr[1][i];
    matr[1][c.length()/2] %= 2;
    matr[2][c.length()/2] = (matr[0][c.length()/2]+matr[1][c.length()/2]) % 2;
    for(int i = 0;i<c.length()/2;i++)
        matr[2][i]=(matr[0][i]+matr[1][i]) % 2;
    cout<<"Прямоугольный код: "<<endl;
    for(int i = 0;i<=c.length()/2;i++)
        cout<<matr[0][i]<<" ";
    cout<<endl;
    for(int i = 0;i<=c.length()/2;i++)
        cout<<matr[1][i]<<" ";
    cout<<endl;
    for(int i = 0;i<=c.length()/2;i++)
        cout<<matr[2][i]<<" ";
    cout<<endl<<"Введите количество искажаемых чисел(0 - пропустить данный этап работы): ";
    int f,d,e;
    cin>>f;
    if(f!=0)
        for(int i = 0;i<f;i++)
        {
            cout<<endl<<"Введите индексы искажаемого числа: ";
            cin>>d;
            cin>>e;
            matr[d][e] = 1-matr[d][e];
        }
    int z = (matr[0][c.length()/2]+matr[1][c.length()/2]+matr[2][c.length()/2]) % 2;
    int k = 0;
    int l = 0;
    int errarr1[m+1];
    int errarr2[2];
    if(f!=0)
    {
        cout<<"Искаженная матрица: "<<endl;
        for(int i = 0;i<=c.length()/2;i++)
            cout<<matr[0][i]<<" ";
        cout<<endl;
        for(int i = 0;i<=c.length()/2;i++)
           cout<<matr[1][i]<<" ";
        cout<<endl;
        for(int i = 0;i<=c.length()/2;i++)
            cout<<matr[2][i]<<" ";
        for(int i = 0;i<m+1;i++)
          errarr1[i]=0;
        for(int i = 0;i<2;i++)
           errarr2[i]=0;
        for(int i = 0;i<m+1;i++)
           errarr1[i]=(matr[0][i]+matr[1][i]+matr[2][i]) % 2;
        for(int i = 0;i<m+1;i++)
           k+=errarr1[i];
        for(int i = 0;i<m+1;i++)
           errarr2[0]+=matr[0][i];
        errarr2[0]%=2;
        for(int i = 0;i<m+1;i++)
        errarr2[1]+=matr[1][i];
        errarr2[1]%=2;
        l = errarr2[0]+errarr2[1];
    }
    if(k==0 && l==0 && z==0)
        cout<<"Ошибки не найдены"<<endl;
    else if(k==1 && l==1)
    {
        int x,y = 0;
        for(int i = 0;i<m+1;i++)
            if(errarr1[i]==1)
            x=i;
        for(int i = 0;i<2;i++)
           if(errarr2[i]==1)
           y=i;
        cout<<endl<<"Обнаружена ошибка в элементе matr["<<y<<"]["<<x<<"]"<<endl;
        matr[y][x] = 1-matr[y][x];
        cout<<"Ошибка исправлена"<<endl;
        cout<<endl<<"Исправленная матрица: "<<endl;
        for(int i = 0;i<=c.length()/2;i++)
         cout<<matr[0][i]<<" ";
        cout<<endl;
        for(int i = 0;i<=c.length()/2;i++)
         cout<<matr[1][i]<<" ";
        cout<<endl;
        for(int i = 0;i<=c.length()/2;i++)
         cout<<matr[2][i]<<" ";
    }
    else
    {
      cout<<endl<<"Обнаружено более одной ошибки/ошибка в контрольной строке"<<endl;
      for(int i = 0;i<m+1;i++)
        if(errarr1[i]==1)
         cout<<"Обнаружена ошибка в столбце "<<i<<endl;
      for(int i = 0;i<2;i++)
        if(errarr2[i]==1)
         cout<<"Обнаружена ошибка в строке "<<i<<endl;
    }
    return 0;
}
