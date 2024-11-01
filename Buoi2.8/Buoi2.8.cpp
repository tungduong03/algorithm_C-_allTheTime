//Nguyễn Tùng Dương 20210266
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    sort(a.begin(),a.end(),[] (const vector<int> &a ,const vector<int> &b) -> bool
    {
        return accumulate(a.begin(), a.end(), 0) > accumulate(b.begin(), b.end(), 0);
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
