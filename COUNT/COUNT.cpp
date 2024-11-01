#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    // Nếu a = 0 => ucln(a,b) = b
    // Nếu b = 0 => ucln(a,b) = a
    while (a != b){
        if (a > b){
            a -= b; // a = a - b
        }else{
            b -= a;
        }
    }
    return a; // return a or b, bởi vì lúc này a và b bằng nhau
}
int main()
{
    int n, p[12];
    cin>>n;
    for (int i=1; i<=n; i++) cin>>p[i];
    for (int i=1; i<=n; i++)
    {   int dem=1;
        for (int j=2; j<=p[i]; j++)
        if ( gcd(j,p[i]) == 1 ) dem++;
        cout<<dem<<endl;
    }

}
