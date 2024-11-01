//Nguyễn Tùng Dương 20210266
#include <bits/stdc++.h>
using namespace std;
int n, k1, k2, a[1000];
void output(){
    for (int p = 1; p<=n; p++){
        cout<<a[p];
    }
    cout<<endl;
}

void check(){
    int minn=n+1, maxx = 0, nho = 0, countt = 0, maxx_0 =0 ;
    //cout<<1;
    for (int p = 1; p <= n; p++){
        if (a[p]==1) {
            nho++;
            if (nho > maxx) maxx = nho;
        }
        else {
            if ( (nho < minn) && (nho != 0) ) minn = nho;
            nho = 0;
        }
        if (a[p]==0) {
            countt++;
            if (countt > maxx_0) maxx_0 = countt;
        }
        else countt=0;
    }
    if (nho != 0 && nho < minn) minn = nho;
    //cout<<minn<<" "<<maxx<<endl;
    if ( minn <= k2 && minn >= k1 && maxx <=k2 && maxx >=k1 && maxx_0<2) output();
}

void TRY(int v){
    //cout<<1;
    for (int i = 0; i<=1; i++){
        a[v] = i;
        if (v==n) check();
        else TRY(v+1);
    }
}

int main(){
    //freopen("Bai3.9.inp","r",stdin);
    cin>>n;
    cin>>k1>>k2;
    //a[0]=0;
    TRY(1);

}
