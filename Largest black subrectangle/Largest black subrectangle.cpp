#include <bits/stdc++.h>
using namespace std;
const int maxN = 999 + 10;
//const int oo = 1e9 + 7;
int a[maxN][maxN] , m , n , d[maxN], maxx_area=0;
void findMax(){
    int k=0, area_dp;
    stack<int> s;
    while (k<m) {
        if (s.empty() || d[k] >= d[s.top()])
            s.push(k++);
        else {
            int dp = s.top();
            s.pop();
            area_dp = d[dp] * (s.empty()?(k):(k-s.top()-1));
            if (area_dp > maxx_area) maxx_area = area_dp;
        }
    }
    while (s.empty()==false){
        int dp = s.top();
        s.pop();
        area_dp = d[dp] * (s.empty()?(k):(k-s.top()-1));
        if (area_dp > maxx_area) maxx_area = area_dp;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("LBS.INP","r", stdin);
    freopen("LBS.OUT","w", stdout);
    cin>>n>>m;
    for (int i=0; i<n; i++)
        for (int j=0; j<m; j++) cin>>a[i][j];

    for (int i=0; i < m; i++) d[i] = 0;

    for (int i=0; i < n; i++) {
        for (int j=0; j < m; j++) {
            if (a[i][j]==1) {
                d[j] = d[j] + 1;
            }
            else d[j] = 0;
        //cout<<d[j]<<" ";

        }
        //cout<<endl;
        findMax();
    }
    cout<<maxx_area;

}
