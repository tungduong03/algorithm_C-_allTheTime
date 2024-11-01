//Nguyễn Tùng Dương 20210266

#include<bits/stdc++.h>
using namespace std;

struct Data {
    int ai;
    int ki;

    Data(int ai, int ki){
        this->ai = ai;
        this->ki = ki;
    }
};

struct Comp{
    bool operator() (Data a, Data b){
        int ra, rb;

        if (a.ai <= a.ki) ra = a.ai;
        else ra = a.ki;

        if (b.ai <= b.ki) rb = b.ai;
        else rb = b.ki;

        return ra < rb;
    }
};

int n, s, kill_enemy, total_enemy;
priority_queue<Data, vector<Data>, Comp> Q;

void inputData(){
    cin >> n >> s;
    kill_enemy = 0;
    total_enemy = 0;
    for (int i=0; i<n; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        total_enemy += tmp1;
        Q.push(Data(tmp1, tmp2));
    }
}

void solve(){
    while (!Q.empty() && s>0){
        Data inf = Q.top();
        Q.pop();

        if (inf.ai <= inf.ki) kill_enemy += inf.ai;
        else {
            int nenemy = inf.ai - inf.ki;
            Q.push(Data(nenemy, inf.ki));
            kill_enemy += inf.ki;
        }

        s -= 1;
    }
}

int calc_enemy(){
    return total_enemy - kill_enemy;
}

int main(){
    inputData();
    solve();
    cout << calc_enemy();
    return 0;
}
