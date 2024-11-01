#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("AMSSEQ.INP","r",stdin);
    freopen("AMSSEQ.OUT","w",stdout);
}
int main()
{
    long long n,k,a[10001],maxx=0,i,q,p,j,f[10001];
    //doc();
    cin>>n>>k;
    for (i=1;i<=n;i++) cin>>a[i];
    f[0]=0;
    for (i=1;i<=n;i++)
    {
        p=-100000;
        for (j=1;j<=k;j++)
        {
            if (i-j>=0 && f[i-j]>=p) p=f[i-j];
        }
        f[i]=p+a[i];
        if (f[i]> maxx) maxx=f[i];
    }
    cout<<maxx;
}
