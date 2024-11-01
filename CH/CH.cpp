#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("CH.INP","r",stdin);
    freopen("CH.OUT","w",stdout);
}
int main()
{
    doc();
    int m,n,k,j,i,p,dem=0;
    long long f[11][11][11][11],a[51][51];
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
    {
        for (k=i;k<=n;k++)
            for (p=j;p<=m;p++)
        {
            f[i][j][k][p]=f[i][j][k-1][p]+f[i][j][k][p-1]-f[i][j][k-1][p-1]+a[k][p];
            if (f[i][j][k][p]%9==0) {dem=dem+1;}
        }
    }
    cout<<dem;
}
