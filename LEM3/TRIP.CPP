#include <bits/stdc++.h>
using namespace std;
long long n,a[20][20],f[20],res=10000000;
bool xet[20];
void read()
{
    freopen("TRIP.INP","r",stdin);
    freopen("TRIP.OUT","w",stdout);
}
long long duyet(int u)
{
    xet[u]=false;
    int nho=0;
    for (int j=1; j<=n; j++)
        if (xet[j])
        {
            if (f[u]==0) f[u]=a[u][j]+duyet(j);
            else f[u]=min(f[u],a[u][j]+duyet(j));
            nho=1;
        }
    if (nho==0) return 0;
    return f[u];
}
int main()
{
    read();
    cin>>n;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        cin>>a[i][j];
    for (int i=1; i<=n; i++)
        {
            memset(xet, true, sizeof xet);
            memset(f, 0, sizeof f);
            //cout<<f[i]<<endl;
            res=min(res,duyet(i));
            //cout<<f[i]<<endl;
        }
    cout<<res;
}
