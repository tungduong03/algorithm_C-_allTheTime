#include <bits/stdc++.h>
using namespace std;
int main()
{
    //Nhập n và phân tích n thành tích thừa số nguyên tố
    int n;
    cin>>n;
    int k=2;
    while (n>1)
    {
        while (n%k==0)
        if (n%k==0) cout<<k<<" ", n=n/k;
        k++;
    }

}
