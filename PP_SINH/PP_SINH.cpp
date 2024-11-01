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
void next_Combination()
{
	int i=m;
	while (b[i]==n-m+i) i--;
	if (i>=1)
	{
		b[i]=b[i]+1;
		for (int j=i+1; j<=m; j++) b[j] = b[i]+j-i;
		solution();
		next_Combination();
	}
}
int main()
{
	for (int k=1; k<=m; k++) b[k]=k;
	next_Combination();
}
