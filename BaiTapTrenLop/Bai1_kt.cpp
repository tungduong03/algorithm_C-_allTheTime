#include <bits/stdc++.h>
using namespace std;
void hienthi(int a[], int &n)
{
    cout<<"Mang da cho la: ";
    for (int i=1; i<=n; i++) cout<<a[i]<<" ";
    cout<<endl;
}
void Sum_3(int a[], int &n)
{
    int sum=0;
    cout<<"Tong cac phan tu duong va chia het 3: ";
    for (int i=1; i<=n; i++)
        if (a[i]>0 && a[i]%3==0) sum+=a[i];
    cout<<sum<<endl;
}
void sort_a(int a[], int &n)
{
    sort(a+1,a+1+n);
    cout<<"Day sau khi sap xep: ";
    for (int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
void delete_x(int a[], int &n, int &x)
{
    int dem=1,b[30];
    cout<<"Day sau khi xoa cac phan tu be hon x: ";
    for (int i=1; i<=n; i++)
        if (a[i]>=x) b[dem]=a[i],dem++;
    for (int i=1; i<dem; i++)
        cout<<b[i]<<" ";
    cout<<endl;
}
int main()
{

    int n;
    cout<<"Nhap n: "; cin>>n;
    int *a= new int[n+1];
    int *c= new int[n+1];
    for (int i=1; i<=n; i++) cout<<"Nhap a["<<i<<"]: ",cin>>a[i],c[i]=a[i];
    hienthi(a, n);
    Sum_3(a, n);
    sort_a(a, n);
    int x;
    cout<<"Nhap x: "; cin>>x;
    delete_x(a, n, x);
    freopen("BT1.txt","w", stdout);
    hienthi(c, n);
    Sum_3(c, n);
    sort_a(c, n);
    delete_x(c, n, x);
}
