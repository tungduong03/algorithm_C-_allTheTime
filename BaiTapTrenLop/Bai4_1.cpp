#include <bits/stdc++.h>
using namespace std;
void nhap(double a[], int &n)
{
    for (int i=0; i<n; i++)
        cout<<"Nhap phan tu a["<<i+1<<"]: ", cin>>a[i];
}
void hienthi(double a[], int &n)
{
    for (int i=0; i<n; i++)
        cout<<"Phan tu a["<<i<<"] la "<<a[i]<<endl;
}
void kiem_tra_X(double a[],int &n)
{
    double x;
    int dem=0;
    cout<<"Nhap X: "; cin>>x;
    for (int i=0; i<n; i++)
        if (a[i]==x) dem++;
    cout<<dem<<endl;
    for (int i=0; i<n; i++)
        if (a[i]==x) cout<<"Vi tri thu "<<i+1<<endl;
}
bool check_snt(int b)
{
    for (int j=2; j<b; j++)
        if (b%j==0) return false;
    return true;
}
void hienthi_snt(double a[], int &n)
{
    cout<<"Cac phan tu nguyen to cua mang a: "<<endl;
    for (int i=0; i<n; i++)
        if (check_snt(int(a[i]))) cout<<int(a[i])<<" ";
    cout<<endl;
}
void chen(double a[], int &n)
{
    double k;
    cout<<"Nhap so k: "; cin>>k;
    for (int i=0; i<n; i++)
        if (i==1) cout<<k<<" "<<a[i]<<" ";
        else cout<<a[i]<<" ";
}
int main()
{
    int n;
    cout<<"Nhap so phan tu mang a: "; cin>>n;
    double *a = new double[n+1];
    nhap(a, n);
    hienthi(a, n);
    kiem_tra_X(a,n);
    hienthi_snt(a,n);
    chen(a,n);
    delete[] a;
    a=NULL;
}
