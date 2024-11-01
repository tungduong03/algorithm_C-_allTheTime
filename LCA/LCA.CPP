#include <bits/stdc++.h>
#define N 5003
#define M 16
using namespace std;
vector<int> a[N];
int n;
int hi[N],par[N][M+3];
void read()
{
    freopen("LCA.INP","r",stdin);
    freopen("LCA.OUT","w",stdout);
}
void DFS(int u)
{
    for (int i=0;i< a[u].size();i++)
        if (a[u][i]!=par[u][0])
        {
            int v=a[u][i];
            par[v][0]=u;
            hi[v]=hi[u]+1;
            DFS(v);
        }
}
void ini()
{
    DFS(1);
    for (int j=1;j<=M;j++)
        for (int i=1;i<=n;i++)
        par[i][j]=par[par[i][j-1]][j-1];
    hi[0]=-1;
}
int getLCA(int u,int v)
{
    if (hi[u] < hi[v])
        return getLCA(v,u);
    for (int i=M; i>=0; i--)
        if (hi[par[u][i] ] >= hi[v])
        u=par[u][i];
    if (u==v) return u;
    for (int i=M; i>=0; i--)
        if (par[u][i]!=par[v][i])
    {
        u=par[u][i];
        v=par[v][i];
    }
    return par[u][0];
}
int main()
{
    read();
    memset(hi,0,sizeof hi);
    memset(par, 0, sizeof par);
    cin>>n;
    for (int i=1;i<n;i++)   a[i].clear();
    for (int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    ini();
//    int u,v;
//    cin>>u>>v;
    //cout<<u<<" "<<v;
    //cout<< par[u][0];
//    cout<<getLCA(3,6);


}






