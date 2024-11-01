#include <bits/stdc++.h>
using namespace std;
long long h[100],a[100],c[100];
void read()
{
    freopen("ELEVATOR.inp","r",stdin);
    freopen("ELEVATOR.out","w",stdout);
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
        swap(h[i],h[j]);
        swap(c[i],c[j]);
        i++;
        j--;
        }
    }
    if (L<j) qsort(L,j);
    if (i<H) qsort(i,H);
}
int main()
{
    read();
    long long n,p,j,l,t,k,build;
    bool f[1001],d=true;
    cin>>n;
    for (p=1;p<=n;p++) cin>>h[p]>>a[p]>>c[p];
    qsort(1,n);
}
