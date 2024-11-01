#include <bits/stdc++.h>
using namespace std;
int main()
{
	int M,K,A,B;
	cin>>M>>K>>A>>B;
	int res=abs(A-B);
	while (M > 0)
	{
		res=abs(res-K);
		M--;
	}
	cout<<res;
}
