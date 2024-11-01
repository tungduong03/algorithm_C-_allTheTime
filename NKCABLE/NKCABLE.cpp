#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("NKCABLE.inp","r",stdin);
    freopen("NKCABLE.out","w",stdout);
}
int main()
{
    //doc();
    long long n,a[1000],f[1000],i;
    cin>>n;
    for (i=1;i<n;i++) cin>>a[i];
    f[2]=a[1];f[3]=a[1]+a[2];
    for (i=4;i<=n;i++)
    {
        f[i]=min(f[i-1],f[i-2])+a[i-1];
    }
    cout<<f[n];
}
