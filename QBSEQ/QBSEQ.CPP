#include <bits/stdc++.h>
using namespace std;
long long n,z=0,k,i,r,s,f[1001][100],a[1001],b[1001],maxx=0,sum=0,dem=1,j;
void read()
{
    freopen("QBSEQ.INP","r",stdin);
    freopen("QBSEQ.OUT","w",stdout);
}
void select()
{
    //long long dem=1;
    for (i=1;i<=n;i++)
        if (b[i]%k !=0)
    {
        a[dem]=b[i]%k;
        dem++;
        sum=sum+a[dem-1];
    }
    maxx=maxx+n-dem+1;
}
void find_maxsum()
{
    long long x,y=1;
    for (i=1;i<=dem-1;i++)
    {
        //cout<<a[i]<<" ";
        for (j=1;j<=sum;j++)
    {
        x=j-a[i];
        if (x<0) f[i][j]=f[i-1][j];

        if (x==0) f[i][j]=max(f[i-1][j],y);
        if (x>0)
        {
            if (f[i-1][j-a[i]]!=0)
                f[i][j]=max(f[i-1][j],f[i-1][j-a[i]]+1);
            else f[i][j]=f[i-1][j];
        }
        if (j%k==0 && f[i][j]>z) z=f[i][j];
        //cout<<f[i][j]<<" ";
    }
    //cout<<endl;
    }
    //cout<<z;
}
int main()
{
    //read();
    cin>>n>>k;
    for (i=1;i<=n;i++)
        cin>>b[i];
    select();
    find_maxsum();
    cout<<maxx+z;
}
