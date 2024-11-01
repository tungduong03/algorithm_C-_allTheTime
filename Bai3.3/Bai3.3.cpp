//Nguyễn Tùng Dương 20210266

#include <bits/stdc++.h>
using namespace std;
#define MAX 100

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = 10000000; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//solution
void solution(){
    curr = 0;
    int y, z;
    for (int p = 1; p<n; p++){
        y = x[p]; z = x[p+1];
        curr += c[y][z];
    }
    curr += c[z][1];
    if (curr < best) best = curr;
}

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        if (mark[i]==0){
            x[k] = i;
            mark[i]=1;

            if (k==n) solution();
            else TRY(k+1);
            mark[i]=0;
        }
    }
}

int main() {
    //freopen("Bai3.3.inp", "r", stdin);
    input();
    for (int i=1; i<=n; i++) mark[i]=0;
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
