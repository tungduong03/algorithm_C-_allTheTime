#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("DTDOI.inp","r",stdin);
    freopen("DTDOI.out","w",stdout);
}
int main()
{
    //doc();
    long long m,n,s[1000],a[100],i,j,p=0,dem=0;
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        if (p<a[i]) p=a[i];
    }
    while (m> 1000)
    {
        m=m-p;
        dem++;
    }
    s[0]=0;
    for (i=1;i<=m;i++) s[i]=10000;
    for (i=1;i<=n;i++)
    {
        for (j=a[i];j<=m;j++)
        {
            if (s[j] > s[j-a[i]]+1) s[j]=s[j-a[i]]+1;
        }
    }
    cout<<s[m]+dem;
}
