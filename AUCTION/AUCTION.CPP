#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("AUCTION.INP","r",stdin);
    freopen("AUCTION.OUT","w",stdout);
}
int main()
{
    long long n,m,a[1001],i,f[1001],maxx=0,nho;
    //doc();
    cin>>n>>m;
    for (i=1;i<=m;i++) cin>>a[i];
    sort(a+1,a+m+1);
    for (i=1;i<=m;i++)
    {
        if (m-i+1 <=n) f[i]=a[i]*(m-i+1);
        if (m-i+1 >n)  f[i]=a[i]*n;
        if (maxx< f[i]) {maxx=f[i]; nho=a[i];}
    }
    cout<<nho<<" "<<maxx;
}
