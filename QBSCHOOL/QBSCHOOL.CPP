#include <bits/stdc++.h>
#define N 5000 + 3
#define M 20000+ 3
using namespace std;
int n,m,d[N],sl[N],a[N][N],tr[N],Count;
bool xet[N];
void read()
{
    freopen("QBSCHOOL.INP","r",stdin);
    freopen("QBSCHOOL.OUT","w",stdout);
}
void dijkstra(int s)
{
    for (int i=1; i<=n; i++)
        {d[i]=a[s][i];tr[i]=s; xet[i]=true;}
    d[s]=0; xet[s]=false; Count=1;
    while (Count != n)
    {
        int dem=0,u,p;
        for (int i=1; i<=n; i++)
        {
            if (xet[i] && dem==1) if (d[i]< p && d[i]!=0) p=d[i],u=i;
            if (xet[i] && dem==0) {p=d[i]; dem=1; u=i;}
        }
        xet[u]=false;
        //cout<<u<<" ";
        for (int i=1; i<=n; i++)
        {
            if (d[i]> d[u]+a[u][i] || d[i]==0)
            {
                d[i]=d[u]+a[u][i];
                tr[i]=u;
            }
            //if (d[i]==d[u]+a[u][i] && tr[i]!=u) sl[i]+=1;
        }
        Count++;
    }

}
int main()
{
    read();
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int k,u,v,m;
        cin>>k>>u>>v>>m;
        if (k==1) a[u][v]=m;
        else {
                a[u][v]=m;
                a[v][u]=m;
                }
        }
    dijkstra(1);
    cout<<d[n]<<" "<<sl[n]+1;
}
