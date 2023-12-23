#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;
int cmpfunc (const void * a, const void * b)
{
  return (*(double*)b > *(double*)a) ? 1 : (*(double*)b < *(double*)a) ? -1:0 ;
}
int divide(int first, int last, double arr[])
{
     double med_ver = 0;
     double current_diff;
     double current_sum;
     double current_ind = first;
     for(int i = first;i<=last;i++) med_ver+=arr[i]/2;
     for(int i = first;i<=last;i++)
     {
         current_sum = 0;
         for(int j = first; j<=i;j++) current_sum+=arr[j];
         if(i==first) current_diff = abs(current_sum-med_ver);
         else
          if (abs(current_sum-med_ver)<current_diff && (current_ind=i)>0) current_diff = abs(current_sum-med_ver);
     }
     return current_ind;
}
void get_code(int k,int last,double arr[])
{
      int a = 0;
      int b = last;
      while(a-b!=0)
      {
          if(k<=divide(a,b,arr))
          {
              b = divide(a,b,arr);
              cout<<"0";
          }
          else
          {
              a = divide(a,b,arr)+1;
              cout<<"1";
          }
      }
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number;
    do
    {
        cout<<"Введите количество кодируемых символов(>=1): "<<endl;
        cin>>number;
        if(number<1) cout<<"Введено неверное значение! Повторите ввод"<<endl;
    }while(number<1);
    double arr[number];
    double sum;
    do
    {
        sum = 0;
        cout<<"Введите вероятности появления кодируемых символов: "<<endl;
        for(int i = 0; i<number;i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        if(abs(sum-1)>=pow(10,-13)) cout<<"Введены неверные значения вероятностей(суммарная вероятность <>1)! "<<endl;
    }while(abs(sum-1)>=pow(10,-13));
    qsort(arr, number, sizeof(double), cmpfunc);
    cout<<"Кодовый словарь: "<<endl;
    for(int i = 0;i<number;i++)
    {
        cout<<i+1<<" ";
        get_code(i,number-1,arr);
        cout<<" "<<endl;
    }
    string a;
    cout<<"Введите кодируемую строку: "<<endl;
    cin>>a;
    cout<<"Закодированное слово: "<<endl;
    for(int i = 0;a[i]!='\0';i++) get_code(a[i]-'1',number-1,arr);
    return 0;
}
