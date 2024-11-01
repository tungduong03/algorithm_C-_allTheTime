#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("TRSET.INP","r",stdin);
    freopen("TRSET.OUT","w",stdout);

    long long n,u,v;
    cin>>n>>u>>v;
    long long long_arr=1;
    long long p=u;
    long long R=u, L=u;
    while (p<=v)
    {
        int temp=n/p;
        int d=min(n/temp, v);
        if(d - p + 1 > R - L + 1){
			L = p;
			R = d;
		}
		p = d + 1;
	}

	cout << L << " " << R << "\n";
}
