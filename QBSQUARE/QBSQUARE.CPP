#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("QBSQUARE.INP","r",stdin);
    freopen("QBSQUARE.OUT","w",stdout);
}
int main()
{
    doc();
    long long m,n,i,j,k,p,dk,maxx=0,a[100][100],r;
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++) cin>>a[i][j];
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        {
            k=i;p=j;dk=1;
            while (k<=n && p<=m && dk==1)
            {
                if (k-i+1> maxx) maxx=k-i+1;
                if (a[i][j]==a[k][p])
                {
                    for (r=0;r<=k-i;r++)
                    {
                    if (a[i][j] != a[k][j+r] || a[i][j]!=a[i+r][p])
                        {dk=0; break;}
                    }
                }
                else dk=0;
                k=k+1;p=p+1;
                cout<<maxx<<endl;
            }
        }
    cout<<maxx;
}
