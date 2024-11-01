#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("VCOWFLIX.INP","r",stdin);
    freopen("VCOWFLIX.OUT","w",stdout);
    int w,n,f[5002],a[20],res=0;
    cin>>w>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int j=0; j<=w; j++) f[j]=0;
    for (int i=1; i<=n; i++)
        for (int j=w; j>0; j--)
    {
        if (a[i]+f[j-a[i]] > f[j] && a[i]<=j) f[j]=a[i]+f[j-a[i]];
    }
    cout<<f[w];
}
