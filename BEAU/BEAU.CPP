#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("BEAU.INP","r",stdin);
    freopen("BEAU.OUT","w",stdout);
}
int main()
{
    long long a[400][400],n,c,j,i,k,s,maxx=0,p;
    //doc();
    cin>>n;
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
        cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=n;j++)
    {
        c=1;
        while (i+c<=n && j+c<=n)
        {
            s=0;
            for (k=0;k<=c;k++)
                s=s+a[i+k][j+k]-a[i+c-k][j+k];
            if (s> maxx) {maxx=s;}
            c++;
            //cout<<s<<endl;
        }
    }
    cout<<maxx;
}
