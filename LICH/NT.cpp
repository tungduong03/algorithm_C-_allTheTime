#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("NT.inp","r",stdin);
    freopen("NT.out","w",stdout);
}
int main()
{
    doc();
    long long s,d,c,d1,c1,i;
    cin>>d>>c;
    if (d<=2)        {s=2*1+3*2+5*3+7*4; d=11;}
    if (d=3)         {    s=3*1+5*2+7*3; d=11;}
    if (d>3 && d<=5) {        s=5*1+7*2; d=11;}
    if (d>5 && d<=7) {            s=7*1; d=11;}
    d1=d/6+1;
    c1=c/6+1;
    for (i=d1;i<=c1;i++)
    {
        if ( (6*i+1) % 5 !=0 && (6*i+1) % 7 != 0 ) s=(s+(6*i+1)) %(1000000007);
        if ( (6*i-1) % 5 !=0 && (6*i-1) % 7 != 0 ) s=(s+(6*i-1)) %(1000000007);
    }
    cout<<s;
}
