#include <bits/stdc++.h>
using namespace std;
void read()
{
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
}
int main()
{
    //read();
    long long n,k,i,j,x,y,maxx=0,s,a[1005][1005],f[1005][1005];
    cin>>n>>k;
    f[0][0]=0;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++) cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
    for (i=k;i<=n;i++)
        for (j=k;j<=n;j++)
    {
        x=i-k;
        y=j-k;
        s=f[i][j]-f[x][j]-f[i][y]+f[x][y];
        if (s>maxx) maxx=s;
        //cout<<s<<" ";
    }
    cout<<maxx;
}
