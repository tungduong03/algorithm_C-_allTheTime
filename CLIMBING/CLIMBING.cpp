#include <bits/stdc++.h>
using namespace std;
int tim_kc(int a[], int i, int m, int c, int minn, int maxx)
{
    int b[10002];
    for (int j=1; j<=m; j++)
        b[j]=a[i-m+j];
    sort(b+1, b+m+1);
    minn=b[1];
    maxx=b[m];
    return b[m]-b[1];
}
int main()
{
    //freopen("CLIMBING.inp","r",stdin);
    //freopen("CLIMBING.out","w",stdout);
    int n, m , c, a[1000001];
    cin>>n>>m>>c;
    for (int i=1; i<=n; i++) cin>>a[i];
    int nho=0, minn=0, maxx=0;
    int kc=tim_kc(a, m, m, c, minn, maxx);
    if (kc<=c) cout<<1<<endl, nho=1;
    for (int i=m+1; i<=n; i++)
    {
        if (maxx < a[i] || minn>a[i])
        {
            kc=tim_kc(a, i, m, c, minn, maxx);
            if (kc<=c) cout<<i-m+1<<endl, nho=1;
        }
        else cout<<i-m+1<<endl, nho=1;
    }
    if (nho==0) cout<<"NONE";
}
