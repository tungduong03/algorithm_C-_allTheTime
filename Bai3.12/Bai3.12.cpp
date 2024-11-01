//Nguyễn Tùng Dương 20210266
#include<bits/stdc++.h>
using namespace std;

const int MAX = 100;
int n, k;
int m;
vector<vector<int> > arr;
int x[MAX];
bool visited[MAX];
int countt;

void input(){
    cin >> n >> k;
    cin >> m;
    arr.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        arr[u-1].push_back(v-1); // Đỉnh v kề với đỉnh u
        arr[v-1].push_back(u-1); // Đỉnh u kề với đỉnh v
    }

    for (int i = 0; i < n; i++){
        visited[i] = false;
    }
    countt = 0;
}

bool check(int v, int i){
    if (v == 0) return true;
    if (visited[i]) return false;

    int index = 0;
    for (int j = 0; j < arr[x[v-1]].size(); j++){
        if (i == arr[x[v-1]][j]) index++;
    }

    if (index == 0) return false;
    return true;
}

void solution(){
    countt++;
}

void TRY(int v){
    for (int i = 0; i < n; i++){
        if (check(v, i)){
            visited[i] = true;
            x[v] = i;

            if(v == k) solution();
            else TRY(v+1);

            visited[i] = false;
        }
    }
}

int main() {
    input();
    TRY(0);
    cout << countt/2;
}
