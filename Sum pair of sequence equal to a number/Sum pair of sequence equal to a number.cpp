#include <bits/stdc++.h>
using namespace std;
int n, m , a[1000000+5], countt=0;
int main(){
    freopen("Spostan.inp", "r", stdin);
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];

    sort(a, a+n);
    //for (int i=0; i<n; i++) cout<<a[i]<<" ";
    int left = 0, right = n-1;
    while (left < right){
        if (a[left] + a[right] == m) {
            countt++;
            if (a[right-1]==a[right]) right--;
            else left++;
        }
        else if (a[left] + a[right] < m) left++;
             else right--;
    }
    cout<<countt;
}
