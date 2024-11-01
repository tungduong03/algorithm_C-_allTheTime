#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ddd.inp","r",stdin);
    string s;
    getline(cin,s);
    int i=0,sum=0,a=0;
    while (i< s.size())
    {
        if (s[i] != ' ')
            a=a*10+ (int(s[i]) - 48);
        else
        {
            sum=sum+ a;
            a=0;
        }
        i++;
    }
    if (a!=0) sum=sum+a;
    cout<<sum;
}
