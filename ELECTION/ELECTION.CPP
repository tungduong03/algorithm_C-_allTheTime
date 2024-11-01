#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("ELECTION.INP","r",stdin);
    //freopen("ELECTION.OUT","w",stdout);
    int t;
    cin>>t;
    for (int p=1; p<=t; p++)
    {
        int n,k,a[105];
        long long sum=0;
        bool check=true;
        cin>>n>>k;
        for (int i=1; i<=n; i++) cin>>a[i], sum+=a[i];
        if ( (sum+k)% n !=0 ) check=false;
        if (check)
        {
            for (int i=1; i<=n; i++) if (a[i]> ((sum+k)/n)) check=false;
        }
        if (check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
