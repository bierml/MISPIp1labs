#include <iostream>
#include <math.h>
#include <windows.h>
#include <stdio.h>
using namespace std;

bool prime_number(int a)
{
    int m = 1;
    for(int i = 2;i<a;i++)
        m*=(a % i);
    return (m==0) ? false : true;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int razm,por1,por2;
    do
    {
        cout<<"Введите размерность поля, в котором умножаются полиномы: "<<endl;
        cin>>razm;
        if(!prime_number(razm))
            cout<<"Данное множество не является полем, повторите ввод!"<<endl;
    }while(!prime_number(razm));
    cout<<"Введите степень первого полинома: "<<endl;
    cin>>por1;
    int pol1[por1+1];
    for(int i = 0;i<=por1;i++)
    {
        cout<<"Введите индекс при x^"<<i<<":"<<endl;
        cin>>pol1[i];
    }
    cout<<"Введите степень второго полинома: "<<endl;
    cin>>por2;
    int pol2[por2+1];
    for(int i = 0;i<=por2;i++)
    {
        cout<<"Введите индекс при x^"<<i<<":"<<endl;
        cin>>pol2[i];
    }
    int comp[por1+por2+1];
    for(int i = 0;i<por1+por2+1;i++)
        comp[i]=0;
    for(int l = 0;l<por1+por2+1;l++)
    {
        for(int i = 0;i<=por1;i++)
            for(int j = 0;j<=por2;j++)
              if(i+j==l) comp[l]+=pol1[i]*pol2[j];
    }
    cout<<"Произведение полиномов в поле:"<<endl;
    int j = 0;
    for(int i = por1+por2;i>1;i--)
        if((comp[i] % razm)!=0 && ++j)
           cout<<(comp[i] % razm)<<"x^"<<i<<"+";
    if((comp[1] % razm)!=0 && ++j)
        cout<<(comp[1] % razm)<<"x+";
    if((comp[0] % razm)!=0 && ++j)
        cout<<(comp[0] % razm);
    else
    {
        putchar('\b');
        putchar(' ');
        putchar('\b');
    }
    if(j==0)
        cout<<"0";
    return 0;
}
