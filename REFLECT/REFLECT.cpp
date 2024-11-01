#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    float l[10002],d[10002],x[10002],g[10002];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>l[i]>>d[i]>>x[i]>>g[i];
    for (int i=1; i<=n; i++)
    {
        //cin>>l>>d>>x>>g;
        int dem=0;
        float l1=0,l2=0;
        //if (g==90 || g==180) cout<<0;
        if (g[i]>90) g[i]=g[i]-90;
        if (g[i]!=90)
        {
            g[i]=(g[i]/180)*3.14159265358979323846;
            l1=x[i]*tan(g[i]);
            l2=d[i]*tan(g[i]);
            //cout<<l1<<" "<<l2<<" ";
            if (l[i]>=l1) dem=1+trunc( (l[i]-l1)/l2 );
            if (l[i]<l1 ) dem=0;
            if (l[i]>10000 && dem>0) dem=dem-1;
                cout<<dem<<endl;
            }
    }
}
