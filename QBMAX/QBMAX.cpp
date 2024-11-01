#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("QBMAX.inp","r",stdin);
    freopen("QBMAX.out","w",stdout);
}
int main()
{
    long long n,m,i,k,j,ln,a[100][100],q=0;
    doc();
    cin>>n>>m;
    for (i=1;i<=n;i++)
        for (j=1;j<=m;j++)
        cin>>a[i][j];
    for (j=2;j<=m;j++)
        for (i=1;i<=n;i++)
    {
        ln=a[i][j-1];
        //s[i][j]=a[i][j];
        for (k=-1;k<2;k++)
                if (ln<a[i+k][j-1] && i+k>=1 && i+k<=n)
            {
                ln=a[i+k][j-1];
            }
        a[i][j]=a[i][j]+ln;
    }

    for (i=1;i<=n;i++)
    {
        if (q< a[i][m]) q=a[i][m];
    }
    cout<<q;
}

