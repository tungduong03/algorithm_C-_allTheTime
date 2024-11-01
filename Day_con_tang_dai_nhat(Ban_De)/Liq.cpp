#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a[10001], b[10001], maxx=0;
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];
    for (int i=1; i<=n; i++) b[i]=1;
    for (int i=1; i<=n; i++)
        for (int j=1; j<i; j++)
            if (a[i]>a[j] && b[i]<b[j]+1) b[i]=b[j]+1;
    for (int i=1; i<=n; i++)
        if (b[i]>maxx) maxx=b[i];
    cout<<maxx;
}
