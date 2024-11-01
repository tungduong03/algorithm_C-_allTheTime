#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb    push_back

/* thuật toán: coi nút 0 là gốc của đồ thị, sử dụng
dfs để duyệt toàn bộ cây
*/
const int N=1e5+5;
int n, s[N], parent[N];                 // số đỉnh, số đỉnh liền kề của mỗi nút, cha của mỗi nút
vector<int>ad[N];                       // vector lưu trữ các nút liền kề
vector<int>res;                         // vector lưu trữ mã prufer

// khởi tạo cây với dfs
void dfs(int u, int par = -1)
{
    for(int v : ad[u])                  // trong toàn bộ những nút v liền kề với u
    {
        if(v == par) continue;           // nếu v là cha của u -> bỏ qua
        parent[v] = u;                  // v là con của u
        dfs(v, u);                      // tìm tiếp các nhánh con
    }
}
void solve()
{
    cin >> n;                           // inp số đỉnh
    for(int i=1; i<=n; i++)
    {
        int u, v; cin >> u >> v;        // có liên kết giữa 2 nút
        ad[u].pb(v);                    // liền kề của u là v
        ad[v].pb(u);                    // liền kề của v là u
        s[u]++;                         // tăng số đỉnh kề của u và v thêm 1
        s[v]++;
    }
    dfs(0);                             // khởi tạo cây với gốc 0
    priority_queue<int, vector<int>, greater<int>>qu;  // khởi tạo hàng đợi ưu tiên để sắp xếp các lá với độ phức tạp O(logn), lá có giá trị nhỏ nhất ở trên cùng
    for(int i=1; i<=n; i++)
        if(s[i] == 1) qu.push(i);       // push các lá vào
    while(qu.size())                    // khi vẫn còn lá >= 1
    {
        int u = qu.top(); qu.pop();     // lấy lá nhỏ nhất ra
        res.pb(parent[u]);              // par của lá là prufer code
        int par = parent[u];
        s[par]--;                       // số đỉnh kề - 1
        if(s[par] == 1 && par > 0) qu.push(par); // nếu nút cha là lá và khác 0 -> đẩy vào hàng đợi
    }
    int l = res.size();
    for(int i = 0; i<l-1; ++i) cout << res[i] << " ";
}

 main()
{
    //freopen("cc.inp","r",stdin);
    //freopen("cc.out","w",stdout);
    solve();
}
