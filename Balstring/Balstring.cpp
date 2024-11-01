#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("Balstring.inp","r",stdin);
    freopen("Balstring.out","w",stdout);
}
int main()
{
    doc();
    long long n,m,tong,i,a[100000];
    string s;
    cin>>n>>s;
    tong=n/2;
    //cout<<n<<endl;
    a[0]=0;m=0;
    for (i=1;i<=n;i++) a[i]=-1;
    for (i=1;i<=n;i++)
    {
        if (s[i]=='0') tong=tong-1;
        else tong=tong+1;
        if (a[tong]==-1) a[tong]=i;
        else
        {
            if (m < i-a[tong]) m=i-a[tong];
        }
        //cout<<m<<" "<<tong<<endl;
    }
    cout<<m;
}
