#include <bits/stdc++.h>
#define N 200000+3
using namespace std;
int n,l[N],h[N],sum[N],a[N];
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
    if ( (c<=l[x]) && (d>=h[x])) return sum[x];
    return request(c,d,2*x)+request(c,d,2*x+1);
}
void update(int x, int l, int r, int j) {
    if (j < l || r < j) {
        return ;
    }
    if (l == r) {
        sum[x] +=x-j+1;
        return ;
    }
    int mid = (l + r) / 2;
    update(x*2, l, mid, j);
    update(x*2 + 1, mid+1, r, j);
    // Cập nhật lại giá trị max của đoạn [l, r] theo 2 nút con:
    sum[x] = sum[2*x]+sum[x*2 + 1];
}
int main()
{
    int n,m;
    freopen("QUERY.INP","r",stdin);
    freopen("QUERY.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    Build(1,1,n);
    cin>>m;
    for (int i=1; i<=m; i++)
    {
        int u,l,r;
        cin>>u>>l>>r;
        if (u==2) cout<<request(l,r,1)<<endl;
        if (u==1)
            {
                for (int j=l; j<=r; j++)
                update(1,1,n,j);
            }
    }
}
