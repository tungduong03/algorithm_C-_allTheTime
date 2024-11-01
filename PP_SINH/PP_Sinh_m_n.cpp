#include <bits/stdc++.h>
#define N 10
using namespace std;
int n = 5;
int m = 3;
int b[N];
void solution()
{
	for (int p=1; p<=m; p++)
	cout<<b[p]<<" ";
	cout<<endl;
}
bool check(int k, int i)
{
	if (i > n) return false;
	else return true;
}
void next(int k)
{
	for (int i=b[k-1]+1; i<=k+m-1; i++)
	{
		if (check(k,i))
		{
			b[k] = i;
			if (k==m) solution();
			else next(k+1);
		}
	}
}
int main()
{
	next(1);
}
