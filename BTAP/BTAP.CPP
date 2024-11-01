#include <bits/stdc++.h>
using namespace std;

int main()
{
    //doc();
    long long n,a[100001],i,maxx=0,luu,dem=0;
    cin>>n;
    for (i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n);
    for (i=1;i<=n;i++)
    {
        if (a[i]==a[i+1]) dem=dem+1;
        if (a[i]!=a[i+1])
        {
            if (dem>maxx) {maxx=dem; luu=a[i];}
            dem=0;
        }
    }
    cout<<luu;
}

