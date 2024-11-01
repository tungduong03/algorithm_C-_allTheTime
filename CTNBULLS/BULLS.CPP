#include <bits/stdc++.h>
#define N 100001
using namespace std;
void read()
{
    freopen("BULLS.INP","r",stdin);
    freopen("BULLS.OUT","w",stdout);
}
int main()
{
    read();
    int n,k,f[N];
    cin>>n>>k;
    for (int i=1; i<=n; i++)
        if (i<=k+1) f[i]=i+1;
    else f[i]=(f[i-1]+f[i-k-1])%2111992;
    cout<<f[n]<<endl;
}
