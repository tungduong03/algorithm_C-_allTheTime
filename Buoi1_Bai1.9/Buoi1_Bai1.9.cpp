#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, a[1001];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>a[i];

    for (int i=1; i<=n; i++)
        for (int j=i; j<=n; j++){
            for (int k=i; k<=j; k++) cout<<a[k]<<" ";
            cout<<endl;
        }
}

