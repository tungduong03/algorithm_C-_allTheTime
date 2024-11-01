#include <bits/stdc++.h>
using namespace std;
int main()
{
    //nhập n và in ra các số nguyên tố bé hơn n
    int n;
    cin>>n;
    //khai báo mảng từ 2-->n mang giá trị true
    bool check[1000];
    for (int i=1; i<=n; i++) check[i]=true;

    //chạy từ 2-->sqrt(n) và loại bỏ các số là bội của các số tìm được.
    /*
    vì 2 đúng --> 4,6,8,... số chẵn là false
    vì 3 đúng --> 6,9,12,...false
    4 là false nên sẽ ko xét nữa
    5=true --> 10,15,... false
    */
    for (int i=2; i<=sqrt(n); i++)
    {
        if (check[i]==true)
        {
            int j=i*i;
            while (j <= n)
            {
                check[j]=false;
                j+=i;
            }
        }
    }
    //in ra giá trị mảng true
    for (int i=2; i<=n; i++)
        if (check[i]==true) cout<<i;
}
