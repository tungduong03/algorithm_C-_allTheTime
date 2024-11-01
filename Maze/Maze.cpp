#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int maxN = 999 + 100;
const int oo = 1e9 + 7;
int a[maxN][maxN] , m , n , r, c, d[maxN][maxN];
    //a[maxN][maxN] đánh dấu cột môt ô đã xét hay chưa
    //d[maxN][maxN] lưu độ dài đường đi từ ô xuất phát đến ô hiện tại
int dx[] = {1, 0, -1, 0},
    dy[] = {0, 1, 0, -1};
queue<ii> qe; //lưu các ô lân cận sẽ được xét

int solve(){
    qe.push(ii(r,c)); //đưa điểm dầu vào
    d[r][c] = 0;
    a[r][c] = 1; //đánh dấu ô xuất phát
    while (!qe.empty()){
        ii u = qe.front(); qe.pop();
        for (int i = 0; i < 4; i++){
            int x = dx[i] + u.first; int y = dy[i] + u.second;  //2 lệnh này để dịch chuyển đến 4 ô nằm cạnh
            if (x < 1 || x > m || y < 1 || y > n) //nếu đã ra ngoài thì dừng lại return kết quả
                return d[u.first][u.second] + 1 ;
            if (a[x][y] != 1){                      //nếu ô đó không có chướng ngại vật
                d[x][y] = d[u.first][u.second] + 1; //tăng biến đếm quãng đường đi
                qe.push(ii(x,y));                   //lưu vào ô cần được xét
                a[x][y] = 1;                           //đánh dấu đã thăm
            }

        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("maze.inp", "r", stdin);
    //freopen("maze.out", "w", stdout);

    cin>>m>>n>>r>>c;

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    int ans = solve();
    cout << ans;
    return 0;
}
