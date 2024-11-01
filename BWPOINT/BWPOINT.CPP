#include <bits/stdc++.h>
#define N 100001
using namespace std;
int a[N],b[N];
void read()
{
    freopen("BWPOINT.INP","r",stdin);
    freopen("BWPOINT.OUT","w",stdout);
}
pair<int,int> ai[2*N];
int main()
{
    read();
    int n;
    cin>>n;
    for (int i=1; i<=n; i++)
    {
        cin>>a[i];
        ai[i]=make_pair(a[i],1);
    }
    for (int i=1; i<=n; i++)
    {
        cin>>b[i];
        ai[i+n]=make_pair(b[i],0);
    }
    sort(ai+1,ai+1+2*n);
    //for (int i=1; i<=2*n; i++) cout<<ai[i].first<<" ";
    int i=1,dem=0;
    while (i<2*n)
    {
        if (ai[i].second != ai[i+1].second ) dem++,i+=2;
        if (ai[i].second == ai[i+1].second ) i++;
    }
    cout<<dem;
}
