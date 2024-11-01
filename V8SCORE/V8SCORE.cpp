#include <bits/stdc++.h>
using namespace std;
long long s,k,n,i,j,a[20][20],dem[20],nho=0;
void doc()
{
    freopen("V8SCORE.inp","r",stdin);
    freopen("V8SCORE.out","w",stdout);
}
void xuli()
{
    long long tong=0;
    for (j=1;j<=k;j++)
        tong=tong+dem[j];
    if (tong==s)
    {
        cout<<"YES"<<endl;
        for (j=1;j<=k;j++) cout<<dem[j]<<" ";
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
    cin>>s>>k>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=k;j++) cin>>a[i][j];
    chon(1,0);
    if (nho==0) cout<<"NO";
}
