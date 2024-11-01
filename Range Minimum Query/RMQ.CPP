#include <bits/stdc++.h>
using namespace std;
#define maxN 10000
int n, a[maxN], d[maxN][maxN];
void solve(){
    for (int i=0; i<n; i++){
        int minn = a[i];

        for (int j=i+1; j<n; j++)
        {
            if (a[j] < minn) minn = a[j];
            d[i][j] = minn;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //freopen("RMQ.INP", "r", stdin);
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    solve();
    int m, a, b, sum=0;
    cin>>m;

    for (int i=1; i<=m; i++) cin>>a>>b, sum+=d[a][b];
    cout<<sum;
    return -1;
}
