#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("ELEC.INP","r",stdin);
    freopen("ELEC.OUT","w",stdout);
}
int main()
{
    doc();
    long long n,m,a[51],j,i,k,q,dem,maxx=10000,p,s[100];
    cin>>n>>m;
    for (i=1;i<=n;i++)
    {
        cin>>a[i];
        for (j=a[i];j<=m;j++)
        {
            s[j]=s[j-a[i]+1]+1;
            cout<<s[j]<<" ";
        }
        cout<<endl;
    }
    cout<<s[m];
}
