#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a[4];
    cin>>a[1]>>a[2]>>a[3];
    sort(a+1,a+1+3);
    if (a[3]==a[2]+a[1]) cout<<1;
    else cout<<0;
}
