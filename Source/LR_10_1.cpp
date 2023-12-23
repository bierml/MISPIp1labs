#include <iostream>
#include <windows.h>
using namespace std;
int euclid(int a, int b, int &x, int &y) {
    if(b == 0) {
       x = 1;
       y = 0;
       return a;
    }

    int x1, y1, gcd = euclid(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int mod(int a,int b)
{
    return (a>=0) ? a % b : b-(-a % b);
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a11,a12,a21,a22,b1,b2,g;
    cout<<"Введите коэффициент расширенной матрицы a11: "<<endl;
    cin>>a11;
    cout<<"Введите коэффициент расширенной матрицы a12: "<<endl;
    cin>>a12;
    cout<<"Введите коэффициент расширенной матрицы a21: "<<endl;
    cin>>a21;
    cout<<"Введите коэффициент расширенной матрицы a22: "<<endl;
    cin>>a22;
    cout<<"Введите коэффициент расширенной матрицы b1: "<<endl;
    cin>>b1;
    cout<<"Введите коэффициент расширенной матрицы b2: "<<endl;
    cin>>b2;
    cout<<"Введите размерность кольца вычетов: "<<endl;
    cin>>g;
    int x_,y_,r_,s_;
    int b1_ = b1;
    int b2_ = b2;
    int a11_ = a11;
    int a12_ = a12;
    int a21_ = a21;
    int a22_ = a22;
    if(!(g<=0 || g==1))
    {
        r_=a21/euclid(a11,a21,x_,y_);
        s_=(-a11*r_)/a21;
        a11=mod((x_*a11_+y_*a21_),g);
        a12=mod((x_*a12_+y_*a22_),g);
        b1=mod((x_*b1_+y_*b2_),g);
        a21=mod((r_*a11_+s_*a21_),g);
        a22=mod((r_*a12_+s_*a22_),g);
        b2=mod((r_*b1_+s_*b2_),g);
    }
    if(g<=0 || g==1)
        cout<<"Неверно введены данные, повторите ввод!"<<endl;
    else if(euclid(a11,g,x_,y_)!=1 || euclid(a22,g,x_,y_)!=1)
        cout<<"Данная система уравнений не имеет решений или имеет бесконечно много решений"<<endl;
    else
    {
        euclid(a11,g,x_,y_);
        a11=mod(a11*mod(x_,g),g);
        a12=mod(a12*mod(x_,g),g);
        b1=mod(b1*mod(x_,g),g);
        int a21_ = a21;
        a21=mod(a21-mod(mod(a11*mod(x_,g),g)*a21_,g),g);
        a22=mod(a22-mod(mod(a12*mod(x_,g),g)*a21_,g),g);
        b2=mod(b2-mod(mod(b1*mod(x_,g),g)*a21_,g),g);
        euclid(a22,g,x_,y_);
        a21=mod(a21*mod(x_,g),g);
        a22=mod(a22*mod(x_,g),g);
        b2=mod(b2*mod(x_,g),g);
        int a12_ = a12;
        a11=mod(a11-mod(a12_*a21,g),g);
        a12=mod(a12-mod(a12_*a22,g),g);
        b1=mod(b1-mod(a12_*b2,g),g);
        cout<<"x="<<b1<<",y="<<b2;
    }
    return 0;
}
Для задачи 2:
#include <iostream>
#include <windows.h>
#include <math.h>
using namespace std;
int mod(int a,int b)
{
    return (a>=0) ? a % b : b-(-a % b);
}
int reverse_(int a, int g)
{
    int res = 0;
    for(int i = 1;i<g && res==0;i++)
        if(mod(i*mod(a,g),g)==1)
         res = i;
    return res;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a,g;
    cout<<"Введите a: "<<endl;
    cin>>a;
    cout<<"Введите p: "<<endl;
    cin>>g;
    if(g<=0)
        cout<<"Введено неверное значение размерности кольца"<<endl;
    else if(reverse_(a,g)!=0)
     cout<<"a^(-1)= "<<reverse_(a,g)<<endl;
    else
     cout<<"В кольце не найден обратный элемент!"<<endl;
    return 0;
}
