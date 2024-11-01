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
        for (int k=1; k<=n; k++)
        for (int j=1; j<=n; j++)
            //if (i!=j && a[k][j]!=0 )
            if (a[i][j]==0 || a[i][j] > a[i][k]+a[k][j])
        {a[i][j]=a[i][k]+a[k][j]; a[j][i]=a[i][j];}
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
//        for (int i=1; i<=n; i++)
//    {for (int j=1; j<=n; j++) cout<<a[i][j]<<" "; cout<<endl;}
    while (m--)
    {
        int u,v;
        cin>>u>>v;
        cout<<a[u][v]<<endl;
    }
}

