#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("PTRANG.inp","r",stdin);
    freopen("PTRANG.out","w",stdout);
}
int main()
{
    //doc();
    long long n,l,f[6000],a[6000],i,j,m,tong,s[6000],dem;
    cin>>n>>l;
    for (i=1;i<=n;i++) cin>>a[i];
    f[0]=0;
    f[1]=l-a[1];
    for (i=2;i<=n;i++)
    {
        tong=0;dem=1;
        for (j=i;j>=1;j--)
        {
            s[dem]=f[j-1];
            tong=tong+a[j];
            if (tong<=l)
            {
                m=l-tong;
                if (s[dem] < m ) s[dem]=m;
                dem++;
            }
            else break;
        }
        f[i]=s[1];
        for (j=1;j<dem;j++) if (f[i]> s[j]) f[i]=s[j];
    }
    cout<<f[n];
}
