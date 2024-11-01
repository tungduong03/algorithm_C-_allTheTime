#include <bits/stdc++.h>
#define N 50000+5
using namespace std;
int n,l[N],h[N],sum[N],a[N];
void read()
{
    freopen("GSS.INP","r",stdin);
    freopen("GSS.OUT","w",stdout);
}
void Build(int x,int low,int high)
{
    int mid;
    l[x]=low;
    h[x]=high;
    if (low==high)
    {
        sum[x]=a[low];
        //leaf[low]=x;
    }
    else {
        mid=(low+high)/2;
        Build(2*x,low,mid);
        Build(2*x+1,mid+1,high);
        sum[x]=sum[2*x]+sum[2*x+1];
    }
}
int request(int c, int d, int x)
{
    if ( (d<l[x]) || (c>h[x]) ) return 0;
    if ( (c<=l[x]) && (d>=h[x]) ) return max(sum[x],max(request(c,d,2*x),max(request(c,d,2*x+1),request(c,d,2*x)+request(c,d,2*x+1)))) ;
    return max(request(c,d,2*x),max(request(c,d,2*x+1),request(c,d,2*x)+request(c,d,2*x+1)));
}
int main()
{
    read();
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    Build(1,1,n);
    int m;
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        cout<<request(u,v,1)<<endl;
    }
}




