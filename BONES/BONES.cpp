#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("BONES.inp","r",stdin);
    freopen("BONES.out","w",stdout);
}
int main()
{
    //doc();
    long long s[81],i,j,k,tong,s1,s2,s3,m=0,l,nho=100;
    cin>>s1>>s2>>s3;
    for (i=1;i<=81;i++) s[i]=0;
    for (i=1;i<=s1;i++)
        for (j=1;j<=s2;j++)
            for (k=1;k<=s3;k++)
    {
        tong=i+j+k;
        s[tong]=s[tong]+1;
        if (m < s[tong])  m=s[tong];
    }
    for (i=1;i<=80;i++) if (s[i]==m && nho>i) nho=i;
    cout<<nho;
}
