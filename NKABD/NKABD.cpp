#include <bits/stdc++.h>
using namespace std;
int check(int k)
{
    int sumU=0;
    for (int j=2; j<= sqrt(k); j++)
        if (k%j==0 )
        if (k/j!=j) sumU=sumU+j+k/j;
        else sumU=sumU+j;
    return sumU;
}
int main()
{
    freopen("NKABD.inp","r",stdin);
    freopen("NKABD.out","w",stdout);
    int L,R,dem=0;
    cin>>L>>R;
    for (int i=L; i<=R; i++)
    {
        if (check(i)> i ) dem++;
    }
    cout<<dem;
}

