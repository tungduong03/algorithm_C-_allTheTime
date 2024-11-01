#include <bits/stdc++.h>
using namespace std;
int main()
{

    //freopen("GOLD.INT","r",stdin);
    //freopen("GOLD.OUT","w",stdout);
    int n,m,duong[1003],am[1003],a[1001][1001];
    cin>>n>>m;
    for (int i=1; i<=n; i++)
        {
            duong[i]=0;
            am[i]=0;
            for (int j=1; j<=m; j++)
            {
            cin>>a[i][j];
            if (a[i][j]>0) duong[i]=duong[i]+a[i][j];
            if (a[i][j]<0) am[i]=am[i]+a[i][j];
            }
        }
    int maxx1=0, maxx2=0;
    for (int i=1; i <=n; i++)
        {if (maxx1<duong[i]) maxx1=duong[i];
        if (maxx2>am[i]) maxx2=am[i];
        }
    cout<<maxx1-maxx2;
}
