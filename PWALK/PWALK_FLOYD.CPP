#include <bits/stdc++.h>
#define N 10000+5
#define M 15
using namespace std;
int n,m,par[N][M],hi[N],dis[N][N],a[N][N];
void read()
{

    freopen("PWALK.INP","r",stdin);
    freopen("PWALK.OUT","w",stdout);
}
void Floyd()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        for (int k=1; k<=n; k++)
        if (a[i][j] > a[i][k]+a[k][j])
        a[i][j]=a[i][k]+a[k][j];
}
int main()
{
    read();
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int u,v,l; cin>>u>>v>>l;
        a[u][v]=l;
        a[v][u]=l;
    }
    Floyd();
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<a[u][v]<<endl;
    }
}
