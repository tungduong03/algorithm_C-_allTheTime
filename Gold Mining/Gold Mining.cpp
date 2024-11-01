#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, a[1000], f[1000], res = 0, minn, maxx;


    cin>>n>>minn>>maxx;
    for (int i = 1; i<=n; i++) cin>>a[i];

    for (int i = 1; i<=minn; i++) f[i] = a[i];

    for (int i = minn+1; i<=n; i++) {
        int maxi = 0;
        for (int j = minn; j<=maxx; j++){
            if (i-j>0)
                if (f[i-j] > maxi) maxi = f[i-j];
        }
        f[i] = a[i] + maxi;
    }

    for (int i = 1; i <= n; i++) {
        if (f[i] > res) res = f[i];
    }
    cout<<res;

}
