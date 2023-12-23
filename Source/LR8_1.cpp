#include <iostream>
#include <windows.h>
using namespace std;
bool chetnost(int* b,int a)
{
    int k = 0;
    for(int j=0;j<a;j++)
     for(int i=j+1;i<a;i++)
        if(b[j]>b[i])
            k++;
    return (k % 2==0) ? true : false;
}
bool check_for_podst(int* b,int a)
{
    for(int i=0;i<a;i++)
        if(b[i]<1 || b[i]>a) return false;
    for(int i=0;i<a;i++)
     for(int j=i+1;j<a;j++)
         if(b[i]==b[j]) return false;
    return true;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a;
    do
    {
        cout<<"Введите порядок перестановки: "<<endl;
        cin>>a;
        if(a<=0)
            cout<<"Введены неверные данные! Повторите ввод"<<endl;
    }while(a<=0);
    int* b = new int[a];
    do
    {
        for(int i = 0;i<a;i++)
        {
            cout<<"Введите значение "<<i+1<<"-го элемента нижней строки перестановки: "<<endl;
            cin>>b[i];
        }
        if(!check_for_podst(b,a))
            cout<<"Введенная строка не является перестановкой! Повторите ввод"<<endl;
    }
    while(!check_for_podst(b,a));
    if(chetnost(b,a))
        cout<<"Перестановка четная"<<endl;
    else
        cout<<"Перестановка нечетная"<<endl;
    return 0;
}
