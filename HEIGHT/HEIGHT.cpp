#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("HEIGHT.inp","r",stdin);
    //freopen("HEIGHT.out","w",stdout);
    int q;
    cin>>q;
    for (int p=1; p<=q; p++)
    {
        int n,a[100002],dem[100002];
        cin>>n;
        for (int i=1; i<=n; i++) cin>>a[i],dem[i]=0;
        a[0]=1000000001;
        for (int i=1; i<=n; i++)
        {
            int dau=0;
            int xet;
            xet=i-1;
            while (a[xet]<=a[i] && xet>0 && dau==0)
            {
                if (a[xet]==a[i])
                {
                    dem[i]=dem[xet];
                    dau=1;
                }
                xet--;
            }
            if (dau==0)
            {
                xet=i+1;
                while (a[xet]<=a[i] && xet<=n)
                {
                    if (a[xet]==a[i]) dem[i]++;
                    xet++;
                }
            }
            cout<<dem[i]<<" ";
        }
        cout<<endl;
    }
}
