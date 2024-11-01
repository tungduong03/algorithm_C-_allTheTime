#include <bits/stdc++.h>
using namespace std;

bool ghepso(int l, int r, string L, string R)
{
    string s;
    s=to_string(l)+to_string(r);
    if (s.length()>R.length() || s.length()<L.length() ) return false;


    if (s.length()==R.length())
    {
        int dem=0;
        bool nho=true;
        while (nho)
        {
            if (s[dem]<R[dem]) break;
            if (s[dem]==R[dem]) dem++;
            if (s[dem]>R[dem]) nho=false;
        }
        if (nho==false ) return false;


        if (s.length()==L.length())
        {
            int dem=0;
            bool nho=true;
            while (nho)
            {
            if (s[dem]>L[dem]) break;
            if (s[dem]==L[dem]) dem++;
            if (s[dem]<L[dem]) nho=false;
            }
            if (nho==false ) return false;
        }
    }
    if (s.length()< R.length())
    {
        if (s.length()==L.length())
        {
            int dem=0;
            bool nho=true;
            while (nho)
            {
            if (s[dem]>L[dem]) break;
            if (s[dem]==L[dem]) dem++;
            if (s[dem]<L[dem]) nho=false;
            }
            if (nho==false ) return false;
        }
    }
}
int main()
{
    //freopen("CONCAT2NUM.INP","r",stdin);
    //freopen("CONCAT2NUM.OUT","w",stdout);
    int t, n, a[100003];
    cin>>t;
    for (int p=1; p<=t; p++)
    {
        cin>>n;
        int sotm=0;
        string L,R;
        //cin>>L>>R;
        cin>>L;
        cin>>R;
        //cout<<L.length()<<endl;
        //cout<<R.length()<<endl;
        for (int i=1; i<=n; i++) cin>>a[i];
        for (int i=1; i<=n; i++)
            for (int j=1; j<=n; j++)
                if (ghepso(a[i], a[j], L, R)) sotm++;
        cout<<sotm<<endl;
    }
}
