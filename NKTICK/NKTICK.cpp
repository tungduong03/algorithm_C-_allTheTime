#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("NKTICK.inp","r",stdin);
    freopen("NKTICK.out","w",stdout);
}
int main()
{
    int n,f[30002],t[30002],r[30002];
    //doc();
    cin>>n;
    //cout<<n;
    for (int i=1; i<=n; i++) cin>>t[i];
    for (int i=1; i<n; i++ ) cin>>r[i];
    f[0]=0;
    f[1]=t[1];
    for (int i=2; i<=n; i++)
    {
        if ( t[i]+f[i-1] <= r[i-1]+f[i-2]) f[i]=t[i]+f[i-1];
        else f[i]=r[i-1]+f[i-2];
    }
    cout<<f[n];
}
