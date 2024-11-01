#include <bits/stdc++.h>
using namespace std;
int a[31][31], lich[31][31], sol =100, countt[31], m , n, chose[31];
vector<int> f[31];
void solution(){
    int maxx =0;
    for (int o = 1; o<=m; o++){
        if (countt[o]>maxx) maxx= countt[o];
    }
    //cout<<1;
    if (maxx < sol) sol = maxx;
}
void khoiphuc(int p, int v){
    for (int o=0; o<f[v].size(); o++){
        int q = f[v][o];
        a[q][v] =1;
        //a[v][q] =1;
    }
    for (int o=1; o<=n; o++){
        if (lich[o][v]==1) a[p][o] = 1;
    }
    countt[p]--;
}
void xoa(int p, int v){
    for (int o = 1; o<=m; o++) {
        if (a[o][v]==1) a[o][v]=0, a[v][o]=0;  //xóa các gv có thể dạy môn đó
    }
    for (int o = 1; o<=n; o++) {
        if (lich[o][v]==1) a[p][o] = 0; //nếu lịch trùng thì gv dạy sẽ xóa hp liên quan
    }
    countt[p]++;
}
void TRY(int v){
    for (int i=1; i<=m ;i++){
        if (a[i][v]==1) {
                chose[v]=i;
                xoa(i, v); //truyền người dạy và học phần vào để xóa
                if (v==n) solution();
                else TRY(v+1);
                khoiphuc(i, v); //khôi phục lại các học phần liên quan đến v
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    freopen("BCA.INP","r", stdin);
    //freopen("BCA.OUT","w", stdout);

    cin>>m>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) a[i][j]=0;
    for (int i=1; i<=m; i++){ //đọc các khóa giáo viên có thể dạy
        int x, y;
        cin>>x;
        for (int p=1; p<=x; p++) {
            cin>>y;
            a[i][y]=1;  //gv i dạy môn y
            //a[y][i]=1;
            f[y].push_back(i);  //môn y có thể dạy bởi gv i
        }
    }
    int k;
    cin>>k;
    for (int i=1; i<=k; i++){
        int x, y;
        cin>>x>>y;
        lich[x][y]=1;  //lịch dạy x trùng y
        lich[y][x]=1;  //lịch dạy y trùng x
    }
    TRY(1);
    cout<<sol;
}
