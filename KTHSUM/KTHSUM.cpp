#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("KTHSUM.inp","r",stdin);
    //freopen("KTHSUM.out","w",stdout);
    int n,k,a[100001],b[100001];
    cin>>n>>k;
    for (int i=1; i<=n ; i++) cin>>a[i];
    for (int i=1; i<=n ; i++) cin>>b[i];
    int sum[10000000001],dem=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
        {
            sum[dem]=a[i]+b[j];
            dem++;
        }
    sort(sum+1,sum+1+n*n);
    for (int i=1; i<=k; i++)
    {
        cout<<sum[i]<<" ";
    }
}
