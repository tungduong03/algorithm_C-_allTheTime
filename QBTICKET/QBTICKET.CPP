#include <bits/stdc++.h>
using namespace std;
void read()
{
    freopen("QBTICKET.INP","r",stdin);
    freopen("QBTICKET.OUT","w",stdout);
}
int main()
{
    //read();
    long long n,l1,l2,l3,c1,c2,c3,b[100001],f[100001],s,p,q,i,mo,dem,dis;
    cin>>l1>>l2>>l3>>c1>>c2>>c3;
    cin>>n;
    cin>>s>>q;
    for (i=1;i<n;i++) cin>>b[i];
    //for (i=s;i<q;i++) {b[p]=a[i]; p++;}
    b[s-1]=0;
    f[0]=0;
    for (i=s;i<q;i++)
    {
        dem=0;
        p=i-1;
        while (dem==0 && p>=s-1)
        {
            dis=b[i]-b[p];
            if (dis > l3) dem=1;
            else
            {
                if (dis>l2 && dis<=l3) mo=f[p]+c3;
                if (dis>l1 && dis<=l2) mo=f[p]+c2;
                if (dis<=l1) mo=f[p]+c1;
                //cout<<mo<<" ";
            }
            if (f[i]>=mo) f[i]=mo;
            if (p==i-1) f[i]=mo;
            p--;

        }
        //cout<<f[i]<<" "<<endl;
    }
    cout<<f[q-1];
}
