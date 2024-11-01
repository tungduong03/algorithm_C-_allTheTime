#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("QBSTR.INP","r",stdin);
    freopen("QBSTR.OUT","w",stdout);
    string a,b;
    int f[100][100];
    cin>>a;
    cin>>b;

    f[0][0]=0;
    f[0][1]=0;
    f[1][0]=0;
    for (int i=1; i<= a.size(); i++)
        for (int j=1; j<= b.size(); j++)
    {
        if (int(a[i-1]) != int(b[j-1]) && f[i-1][j]!=f[i][j-1] ) f[i][j]=max(f[i-1][j],f[i][j-1]);
        if (int(a[i-1]) != int(b[j-1]) && f[i-1][j]==f[i][j-1] ) f[i][j]=f[i-1][j];
        if (int(a[i-1]) == int(b[j-1])) f[i][j]=f[i-1][j-1]+1;
    }
    cout<<f[a.size()][b.size()];
    return 0;
}
