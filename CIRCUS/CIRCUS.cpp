#include <bits/stdc++.h>
using namespace std;
int a[21],b[21],c[21],n,m,k[21],ress=0;
void qsort(long long L, long long H)
{
    long long p,q,xx;
    p=L;
    q=H;
    //x:=a[random(H-L+1)+L];
    xx=c[(L+H)/2];
    while (p<q)
    {
    while (c[p]<xx) p++;
    while (c[q]>xx) q--;
        if (p<=q)
        {
        swap(a[p],a[q]);
        swap(b[p],b[q]);
        swap(c[p],c[q]);
        p++;
        q--;
        }
    }
    if (L<q) qsort(L,q);
    if (p<H) qsort(p,H);
}
int solve()
{
    int sum=0,res=10000;
    for (int i=1; i<=n; i++)
        if (k[i]==1) sum+=b[i];
    int dem=0;
    for (int i=1; i<=n; i++)
        if (k[i]==1 && dem==0)
        {   if (sum-b[i]<=c[i])
            {
                sum-=b[i];
                int d=c[i]-sum;
                if (d<res) res=d;
            }
            else dem=1;
        }
    sum=0;
    if (dem==0)
    for (int i=1; i<=n; i++) if (k[i]==1) sum+=a[i];
    if (sum>=m) return res;
}
void dnp(int x)
{
    for (int i=0; i<2; i++)
    k[x]=i;
    if (x<n) dnp(x+1);
    else {
            int sol= solve();
            if (sol >ress) ress=sol;
    }
}
int main()
{
    freopen("CIRCUS.INP","r",stdin);
    freopen("CIRCUS.OUT","w",stdout);
    cin>>n>>m;
    for (int i=1; i<=n; i++) cin>>a[i]>>b[i]>>c[i];
//    qsort(1,n);
//    for (int i=1; i<=n; i++)
//        for (int j=i; j<=n; j++)
//        if (c[i]==c[j] && b[i]>b[j])
//    {
//        swap(b[i],b[j]);
//        swap(a[i],a[j]);
//    }
//    //dnp(1);
//    cout<<ress;
}
