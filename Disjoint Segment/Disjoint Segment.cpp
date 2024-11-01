#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> a[100005];
bool compare1(const vector<int>& v1, const vector<int>& v2) {
        return v1[0] < v2[0];
}
bool compare2(const vector<int>& v1, const vector<int>& v2) {
        return (v1[1]-v1[0]) < (v2[1]-v2[0]);
}
bool compare3(const vector<int>& v1, const vector<int>& v2) {
        return v1[1] < v2[1];
}
void Greedy1(){ //sắp xếp theo điểm {bắt đầu} càng sớm càng tốt
    sort(a.begin(), a.end(), compare1);
    for (const auto& vec : a){

    }
}

void Greedy2(){ //sắp xếp theo các đoạn có kích thước nhỏ, càng nhỏ càng tốt


}

void Greedy3(){ //sắp xếp theo điểm {kết thúc} càng sớm càng tốt


}

int main(){
    freopen("Disjoint Segment.inp","r", stdin);

    cin>>n;

    for (int i = 1; )


}
