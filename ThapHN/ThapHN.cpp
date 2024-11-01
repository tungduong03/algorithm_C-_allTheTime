#include <bits/stdc++.h>
using namespace std;
/**ý tuong: muc tieu chuyen n cai tu A->C (n,A,B,C)
{
muc tieu chuyen n-1 cai tu A->B
muc tieu chuyen 1 cai tu A->C
muc tieu chuyen n-1 cai tu n-1 (dang o B) B->C
}
**/
void ThapHN(int n, char a, char b, char c)
{
	if (n==1) cout<<"Chuyen 1 dia tu "<<a<<" sang "<<c<<endl ;
	else 
	{
		ThapHN(n-1, a, c, b);
		ThapHN(1, a, b, c);
		ThapHN(n-1, b, a, c);
	}
}
int main()
{
	ThapHN(3,'a','b','c');
}
