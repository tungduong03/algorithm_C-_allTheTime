#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 1e6+5;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    long long n, a[MAXN], sum_chan[MAXN], maxx = 0, sum_le[MAXN];
    bool chan[MAXN], le[MAXN];
    cin>>n;
    sum_le[0] = 0;
    sum_chan[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin>>a[i];
    }

    if (a[1]%2==0) {
        sum_chan[1] = a[1];
        chan[1] = true;
        le[1] = false;
    }
    else {
        sum_le[1] = a[1];
        le[1] = true;
        chan[1] = false;
    }

    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {  //nếu a[i] chẵn
            if (chan[i-1]) {  //nếu tổng trước đó chẵn
                if (sum_chan[i-1] > 0) sum_chan[i] = sum_chan[i-1] + a[i];
                else sum_chan[i] = a[i];
                chan[i] = true;
            }
            else {
                sum_chan[i] = a[i];
                chan[i] = true;
            }
            if (le[i-1]) {
                sum_le[i] = sum_le[i-1] + a[i];
                le[i] = true;
            }
            else le[i] = false;
        }
        else{  //nếu a[i] không phải số chẵn
            if (le[i-1]) {
                sum_chan[i] = sum_le[i-1] + a[i];
                chan[i] = true;
            }
            else chan[i] = false;
            if (chan[i]) {
                if (sum_chan[i-1] > 0) sum_le[i] = sum_chan[i-1] + a[i];
                else sum_le[i] = a[i];
                le[i] = true;
            }
            else {
                sum_le[i] = a[i];
                le[i] = true;
            }

        }
    }
    for (int i = 1; i <= n; i++)
        if (chan[i] && maxx < sum_chan[i]) maxx = sum_chan[i];


    cout<<maxx;


}
