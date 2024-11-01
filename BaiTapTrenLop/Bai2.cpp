#include <bits/stdc++.h>
using namespace std;
void nhap(int a[],int &n)
{

    cout<<"nhap n: "; cin>>n;
    for (int i=1; i<=n; i++) cout<<"nhap a["<<i<<"]: ",cin>>a[i];
}
void xuat(int a[],int &n)
{
    cout<<"Cac phan tu trong mang: "<<endl;
    for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}
void sochanchiahet3(int a[], int &n)
{
    for (int i=1; i<=n; i++)
    {
        if (a[i]%2==0 & a[i]%3==0) cout<<"So chan chia het 3: "<<a[i]<<" vi tri "<<i<<endl;
    }
}
void sapxep(int a[], int &n)
{
    sort(a+1, a+1+n);
    cout<<"Mang A sap xep theo thu tu tang dan: ";
    for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}
void chenX(int a[],int &n)
{
    int x;
    cout<<"So x can chen: ";
    cin>>x;
    cout<<"Mang A sau khi chen x: ";
    for (int i=1; i<=n; i++)
    {
        if (a[i]%2==0)
            cout<<a[i]<<" "<<x<<" ";
        else cout<<a[i]<<" ";
    }
}
int main()
{
    int n, a[41];
    nhap(a, n);
    xuat(a, n);
    sochanchiahet3(a, n);
    sapxep(a, n);
    chenX(a, n);
}
