#include<bits/stdc++.h>
using namespace std;
int n,a[301],par[301];
void mo()
{
    freopen("FWATER.INP","r",stdin);
    freopen("FWATER.OUT","w",stdout);
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
    cin>>n;
    for(int i=1;i<=n;++i)
    cin>>a[i],par[i]=-1;

    for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
    {
       int v;
    cin>>v;
    e.push_back({i,j,v});
    e.push_back({j,i,v});
    }
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

void process()
{
    int res=0;
    in();
    sort(a+1,a+1+n);
    sort(e.begin(),e.end());
    for(int x=0;x<e.size();++x)
    {
        int u = root(e[x].u);
        int v = root(e[x].v);
        if(u!=v)
        {
        merge(u,v);
        res+=e[x].w;
        }
    }
    cout<<res+a[1];
}
int main()
{
    //mo();
    process();
}
