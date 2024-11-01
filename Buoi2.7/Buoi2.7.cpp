//Nguyễn Tùng Dương 20210266
#include <iostream>
using namespace std;

//# viết hàm arr_sum
template <typename P>
P arr_sum(P* a, int leng_a, P* b, int leng_b){
    P sum = 0;
    for (int i=0; i<leng_a; i++) sum+=a[i];
    for (int i=0; i<leng_b; i++) sum+=b[i];
    return sum;
}
int main() {
    int val;
    cin >> val;

    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;
    }

    return 0;
}
