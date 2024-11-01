#include <bits/stdc++.h>
using namespace std;
long long n,i,f[10000],a[10000],b[10000],maxx;
void doc()
{
    freopen("Bai3.inp","r",stdin);
    freopen("Bai3.out","w",stdout);
}
void qsort(long long L, long long H)
{
    long long i,j,x,tmp;
    i=L;
    j=H;
    //x:=a[random(H-L+1)+L];
    x=a[(L+H)/2];
    while (i<j)
    {
    while (a[i]<x) i++;
    while (a[j]>x) j--;
        if (i<=j)
        {
        swap(a[i],a[j]);
        swap(b[i],b[j]);
        i++;
        j--;
        }
    }
    if (L<j) qsort(L,j);
    if (i<H) qsort(i,H);
}
int main()
{
    doc();

    cin>>n;
    for (i=1;i<=n;i++)
        cin>>a[i]>>b[i];
    qsort(1,n);
    f[1]=b[1]-a[1];
    maxx=f[1];
    for (i=2;i<=n;i++)
        {
            if (a[i]< b[i-1]) f[i]=b[i]-a[i]+f[i-1]-(b[i-1]-a[i]);
            else f[i]=b[i]-a[i];
            if (f[i] > maxx ) maxx=f[i];
        }
    cout<<maxx;
}
