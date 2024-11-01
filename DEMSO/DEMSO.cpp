#include <bits/stdc++.h>
#define N 10001
using namespace std;
int main()
{
    int n, a[N], maxx=0, dem=1, nho=0;
    //freopen("DEMSO.INP","r",stdin);
    //freopen("DEMSO.OUT","w",stdout);
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    sort(a+1,a+n+1);
    //for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    for (int i=1; i<=n; i++)
        if (a[i]==a[i+1]) dem++;
        else {
                if (dem > maxx) {   nho=a[i]; maxx=dem;}
                dem=1;
        }
    cout<<nho<<endl;
}
