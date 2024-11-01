#include <bits/stdc++.h>
using namespace std;
int a[100][100], n , m, visitted[100], countt[100];
void DFS(int u){
    cout<<u<<" ";
    countt[u] += 1;
    visitted[u] = true;
    for (int v = 1; v <= n; v++)
        if (a[u][v] == 1 && visitted[v] == false)
            DFS(v);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("DFS.inp", "r", stdin);

    cin>>n>>m;
    for (int i = 1; i<=m; i++){
        int x, y;
        cin>>x>>y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
    for (int i = 1; i<=n; i++)
        visitted[i] = false, countt[i] = 0;
    for (int i = 1; i<=n; i++)
        if (countt[i] == 0) DFS(i);

}
