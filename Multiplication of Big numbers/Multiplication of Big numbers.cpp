#include <bits/stdc++.h>

using namespace std;

typedef vector < int > vi;

// Nạp chồng toán tử nhập luồng, dùng để nhập vào số lớn.
istream &operator >> (istream &cin, vi &a)
{
    string s;
    cin >> s;

    a.clear();
    for (int i = 0; i < s.size(); ++i)
        a.push_back(s[i] - '0');

    return cin;
}

// Nạp chồng toán tử trích luồng, dùng để in ra số lớn.
ostream &operator << (ostream &cout, const vi &a)
{
    for (auto d: a)
        cout << d;

    return cout;
}

// Xóa các số 0 vô nghĩa ở đầu.
void del_zero(vi &a)
{
    reverse(a.begin(), a.end());

    while (a.size() >= 2)
        if (a.back() == 0)
            a.pop_back();
        else
            break;

    reverse(a.begin(), a.end());
}

vi int_to_vi(int n)
{
    vi res;
    if (n == 0)
    {
        res.push_back(n);
        return res;
    }

    while (n)
    {
        res.push_back(n % 10);
        n /= 10;
    }

    return res;
}

// Nhân hai số lớn.
vi operator * (vi a, vi b)
{
    // Đảo ngược hai số trước để tiện tính toán.
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    // Resize trước mảng kết quả. Kết quả của tích có thể đạt tới số chữ số
    // bằng tổng độ dài của hai số ban đầu cộng lại và cộng thêm 1.
    vi c(a.size() + b.size() + 1);
    for (int i = 0; i < (int) a.size(); ++i)
        for (int j = 0; j < (int) b.size(); ++j)
        {
            c[i + j] += (a[i] * b[j]);
            c[i + j + 1] += (c[i + j] / 10);
            c[i + j] %= 10;
        }

    // Xử lý nốt phần giá trị nhớ chưa được cộng hết.
    // Mảng c hiện tại đang là mảng kết quả bị đảo ngược.
    c.push_back(0);
    for (int i = 0; i < (int) c.size() - 1; ++i)
    {
    	c[i + 1] += (c[i] / 10);
    	c[i] %= 10;
    }

    // Đảo ngược mảng c và xóa các chữ số 0 vô nghĩa ở đầu, ta sẽ thu được tích a * b.
    reverse(c.begin(), c.end());
    del_zero(c);

    return c;
}

main()
{
    vi a, b;
    int n;
    freopen("Multiplication of Big numbers.inp", "r", stdin);
    cin >> a >> b;
    //cin >> n;

    // Nhân số lớn a và số nhỏ n. Chuyển n qua số lớn để nhân.
    //cout << a * int_to_vi(n) << '\n';
    // Nhân hai số lớn a và b.
    cout << a * b;

    return 0;
}
