#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h,m,a,b;
    cin>>h>>m>>a>>b;
    h=h+(b-a);
    if (h>=24) h=h-24;
    if ( h<0 ) h=h+24;
    cout<<h<<" "<<m;
}
