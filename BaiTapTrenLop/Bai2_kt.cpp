#include <bits/stdc++.h>
using namespace std;
void nhap(string *s)
{
    cout<<"Nhap chuoi: "<<endl;
    cin>>*s;
}
void xuat(string *s)
{
    cout<<*s<<endl;
}
void kiemtra(string *s, int &n)
{
    int dem=0;
    cout<<"So ki tu thuong: ";
    for (int i=0; i< n; i++)
        if (int((*s)[i]>=97) && int((*s)[i]<=122)) dem++;
    cout<<dem<<endl;
}
void delete_h(string *s, int &n)
{
    string st="";
    cout<<"Xau sau khi xoa ki tu h: ";
    for (int i=0; i< n; i++)
        if (int((*s)[i]) !=104)
            st+=(*s)[i];
    *s=st;
    cout<<*s<<endl;
}
int main()
{
    string s;
    nhap(&s);
    int n= s.length();
    xuat(&s);
    kiemtra(&s, n);
    delete_h(&s, n);
}
