#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,dem=0;
    cin>>a>>b;
    for (int i=a; i<=b; i++)
    {
        int so=i,nguoc=0;
        while (so>0)
        {
            nguoc=nguoc*10+(so%10);
            so=so/10;
        }
        so=i;
        int UCLN=abs(so-nguoc), minn=min(so,nguoc);
        while (UCLN != abs(UCLN-minn))
        {
            nguoc=min(UCLN,minn);
            UCLN=abs(UCLN-minn);
            minn=nguoc;
        }
        if (UCLN==1) dem=dem+1;
    }
    cout<<dem<<endl;
}
