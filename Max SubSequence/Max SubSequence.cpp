#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Max SubSequence.inp", "r", stdin);
    long long n;
    int a[1000000+3];
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    int sum = 0, maxx=a[0];
    for (int i=0; i<n; i++)
        if (sum + a[i] > 0) {
            sum = sum+a[i];
            if (sum > maxx) maxx = sum;
        }
        else sum = 0;
    cout<<maxx;
}
