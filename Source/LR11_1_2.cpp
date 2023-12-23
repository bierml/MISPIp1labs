#include <iostream>
#include <windows.h>
#include <vector>
#include <math.h>
using namespace std;
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
int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int a = 0;
    string m;
    int inf[4];
    int g[5]={1,1,0,0,1};
    int comp[9]={0,0,0,0,0,0,0,0,0};
    cout<<"информационный вектор|кодовое слово"<<endl;
    for(;a<pow(2,4);a++)
    {
        m = get_binary_code(a,4);
        for(int j = 0;j<4;j++)
            inf[j]=m[j]-'0';
        for(int l = 0;l<=4+3+1;l++)
        {
         for(int i = 0;i<=3;i++)
            for(int j = 0;j<=4;j++)
             if(i+j==l)
                comp[l]+=inf[i]*g[j];
        }
        for(int i = 0;i<4;i++)
            cout<<inf[i];
        cout<<"                  ";
        for(int i = 0;i<8;i++)
            cout<<comp[i] % 2;
        cout<<endl;
        for(int i = 0;i<8;i++)
            comp[i]=0;
    }
    return 0;
}
