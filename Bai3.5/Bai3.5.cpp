//Nguyễn Tùng Dương 20210266

#include <iostream>
using namespace std;
int c[100][100];
int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;
    return binom(n-1, k) + binom(n-1, k-1);
}

int binom2(int n, int k){
    //# Khử đệ quy
    if (k==0) {c[n][k]=1; return c[n][k];}
    if (k==n) {c[n][k]=1; return c[n][k];}
    c[n][k] = c[n-1][k] + c[n-1][k-1];
    return c[n][k];
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
