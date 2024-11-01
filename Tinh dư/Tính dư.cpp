#include <bits/stdc++.h>
using namespace std;
int main(){
    int x, n=4757;
    cin>>x;
    int y=x;
    for (int i=1; i<2003; i++){
        y = (y*x) %n;
    }
    cout<<y;


}
