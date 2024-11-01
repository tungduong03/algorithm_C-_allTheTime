#include <bits/stdc++.h>
using namespace std;
int main()
{
    float x,y,a,b,r;
    cout<<"Nhap x: "; cin>>x;
    cout<<"Nhap y: "; cin>>y;
    cout<<"Nhap a: "; cin>>a;
    cout<<"Nhap b: "; cin>>b;
    cout<<"Nhap r: "; cin>>r;
    if ( (a-x)*(a-x)+ (b-y)*(b-y) <= r*r ) cout<<"z= "<<abs(x)+abs(y);
    else cout<<"z= "<<x+y;

}
