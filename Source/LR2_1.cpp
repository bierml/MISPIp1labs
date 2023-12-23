#include <iostream>
#include <math.h>
#include <vector>
#include <windows.h>
#define pi M_PI
using namespace std;
double preobr_furie(double x, int m)
{
     double sum = 0.5;
     for(int i = 1;i<m+1;i++) sum+=2*sin((2*i-1)*x)/(pi*(2*i-1));
     return sum;
}
double sgn(double x)
{
    if(x==0)
        return 0;
    else
        return (x>0) ? 1 : -1;
}
double meandr(double x)
{
    return (sgn(sin(x))+1)/2;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int g;
    double k;
    vector<double> arr;
    do
    {
        cout << "Введите количеcтво аргументов функции: ";
        cin >> g;
        if(g>0) break;
        else cout<<"Неверное значение!Повторите ввод"<<endl;
    }while(true);
    cout << "Введите значение аргументов функции: "<<endl;
    do
    {
        cin >> k;
        arr.resize(arr.size()+1);
        arr[arr.size()-1] = k;
    } while(arr.size()<g);
    do
    {
        cout << "Введите число гармоник в разложении в ряд Фурье: ";
        cin >> g;
        if(g>0) break;
        else cout<<"Неверное значение!Повторите ввод"<<endl;
    }while(true);
    cout << "аргумент функции | значение функции | сумма ряда | расхождение"<<endl;
    int m = 0;
    double f = 0;
    for(int i = 0;i<arr.size();i++)
    {
        cout.setf(ios::left);
        cout.width(18);
        cout<<arr[i];
        cout.setf(ios::left);
        cout.width(19);
        cout<<meandr(arr[i]);
        cout.setf(ios::left);
        cout.width(13);
        cout<<preobr_furie(arr[i],g);
        cout<<abs(meandr(arr[i])-preobr_furie(arr[i],g));
        cout<<endl;
        if(abs(meandr(arr[i])-preobr_furie(arr[i],g))>=f)
        {
            f = abs(meandr(arr[i])-preobr_furie(arr[i],g));
            m = i;
        }
    }
    cout<<"Аргумент, для которого наблюдается максимальное расхождение: "<<arr[m]<<endl;
    cout<<"Величина максимального расхождения: "<<abs(meandr(arr[m])-preobr_furie(arr[m],g));
    return 0;
}
