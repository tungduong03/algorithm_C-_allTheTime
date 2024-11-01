#include <bits/stdc++.h>
using namespace std;

void nhap(int a[100][100], int &n, int &m)
{
    cout<<"Nhap so hang: "; cin>>m;
    cout<<"Nhap so cot: "; cin>>n;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) cin>>a[i][j];
}
void xuat(int a[100][100], int &n, int &m)
{
    cout<<"ma tran: "<<endl;
    for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
}
void tim_maxx(int a[100][100], int &n, int &m)
{
    int maxx=a[1][1];
    cout<<"phan tu max: ";
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (a[i][j]>maxx) maxx=a[i][j];
    cout<<maxx<<endl;
}
void doi_hang1_voi_hang2(int a[100][100], int &n, int &m)
{
    //doi hang 1 voi hang 2
    cout<<"Ma tran khi doi hang 1 voi hang 2: "<<endl;
    for (int i=1; i<=n; i++)
    {
        int doi;
        doi=a[2][i];
        a[2][i]=a[1][i];
        a[1][i]=doi;
    }
    for (int i=1; i<=m; i++)
        {
            for (int j=1; j<=n; j++) cout<<a[i][j]<<" ";
            cout<<endl;
        }
}
int main()
{
    int n,m,a[100][100];
    nhap(a, n,m);
    xuat(a,n,m);
    tim_maxx(a,n,m);
    doi_hang1_voi_hang2(a,n,m);
}

