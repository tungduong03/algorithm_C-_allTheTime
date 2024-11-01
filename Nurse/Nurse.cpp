#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, m, S0[1003], S1[1003];
    cin>>n>>k>>m;

    for (int i = 1; i <= n; i++) {
        S0[i] = 0;
        S1[i] = 0;
    }

    S0[1] = 1; S1[k] = 1; S0[0] = 1;

    for (int i = k+1; i<= n; i++) {
        S0[i] = S1[i-1];
        S1[i] = 0;
        for (int j = k; j<=m; j++){
            if (i-j >= 0)
                S1[i] = S1[i] + S0[i-j];
        }
    }

    int rs = (S0[n]+ S1[n])%(1000000000+7);

    cout<<rs;

}
