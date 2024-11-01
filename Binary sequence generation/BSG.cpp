#include <bits/stdc++.h>
using namespace std;
//string str="";
int n, m, a[101];
void solve(){
    for (int j=0; j<n; j++) cout<<a[j];
    cout<<endl;
}
void dq(int t, int k){
    for (int i=k+1; i<=m; i++){
        a[t]=i;
        if (t==(n-1)) solve();
        else dq(t+1, i);
    }

}
int main(){
    ios_base::sync_with_stdio(false);
    cout.tie(0);
    cin>>n>>m;
    dq(0, 0);
}
