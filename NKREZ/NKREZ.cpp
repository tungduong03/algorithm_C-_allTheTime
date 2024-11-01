#include <bits/stdc++.h>
using namespace std;
long long a[10000],b[10000];
void doc()
{
    freopen("NKREZ.INP","r",stdin);
    freopen("NKREZ.OUT","w",stdout);
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
        tmp=a[i];
        a[i]=a[j];
        a[j]=tmp;
        tmp=b[i];
        b[i]=b[j];
        b[j]=tmp;
        i++;
        j--;
        }
    }
    if (L<j) qsort(L,j);
    if (i<H) qsort(i,H);
}
int main()
{
    //doc();
    long long p,n,q,m=0,tong[10000];
    cin>>n;
    for (p=1;p<=n;p++) cin>>a[p]>>b[p];
    qsort(1,n);
    for (p=1;p<=n;p++)
    {
        tong[p]=0;
        for (q=p-1;q>=1;q--)
            if (a[p] >= b[q] && tong[p] < tong[q])
            {
                tong[p]=tong[q];
            }
        tong[p]=tong[p]+(b[p]-a[p]);
        if (m<tong[p]) m=tong[p];
    }
    cout<<m;
}
