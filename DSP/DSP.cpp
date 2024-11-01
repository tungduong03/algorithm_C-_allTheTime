#include <bits/stdc++.h>
using namespace std;
int m=1,p,n;
int b[10000],a[10000],s[10000];
void doc()
{
    freopen("DSP.INP","r",stdin);
    freopen("DSP.OUT","w",stdout);
    cin>>n;
    for (p=1;p<=n;p++)
    cin>>s[p];
}
void xuli()
{
    long long tong=0,dem=1,nho=0,j;
    for (j=1; j<=n;j++)
    {
        if (a[j]==1)
        {
            tong=tong+s[j];
            b[dem]=s[j];
            dem++;
        }
    }
    for (j=1;j<=dem-1;j++)
    {
        if ((tong-b[j]) % b[j]==0)
        {
            nho=1;
        }
    }
    if ((nho==1) && (m<dem-1))
    {
        m=dem-1;
    }
}
void dnp(int x)
{
    int i;
    for (i=0; i<2 ; i++)
    {
        a[x]=i;
        if (x<n) dnp(x+1);
        else
        {
            xuli();
        }
    }
}
int main()
{
    doc();
    dnp(1);
    cout<<m;
}
