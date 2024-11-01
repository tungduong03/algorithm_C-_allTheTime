#include <bits/stdc++.h>
using namespace std;
int n, countt=0, a[8];
void solve(){

    int bol = 0;
    int s = n - ( (100*a[1]) + (10*a[2]) + a[3] - (100*a[4]) - 62 );
    if ( (s % 10) == a[3] && s > 999 && s < 10000) {
        int b[8];
        b[5] = s / 1000;
        s = s % 1000;
        b[6] = s / 100;
        s = s % 100;
        b[7] = s / 10;

        for (int p = 1; p<=4; p++) b[p] = a[p];
        sort(b+1,b+8);
        for (int p = 1; p<7; p++){
            if (b[p] == b[p+1] || b[p] <= 0 || b[p+1] >= 10) bol = 1;
        }
        if (bol == 0) {
            countt++;
        }
    }
}

void TRY(int v){
    for (int i = 1; i <= 9; i++){
        a[v] = i;
        if (v == 4) solve();
        else TRY(v+1);
    }
}

int main(){
    cin>>n;
    TRY(1);
    cout<<countt;
}

/*
a[1] = I;
a[2] = C;
a[3] = T;
a[4] = K;
*/


