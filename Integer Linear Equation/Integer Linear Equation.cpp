#include <bits/stdc++.h>
#define MAX 20

using namespace std;
int n, M, a[MAX], countt=0, t[MAX], x[MAX], f;

void init(){
    t[1]=a[1];
    for (int i = 2; i<=n; i++)
        t[i] = t[i-1]+a[i];

}
void solution(){
    if (f==M){
        countt++;
    }
}
void TRY(int k) {
    int v;
    int Max_v = (M-f-(t[n]-t[k]))/a[k];  //f là tổng các nghiệm thử trước, t[n]-t[k] là hệ số còn lại của các x sau(chưa thử) vì x>=1 nên phải trừ ra để có không gian cho x sau, rút ngắn khoảng thử

    for (v=1; v<=Max_v; v++){
        x[k]=v;
        f+=a[k]*x[k];
        if (k==n) solution();
        else TRY(k+1);

        f-=a[k]*x[k];
    }
}
int main(){
    freopen("Integer Linear Equation.inp", "r", stdin);
    freopen("Integer Linear Equation.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>M;
    for (int i=1; i<=n; i++) cin>>a[i];
    f=0;
    init();
    TRY(1);
    cout<<countt;
}
