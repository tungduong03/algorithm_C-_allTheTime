#include <bits/stdc++.h>
#include <string>
using namespace std;
string s,st;
int n,i,dp[2002][2002];
void doc()
{
    freopen("NKPALIN.inp","r",stdin);
    freopen("NKPALIN.out","w",stdout);
}
main()
{
    doc();
	cin>>s;
	n=s.size();
	st=s;
	s=" "+s;
	reverse(st.begin(),st.end());
	st=" "+st;

	int res=-1;
	for(int i=1 ;i <= n;++i)
		for(int j=1;j<=n;++j)
		{
			if(st[i]==s[j])
                dp[i][j]=dp[i-1][j-1]+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
			res=max(res,dp[i][j]);
		}
    int i=n, j=n;
    dp[0][0]=0;
    string p="";
    int dem=res;
    while ( res > (dem/2))
    {
        if ( dp[i][j] > max( dp[i-1][j-1], max(dp[i-1][j],dp[i][j-1]) ) )
        {
            p=p+s[j];
            //cout<<p;
            res=res-1; i--; j--;
        }
        else
        {
            if (dp[i][j] == dp[i-1][j-1])
            {
                i--; j--;
            }
            else
                {
                    if (dp[i][j]== dp[i][j-1]) j--;
                    if (dp[i][j]== dp[i-1][j]) i--;
                }
        }
    }
    if ( dem/2 +1 == dem-dem/2)
    {
        cout<<p;
        reverse(p.begin(),p.end());
        p.erase(0,1);
        cout<<p;
    }
    else
    {
        cout<<p;
        reverse(p.begin(),p.end());
        cout<<p;
    }
}









