#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("ABC.INP","r",stdin);
    freopen("ABC.OUT","w",stdout);
    /*pair<int,int> a[100];
    cin>>a[1].first>>a[1].second;
    cin>>a[2].first>>a[2].second;
    sort(a.first,(a+2).first);
    cout<<a[1].first<<" "<<a[1].second<<endl;
    cout<<a[2].first<<" "<<a[2].second;*/
    string s,st;
    getline(cin,s);
    getline(cin,st);
    for (int i=0; i<s.size(); i++)
    {
        if (    int(st[i])-65 < 26 )
        cout<<s[i]+(int(st[i])-65) << " " ;
        else
        cout<<s[i]+(int(st[i])-65-26) << " ";

}
}
