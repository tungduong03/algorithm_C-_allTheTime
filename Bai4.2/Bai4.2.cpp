// Nguyễn Tùng Dương 20210266

#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    double x = (b.first - a.first)*(c.second - a.second);
    double y = (c.first - a.first)*(b.second - a.second);
    return 0.5*fabs(x-y);
}

int main() {
     cout << setprecision(2) << fixed;
     cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
     return 0;
}
