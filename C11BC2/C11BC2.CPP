#include <bits/stdc++.h>
#define N 10003
using namespace std;
int n,m,a[N][N],T[N][N];
void read()
{
    freopen("C11BC2.INP","r", stdin);
    freopen("C11BC2.OUT","w",stdout);
}

void floyd()
{
    for (int i=1; i<=n; i++)
        for (int k=1; k<=n; k++)
        for (int j=1; j<=n; j++)
        if (a[i][j] > a[i][k]+a[k][i] && a[i][k]+a[k][i]!=0 )
        {
            a[i][j]=a[i][k]+a[k][j];
            if (T[i][k]==2 || T[k][j]==2) T[i][j]=2;
        }
}
int main()
{
    read();
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int u,k;
        cin>>u>>k;
        a[i][u]=1;
        T[i][u]=k;
    }
    floyd();
//    for (int i=1; i<=n; i++)
//    {for (int j=1; j<=n; j++) cout<<a[i][j]; cout<<endl;}
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        if (T[u][v]==2) cout<<"YES"<<endl;
        if (T[u][v]!=2) cout<<"NO"<<endl;
    }

}
