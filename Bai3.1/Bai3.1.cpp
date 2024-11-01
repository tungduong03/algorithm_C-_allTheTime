//Nguyễn Tùng Dương 20210266

#include <bits/stdc++.h>
using namespace std;
int lucas(int n) {

    int L0=2, L1=1, L;
    while (n>=2) {
        L = L1 + L0;
        L0 = L1;
        L1 = L;
        n--;
    }
    return L;
}
int main(){
    cout<<lucas(5);
}
