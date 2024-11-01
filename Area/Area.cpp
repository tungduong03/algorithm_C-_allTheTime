#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("Area.inp","r",stdin);
    freopen("Area.out","w",stdout);
}
int main()
{
    doc();
    long long n,i,a[10000],m=0,left,right,dem;
    cin>>n;
    for (i=1;i<=n;i++) cin>>a[i];
    a[0]=0;a[n+1]=0;
    for (i=1;i<=n;i++)
    {
        left=i-1;right=i+1;dem=1;
        while (a[left] >= a[i])
        //for (left=i-1;left>=1;left--)
        {
            left--;
            dem++;
        }
        while (a[right] >= a[i])
        //for (right=i+1;right<=n;right++)
        {
            right++;
            dem++;
        }
        if (m < dem*a[i])  m=dem*a[i];
    }
    cout<<m;
}
