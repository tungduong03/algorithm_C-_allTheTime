#include <bits/stdc++.h>
#define N 10000+5
#define M 15
using namespace std;
int n,m,par[N][M],hi[N],dis[N][N];
long long h[N];
vector<int> a[N];
void read()
{
    freopen("PWALK.INP","r",stdin);
    freopen("PWALK.OUT","w",stdout);
}
void DFS(int u)
{
    for (int i=0; i<a[u].size(); ++i)
    if (a[u][i] != par[u][0])
        {
            int v=a[u][i];
            par[v][0]=u;
            hi[v]= hi[u]+1;
            h[v]=h[u]+dis[u][v];
            DFS(v);
        }
}
void ini()
{
    DFS(1);
    for (int j=1; j<=n; j++)
        for (int i=1; i<=n; i++)
    {
        par[i][j]=par[par[i][j-1]][j-1];
    }
    hi[0]=-1;
}
int getLCA(int u, int v)
{
    if ( hi[u] < hi[v] ) return getLCA(v,u);

    for (int i=M; i>=0; i--)
        if (hi[u] > hi[v]) u=par[u][0];
    if (u==v) return u;
    for (int i=M; i>=0; i--)
        if (par[u][i] != par[v][i] )
    {
        u=par[u][i];
        v=par[v][i];
    }
}
int main()
{
    read();
    cin>>n>>m;
    for (int i=1; i<n; i++)
    {
        int u,v,l;
        cin>>u>>v>>l;
        a[u].push_back(v);
        a[v].push_back(u);
        dis[u][v]=dis[v][u]=l;
    }
    ini();
    int u,v;
    while (m--)
    {
        cin>>u>>v;
        int p=getLCA(u,v);
        cout<<h[u]+h[v]-2*h[p]<<endl;
    }
}
