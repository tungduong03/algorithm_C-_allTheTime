#include <bits/stdc++.h>
using namespace std;
void read()
{
    freopen("KMBUS.INP","r",stdin);
    freopen("KMBUS.OUT","w",stdout);
}
int main()
{
    //read();
    long long n,l,f[101][10001],a[101],i,j;
    cin>>n>>l;
    for (i=1;i<=n;i++) cin>>a[i];
    for (i=1;i<=n;i++) f[i][0]=0;
    for (i=1;i<=l;i++) f[0][i]=100000;
    for (i=1;i<=n;i++)
        for (j=1;j<=l;j++)
    {
        f[i][j]=min(f[i][j-i]+a[i],f[i-1][j]);
        //cout<<f[i][j]<<" ";
    }
    cout<<f[n][l];
}
