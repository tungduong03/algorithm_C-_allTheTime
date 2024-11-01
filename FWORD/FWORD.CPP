#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("FWORD.INP","r",stdin);
    freopen("FWORD.OUT","w",stdout);
    long long n,m,k,x;
    string s_chinh, s[505];
    cin>>n>>m>>k>>x;
    cin>>s_chinh;
    for (int i=1; i<=m; i++)
    {
        cin>>s[i];
        sort(s[i].begin(), s[i].end());
    }

    for (int i=1; i<=m; i++)
    {
        bool check=true;
        int j=0;
        while (check)
        {
            if ( j*pow(k,m-i) < x && (j+1)*pow(k,m-i) >= x  ) s[i]=s[i][j],check=false;
            else j++;
        }
        x=x-j*k;
    }

    int dem=1;
    string s_xuat="";
    for (int i=0; i<s_chinh.size(); i++)
        if (int(s_chinh[i]) == 35)
        s_xuat+=s[dem],dem++;
        else s_xuat+=s_chinh[i];
    cout<<s_xuat;
}






