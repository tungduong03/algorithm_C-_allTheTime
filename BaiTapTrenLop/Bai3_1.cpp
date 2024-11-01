#include <bits/stdc++.h>
using namespace std;
void nhap(int a[], int &n)
{
    for (int i=1; i<=n; i++)
        cout<<"Nhap phan tu a["<<i<<"]: ", cin>>a[i];
}
void hienthi(int a[], int &n)
{
    for (int i=1; i<=n; i++)
        cout<<"Phan tu a["<<i<<"] la "<<a[i]<<endl;
}
void kiemtra(int a[],int &n)
{
    int nho=0;
    for (int i=1; i<=n; i++)
        if (a[i]<=10) nho=1;
    if (nho==0) cout<<"Mang co cac phan tu deu lon hon 10";
    else cout<<"Mang co phan tu be hon hoac bang 10";
    cout<<endl;
}
void xoa_chan(int a[], int &n)
{
    cout<<"Mang a xoa cac phan tu chan: "<<endl;
    for (int i=1; i<=n; i++)
        if (a[i]%2 != 0) cout<<a[i]<<" ";
    cout<<endl;
}
void tach(int a[], int &n)
{
    int b[1000], c[1000],dem_b=1, dem_c=1;
    for (int i=1; i<=n; i++)
        if (a[i]%3==0) b[dem_b]=a[i], dem_b++;
        else c[dem_c]=a[i], dem_c++;
    cout<<"Mang b: "<<endl;
    for (int i=1; i<dem_b; i++) cout<<b[i]<<" ";
    cout<<endl;
    cout<<"Mang c: "<<endl;
    for (int i=1; i<dem_c; i++) cout<<c[i]<<" ";
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Nhap so phan tu mang a: "; cin>>n;
    int *a = new int[n];
    nhap(a, n);
    hienthi(a, n);
    kiemtra(a,n);
    xoa_chan(a,n);
    tach(a,n);
    delete[] a;

}
