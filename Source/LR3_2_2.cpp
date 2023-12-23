#include <iostream>
#include <windows.h>
#include <string.h>
using namespace std;
char* to_char_arr(string s)
{
    char* a = new char[s.length()];
    int i = -1;
    while(s[++i]=='0' || s[i]=='1') a[i]=s[i];
    a[s.length()]='\0';
    return a;
}
bool check_for_pref(char* arr[],int number)
{
    bool b = true;
    for(int i = 0;i<number;i++)
        for(int j = 0;j<number;j++)
          if(j!=i && strstr(arr[j],arr[i])!=NULL && arr[j]-strstr(arr[j],arr[i])==0) b = false;
    return b;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int number;
    do
    {
        cout<<"Введите количество кодовых слов(>=1): "<<endl;
        cin>>number;
        if(number<1) cout<<"Введено неверное значение! Повторите ввод"<<endl;
    }while(number<1);
    string word;
    char* arr[number];
    cout<<"Введите кодовые слова: "<<endl;
    for(int i = 0;i<number;i++)
    {
        cin>>word;
        arr[i] = to_char_arr(word);
        fflush(stdin);
    }
    if(check_for_pref(arr,number))
        cout<<"Код префиксный!"<<endl;
    else
        cout<<"Код не префиксный!"<<endl;
    return 0;
}
