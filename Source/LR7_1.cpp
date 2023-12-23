#include <iostream>
#include <windows.h>
#include <math.h>
#include <vector>
using namespace std;
int weight(string a)
{
    int k = 0;
    for(int i = 0;i<a.length();i++)
        if(a[i]=='1') k++;
    return k;
}
string get_binary_code(int a,int b)
{
    int s = a;
    vector<int> f;
    string z;
    if(a==0)
    {
         for(int i = 0;i<b;i++) z+='0';
         return z;
    }
    while( s>0)
    {
        f.resize(f.size()+1);
        f[f.size()-1] = s % 2;
        s = s / 2;
    }
    for(int i = 0;i<b-int(logf(a)/logf(2))-1;i++) z+='0';
    for(int i = f.size()-1;i>=0;i--) z+=f[i]+'0';
    return z;
}
string get_code(int** arr,string a,int c,int d)
{
   string m;
   m.resize(d);
   for(int i = 0;i<d;i++)
    m[i]='0';
   for(int j = 0;j<d;j++)
    for(int i = 0;i<c;i++)
     if(arr[i][j]*(a[i]-'0')==1)
      m[j]='0'+((m[j]-'0'+1) % 2);
   return m;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a,b;
    do
    {
      cout<<"Введите количество строк матрицы: "<<endl;
      cin>>a;
      cout<<"Введите количество столбцов матрицы: "<<endl;
      cin>>b;
      if(a<=0 || b<=0)
        cout<<"Произошла ошибка! Повторите ввод"<<endl;
    }while(a<=0 || b<=0);
    int** c = new int*[b];
    for(int i = 0;i<a;i++)
        c[i]= new int[b];
    for(int i = 0;i<a;i++)
    {
        for(int j = 0;j<b;j++)
        {
            cout<<"Введите значение элемента a["<<i<<"]["<<j<<"]: ";
            cin>>c[i][j];
        }
    }
    int minw = weight(get_code(c,get_binary_code(1,a),a,b));
    cout<<"Кодовый словарь: "<<endl;
    for(int i = 0;i<pow(2,a);i++)
    {
        cout<<get_binary_code(i,a)<<" "<<get_code(c,get_binary_code(i,a),a,b)<<endl;
        if(weight(get_code(c,get_binary_code(i,a),a,b))<minw && i!=0)
            minw=weight(get_code(c,get_binary_code(i,a),a,b));
    }
    cout<<"Кодовое расстояние: "<<minw;
    return 0;
}
