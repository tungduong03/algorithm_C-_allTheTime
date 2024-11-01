#include <bits/stdc++.h>
using namespace std;
long long h;
void doc()
{
    freopen("BASEH.INP","r",stdin);
    freopen("BASEH.OUT","w",stdout);
}
long long solve( long long k)
{
    if (k>1)
    {
        if (k%2==0) return solve(k/2)*h;
        if (k%2!=0) return solve((k-1)/2)*h+1;
    }
    if (k=1) return 1;
}
int main()
{
    long long k;
    //doc();
    cin>>k>>h;
    cout<<solve(k);
}
