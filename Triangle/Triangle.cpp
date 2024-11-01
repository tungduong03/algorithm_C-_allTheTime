#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    //freopen("Triangle.inp","r",stdin);
    //freopen("Triangle.out","w",stdout);
    cin>>t;
    for (int l=1; l<=t; l++)
    {
        int n,a[10003],b[10003],res=0;
        cin>>n;
        for (int i=1; i<=n; i++)
            {
                cin>>a[i]>>b[i];
                if (res< a[i]+b[i]) res=a[i]+b[i];
            }
        cout<<res<<endl;
    }
}
