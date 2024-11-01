#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b;
    for (int i=a; i<=b; i++)
    {
        if (i%2 != 0)
        {
            if (check(i)==0) cout<<i<<endl;
        }
    }
}
int check(int snt);
{
    check=0;
    for (int j=2; j<= sqrt(snt); j++)
        if (snt%j==0) return check=1;
}
