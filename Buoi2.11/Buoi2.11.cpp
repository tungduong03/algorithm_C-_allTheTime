//Nguyễn Tùng Dương 20210266

#include<bits/stdc++.h>
using namespace std;

void input (vector<int> &a, int n) {
    int x;
    for(int i = 0; i < n; i++) {
        cin>>x; a.push_back(x);
    }
}

using complex_double = complex<double>;
const double PI = acos(-1);
void fast_fourier(vector<complex_double> &p, bool invert) {
    int n = p.size();
    if (n == 1)
        return;
    vector<complex_double> p_0(n/2), p_1(n/2);
    for (int i = 0; 2*i < n; i++) {
        p_0[i] = p[2*i];
        p_1[i] = p[2*i+1];
    }
    fast_fourier(p_0, invert);
    fast_fourier(p_1, invert);

    double angle = 2*PI/n * (invert ? -1 : 1);
    complex_double  matrix_element(1), martric_element_n(cos(angle), sin(angle));
    for (int i = 0; 2*i < n; i++) {
        p[i] = p_0[i] + matrix_element * p_1[i];
        p[i + n/2] = p_0[i] - matrix_element * p_1[i];
        if (invert) {
            p[i] /=  2;
            p[i + n/2] /= 2;
        }
        matrix_element = matrix_element * martric_element_n;
    }
}
vector<int> polynomial_multiply(vector<int> &a, vector<int> &b) {
    vector<complex_double> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while (n < a.size() + b.size())
        n <<= 1;
    fa.resize(n);
    fb.resize(n);
    fast_fourier(fa, false);
    fast_fourier(fb, false);

    for (int i = 0; i < n; i++)
        fa[i] *= fb[i];
    fast_fourier(fa, true);
    vector<int> result(n);
    for (int i = 0; i < n; i++)
        result[i] = round(fa[i].real());
    return result;
}

int main () {
    int m,n;
    //freopen("Buoi2.11.inp", "r", stdin);
    vector<int> a, b;
    cin >> n;
    input(a,n+1);
    cin>>m;
    input(b,m+1);
    vector<int> c = polynomial_multiply(a,b);

    int h = m + n + 1;
    int xor_c = c[0] ^ c[1];
    for (int i = 2; i < h; i++)
        xor_c = xor_c^c[i];
    cout << endl<< xor_c;
    return 0;
}
