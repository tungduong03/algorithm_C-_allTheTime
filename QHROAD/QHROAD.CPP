#include <bits/stdc++.h>
using namespace std;
int n,a[31],par[31],m,q,i,x[31],y[31],id[31],t[31];
void read()
{
    freopen("QHROAD.INP","r",stdin);
    freopen("QHROAD.OUT","w",stdout);
}
struct edge
{
    int u,v,w;
    bool operator < (const edge &x) const
{
   return w <= x.w;
}
};
vector<edge> e;

void in()
{
    cin>>n>>m>>q;
    for (i=1;i<=m;i++)
    {
        cin>>x[i]>>y[i];
        t[i]=0;
        par[i]=-1;
    }
    for (i=1;i<=q;i++)
    {
        cin>>id[i];
        t[id[i]]=1;
    }
    for (i=1;i<=m;i++)
        if (t[i]==0)
        {
            e.push_back({x[i],y[i],i});
        }
    return;
}
int root (int v)
{
    return par[v]<0 ?v :(par[v]=root(par[v]));
}

void merge (int a, int b)
{
    if ( root(a) == root(b) ) return;
    if ( par[a] < par[b] )
    {
        swap(a,b);
    }
    par[a]+=par[b];
    par[b]=a;
}

int main()
{
    int res;
    read();
    in();
    res=n;
    for (i=0;i<e.size();++i)
    {
        int u = root(e[i].u);
        int v = root(e[i].v);
        if(u!=v)
        {
            merge(u,v);
            res=res-1;
        }
    }
    cout<<res<<endl;
    int dem=e.size();
    //cout<<dem;
    for (i=1;i<q;i++)
    {
        e.push_back({x[id[i]],y[id[i]],id[i]});
        int u=root(e[dem].u );
        int v=root(e[dem].v);
        if (u!=v)
        {
            merge(u,v);
            res=res-1;
        }
        cout<<res<<endl;
        dem++;
    }
}
