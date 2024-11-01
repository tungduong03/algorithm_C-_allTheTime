#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("Daychung.inp","r",stdin);
    freopen("Daychung.out","w",stdout);
}
int main()
{
    long long f[100][100],k,l,a[10],b[10],m;
    doc();
    cin>>a[1]>>a[2]>>a[3];
    cin>>b[1]>>b[2]>>b[3]>>b[4];
    for (k=1;k<=10;k++)
    {
        f[0][k]=0;
        f[k][0]=0;
    }
    m=0;
    for (k=1;k<=3;k++)
        for (l=1;l<=4;l++)
    {
        if (a[k]== b[l]) f[k][l]=f[k-1][l-1]+1;
        else f[k][l]=0;
        if (m< f[k][l]) m=f[k][l];
    }
    cout<<m;
}
