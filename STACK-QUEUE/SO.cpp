#include <bits/stdc++.h>
using namespace std;
int daonguoc(int a)
{
    int s=0;
    while (a>0)
    {
        s=10*s+a%10;
        a=a/10;
    }
    return s;
}
int main()
{
    int l,r,dem=0;
    cin>>l>>r;
    //cout<<uoc(12)<<" ";
    for (int i=l; i<=r; i++)
        {
            int d=__gcd(i,daonguoc(i));
            if (d==1) dem++;
        }
    cout<<dem;
}
