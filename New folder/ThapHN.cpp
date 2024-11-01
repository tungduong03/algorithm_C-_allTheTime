#include<bits/stdc++.h>
using namespace std;
int n;
void solve(int n , char a, char b, char c )
{
	if(n==1)
    {
		cout << a << "->" << c << endl;
		return;
	}
	solve(n-1,a,c,b);
	solve(1,a,b,c);
	solve(n-1,b,a,c);
}
int main()
{
	cout<<"Nhap n: ";
	cin>>n;
	solve(n,'A','B','C');
}