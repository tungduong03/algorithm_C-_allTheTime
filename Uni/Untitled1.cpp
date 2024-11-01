#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    int x,res=0;
    getline(cin,a);
    cin>>x;
    for (int i=0; i< a.length(); i++)
    {
        int ts=int(a[i])-97+x;
        if (ts>25) ts=ts-25;
        res=res+ts;
        cout<<ts<<endl;
    }
    cout<<res;
    return 0;
}
