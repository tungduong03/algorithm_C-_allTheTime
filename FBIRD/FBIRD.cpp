#include <bits/stdc++.h>
using namespace std;
long long s,k,n,i,j,a[20][20],dem[20],nho=0;
void doc()
{
    freopen("FBIRD.inp","r",stdin);
    freopen("FBIRD.out","w",stdout);
}
void xuli()
{
    long long tong=0;
    for (j=1;j<=k;j++)
        tong=tong+dem[j];
    if (tong==s)
    {
        cout<<s;
        nho=1;
    }
}
void chon(long long l, long long x)
{
    long long p;
    if (l-1==k) {xuli();}
    else
    {
    for (p=1;p<=n;p++)
        if (a[p][l]>= x)
    {
        dem[l]=a[p][l];
        chon(l+1,dem[l]);
    }
    }
}
int main()
{
    doc();
    cin>>n>>k>>s;
    for (i=1;i<=n;i++)
        for (j=1;j<=k;j++) cin>>a[i][j];
    chon(1,0);
    if (nho==0) cout<<-1;
}

