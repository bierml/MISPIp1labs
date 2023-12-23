#include <iostream>
#include <windows.h>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
bool check_string(string a)
{
    bool m = true;
    for(int i = 0;i<a.length();i++) m = m && (a[i]=='0' || a[i]=='1');
    return m;
}
string write_binary_code(int a,int b)
{
    int s = a;
    vector<int> f;
    string z;
    while( s>0 )
    {
        f.resize(f.size()+1);
        f[f.size()-1] = s % 2;
        s = s / 2;
    }
    for(int i = 0;i<b-int(logf(a)/logf(2))-1;i++) z+='0';
    for(int i = f.size()-1;i>=0;i--) z+=f[i]+'0';
    return z;
}
int codrazrlength(int inflength)
{
    int k;
    for(int i = 0;pow(2,i)<inflength+i+1;i++)
        if(pow(2,i)<inflength+i+1)
         k=i;
    return k+1;
}
string prepare_str(string a,int codrazr)
{
    string b;
    b.resize(a.length()+codrazr);
    for(int i = 0;i<(a.length()+codrazr);i++)
        b[i]='0';
    int j = 0;
    for(int i = 1;i<=(a.length()+codrazr);i++)
    {
        if(abs(log(a.length()+codrazr-i+1)/log(2)-int(log(a.length()+codrazr-i+1)/log(2)))<=pow(10,-13))
        {
            j++;
            b[i-1]='0';
        }
        else b[i-1]=a[i-1-j];
    }
    return b;
}
string isk_razr(string a,int b)
{
    string m = a;
    m[a.length()-b]='1'-(m[a.length()-b]-'0');
    return m;
}
string create_str(string a,int codrazr)
{
     string m = a;
     for(int i = 0;i<=codrazr;i++)
     {
         for(int j = 0;j<=a.length();j++)
            if(write_binary_code(a.length()-j,ceil(log(a.length())/log(2)))[ceil(log(a.length())/log(2))-i]=='1' && (a.length()-j)!=pow(2,i-1))
            {
                if(a.length()>=j+1)
                 m[a.length()-pow(2,i-1)]=(m[a.length()-pow(2,i-1)]-'0'+m[j]-'0') % 2+'0';
            }
     }
     m.resize(a.length());
     return m;
}
int search_for_error(string a,int codrazr)
{
     string m = a;
     string resultarr;
     for(int i = 0;i<codrazr;i++)
        resultarr+='0';
     for(int i = 1;i<=codrazr;i++)
     {
         for(int j = 0;j<=a.length();j++)
            if(write_binary_code(a.length()-j,ceil(log(a.length())/log(2)))[ceil(log(a.length())/log(2))-i]=='1' && (a.length()-j)!=pow(2,i-1))
            {
                if(a.length()>=j+1 && j>=0)
                    resultarr[i-1]=(resultarr[i-1]-'0'+m[j]-'0') % 2+'0';
            }
            if(i!=0)
                 resultarr[i-1]=(resultarr[i-1]-'0'+ m[a.length()-pow(2,i-1)]-'0') % 2+'0';
     }
     int g = 0;
     for(int i = 0;i<resultarr.length();i++)
      if(resultarr[i]=='1')
        g+=pow(2,i);
     return g;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string c;
    string m;
    int d;
    cout<<"Введите кодируемую строку: ";
    do
    {
        cin>>c;
        if(c.empty() || !check_string(c))
            cout<<"Неверные данные! Повторите ввод"<<endl;
    }
    while(c.empty() || !check_string(c));
    cout<<"Код Хемминга для введенной строки: "<<(c = create_str(prepare_str(c,(d = codrazrlength(c.length()))),codrazrlength(c.length())))<<endl;
    cout<<"Введите искаженную строку: ";
    cin>>m;
    cout<<"Ошибка обнаружена в "<<search_for_error(m,d)<<" разряде"<<endl;
    return 0;
}
