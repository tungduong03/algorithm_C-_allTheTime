#include <bits/stdc++.h>
using namespace std;
void nhap(int &n, double &x)
{
    cout<<"Nhap so nguyen: "; cin>>n;
    cout<<"Nhap so thuc: "; cin>>x;
}
void xuat(int *ptr_n, double *ptr_x)
{
    cout<<"dia chi cua so nguyen: "<<ptr_n<<" gia tri so nguyen: "<<*ptr_n;
    cout<<endl;
    cout<<"dia chi cua so thuc: "<<ptr_x<<" gia tri so thuc: "<<*ptr_x;
}
int main()
{
    int n;
    double x;
    nhap(n,x);
    xuat(&n, &x);
}

