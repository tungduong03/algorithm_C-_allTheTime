#include <bits/stdc++.h>
using namespace std;
void doc()
{
    freopen("Bai1.inp","r",stdin);
    freopen("Bai1.out","w",stdout);
}
int main()
{
    doc();
    string n;
    bool f[100];
    stack <int> s;
    int k,p,i;
    for (i=1;i<100;i++)
        f[i]=true;
    cin>>n>>k;
    p= n.length();
    k=p-k;
    s.push(1);
    while (k!=0)
    {
        while (k!=0 && s.empty() && n[i]> n[s.top()])
        {
            f[s.top()]=false;
            s.pop();
            s.push(i);
        }
        i++;
    }
    cout<<f[1];
}
