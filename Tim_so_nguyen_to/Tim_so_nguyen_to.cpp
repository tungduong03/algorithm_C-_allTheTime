
#include <bits/stdc++.h>
using namespace std;
int check(int snt)
{
    for (int j=2; j<= sqrt(snt); j++)
        if (snt%j==0) return 1;
    return 0;
}
int main()
{
    int a,b;
    cin>>a>>b;
    if (a==1) { a=a+2; cout<<2<<endl;}
    if (a==2) { a=a+1; cout<<2<<endl;}
    for (int i=a; i<=b; i++)
    {
        if (i%2 != 0)
        {
            if (check(i)==0) cout<<i<<endl;
        }
    }
}

