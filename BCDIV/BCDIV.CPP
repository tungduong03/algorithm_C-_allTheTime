#include <bits/stdc++.h>
using namespace std;
void read()
{
    freopen("BCDIV.INP","r",stdin);
    freopen("BCDIV.OUT","w",stdout);
}
int main()
{
    read();
    int t;
    cin>>t;
    for (int z=1; z<=t; z++)
    {
        int n,m;
        int f[30][30];
        cin>>n>>m;
        //f[0][0]=0;
        for (int i=1; i<=n; i++) f[1][i]=i;

        for (int j=2; j<=m; j++)
            for (int i=j; i<=n; i++)
            f[i][j]=f[i-1][j-1]+f[i-1][j]*j;
        cout<<f[m][n]<<endl;
    }
}
