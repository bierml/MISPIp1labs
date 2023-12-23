#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
char upper(char a)
{
    if(a>='а' && a<='я')
       return a-'а'+'А';
    else if(a>='А' && a<='Я')
        return a;
    else
        return 'А';
}
string coding(string a,string arr[])
{
    string b;
    for(int i = 0;i<a.length();i++)
        b+=arr[upper(a[i])-'А'];
    return b;
}
string decoding(string a, string arr[],int arrlength)
{
    string c = a;
    string b;
    while(!c.empty())
    {
         int m;
         for(int j = 0;j<arrlength;j++)
         {
            if(c.find(arr[j])==0 && ((m = j)+3)>1)
                b+=char('А'+j);
         }
         c = c.substr(arr[m].length());
    }
    return b;
}
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string a;
    string arr[6] = {"00","01","100","101","110","111"};
    cout<<"Введите кодируемое слово: "<<endl;
    cin>>a;
    cout<<"Закодированное слово: "<<endl;
    cout<<coding(a,arr)<<endl;
    cout<<"Введите декодируемое слово: "<<endl;
    cin>>a;
    cout<<"Декодированное слово: "<<endl;
    cout<<decoding(a,arr,6);
    return 0;
}
