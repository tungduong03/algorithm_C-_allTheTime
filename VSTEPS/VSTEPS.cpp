#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("VSTEPS.inp","r",stdin);
    freopen("VSTEPS.out","w",stdout);
}
int main()
{
    long long n,k,x,i,a[100000],dem=0;
    //doc();
    cin>>n>>k;
    for (i=1;i<=n;i++) a[i]=1;
    for (i=1;i<=k;i++) {cin>>x; a[x]=0;}
    a[0]=0;
    for (i=2;i<=n;i++)
    {
        if (a[i]!=0)
        {
        if (a[i-1] !=0 && a[i-2] !=0) a[i]=(a[i-1]+a[i-2])%14062008;
        if (a[i-1] !=0 && a[i-2] ==0) a[i]=a[i-1]%14062008;
        if (a[i-1] ==0 && a[i-2] !=0) a[i]=a[i-2]%14062008;
        if (a[i-1] ==0 && a[i-2] ==0) {cout<<0; dem=1; break;}

        }
    }
    if (dem==0) cout<<a[n];
}
