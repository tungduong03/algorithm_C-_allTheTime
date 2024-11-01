//Nguyễn Tùng Dương 20210266
#include <bits/stdc++.h>
using namespace std;
int T, t[20][2], h, n;
int a[20], sum = 0;
void output(){
    for (int p = 1; p<=n; p++){
        cout<<a[p];
    }
    cout<<endl;
}

void check(){
    int countt = 0;
    for (int p = 1; p<=n; p++){
        if (a[p]==1) countt++;
    }
    if (countt == h) output();
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
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> t[i][0];
        cin >> t[i][1];
    }
    for (int i = 0; i < T; i++) {
        n = t[i][0];
        h = t[i][1];
        cout << endl;
        TRY(1);
    }
    return 0;

}
