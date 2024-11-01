#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("LICH.INP","r",stdin);
    freopen("LICH.OUT","w",stdout);
}
int main()
{
    long long n,c,l,t,a[1000],f[1001],s,i,j,p,b[1000];
    doc();
    cin>>n>>l>>c;
    for (i=1;i<=n;i++) cin>>a[i];
    f[0]=0;b[0]=0;
    for (i=1;i<=n;i++)
    {
        f[i]=100000;s=0;
        for (j=i;j>=1;j--)
        {
            if (s+a[j]<=l)
            {
                s=s+a[j];
                if ( (l-s)<=10) t=10;
                if ( (l-s) >10) t=(l-s)*(l-s);
                if ( (l-s)==0 ) t=0;
                p=t+f[j-1];
                if (p<f[i])
                {f[i]=p; b[i]=b[j-1]+1;}
            }
            else break;
        }
    }
    cout<<b[n]<<endl<<f[n];
}
