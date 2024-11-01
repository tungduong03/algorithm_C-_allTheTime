#include <bits/stdc++.h>
#
using namespace std;
void read()
{
    freopen("SELECT.INP","r",stdin);
    freopen("SELECT.OUT","w",stdout);
}
int main()
{
    read();
    int n,a[2][1000];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[1][i];
    for (int i=1; i<=n; i++) cin>>a[2][i];

    a[1][n+1]=0;
    a[2][n+1]=0;
    int i=1,maxx;
    int s=0;
    while (i <=n )
    {
        maxx=a[1][i]; int nho=i;
        for (int k=1; k<=2; k++)
            if (a[1][i+k] > maxx) maxx=a[1][i+k],nho=i+k;
        s=s+maxx;
        i=nho+1;
        cout<<s<<" ";
        if (a[2][nho-1] > 0 && nho-1>0) s=s+a[2][nho-1];
        cout<<s<<" ";
        if (a[2][nho+1] > 0) {s=s+a[2][nho+1];i=nho+2;}
        cout<<s<<" "<<nho<<" "<<maxx<<" "<<i<<endl;
    }
    cout<<s;
}
