#include <bits/stdc++.h>
using namespace std;
void read()
{
    freopen("MMAXPER.INP","r",stdin);
    freopen("MMAXPER.OUT","w",stdout);
}
int main()
{
    read();
    long long n,a[1001],b[1001],i,f[2][1001];
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i]>>b[i];
    f[1][1]=a[1];
    f[2][0]=b[1];
    for (i=2;i<=n;i++)
    {
        f[1][i]=max( f[1][i-1]+abs(b[i]-b[i-1])+a[i], f[2][i-1]+abs(b[i]-a[i-1])+a[i]);
        f[2][i]=max( f[1][i-1]+abs(a[i]-b[i-1])+b[i], f[2][i-1]+abs(a[i]-a[i-1])+b[i]);
        cout<<f[1][i]<<" "<<f[2][i]<<endl;
    }
}
