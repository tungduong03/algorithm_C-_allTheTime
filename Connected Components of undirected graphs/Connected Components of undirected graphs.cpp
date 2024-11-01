#include <bits/stdc++.h>
#define maxN 100000+5
using namespace std;

vector<int> graph[maxN];
long int n, m, visted[maxN], countt=0;
void dfs(int x){
    visted[x] = 1;
    for (int k=0; k<graph[x].size(); k++)
        if (visted[graph[x][k]]==false) dfs(graph[x][k]);
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("CCoug.int", "r", stdin);
    cin>>n>>m;
    for (int i=1; i<=m; i++) {
        int x, y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    for (int i=1; i<=n; i++) visted[i] = 0;

    for (int i=1; i<=n; i++){
        if (visted[i]==0) dfs(i), countt++;
    }
    cout<<countt;
}
