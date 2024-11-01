#include <bits/stdc++.h>
using namespace std;
int nho=0;
void nhap(double a[],int &n)
{
    cout<<"nhap n: "; cin>>n;
    for (int i=0; i<n; i++) cout<<"nhap a["<<i<<"]: ",cin>>a[i];
}
void check_day(double a[], int &n)
{
    int dem1=1,dem2=1,dem3=1,dem4=1;
    for (int i=0; i<=n-2; i++)
    {
        if (a[i] <=a[i+1]) dem1++;
        if (a[i] < a[i+1]) dem2++;
        if (a[i] >=a[i+1]) dem3++;
        if (a[i] > a[i+1]) dem4++;
    }

    if (dem2==n) cout<<"Day tang ngat",nho=1;
    else if (dem1==n) cout<<"Day tang",nho=1;
    if (dem4==n) cout<<"Day giam ngat",nho=1;
    else if (dem3==n) cout<<"Day giam",nho=1;
}
void sapxep(double a[], int &n)
{
    if (nho==0)
    {
        cout<<"Day da duoc sap xep: "<<endl;
        sort(a, a+n);
        for (int i=0; i<n; i++) cout<<a[i]<<" ";
    }

}
int main()
{
    int n;
    double a[10001];
    nhap(a, n);
    check_day(a, n);
    sapxep(a, n);
}
