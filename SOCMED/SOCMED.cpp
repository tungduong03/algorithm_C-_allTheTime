#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("SOCMED.inp","r",stdin);
    //freopen("SOCMED.out","w",stdout);
    int n,k,dem[102];
    string tk[102],mk[102];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>tk[i]>>mk[i],dem[i]=0;
    cin>>k;
    for (int i=1; i<=k; i++)
    {
        string a,b;
        cin>>a>>b;
        for (int i=1; i<=n; i++)
            if (a==tk[i] && b==mk[i]) dem[i]++;
    }
    for (int i=1; i<=n; i++) cout<<dem[i]<<" ";
}
