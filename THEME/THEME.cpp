#include <bits/stdc++.h>
using namespace std;
long long m,b[5000],n,f[500][500];
void doc()
{
    freopen("THEME.inp","r",stdin);
    freopen("THEME.out","w",stdout);
}
void daychung(long long i,long long j)
{
    long long k,l;

    m=0;
    for (k=1;k<=i;k++)
        for (l=i+1;l<=j;l++)
    {
        if (b[k]== b[l]) f[k][l]=f[k-1][l-1]+1;
        else f[k][l]=0;
        if (m< f[k][l]) m=f[k][l];
    }
}
int main()
{
    doc();
    long long w,a[5000],q=0;
    cin>>n;
    for (w=1;w<=n;w++) cin>>a[w];
    for (w=1;w<n;w++) b[w]=a[w+1]-a[w];
    b[n]=-100;
    for (w=1;w<=n;w++)
    {
        f[0][w]=0;
        f[w][0]=0;
    }
    for (w=4;w<n;w++)
    {
        daychung(w,n);
        if (q < m) q=m;
    }
    cout<<q+1;
}
