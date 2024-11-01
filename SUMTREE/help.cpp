#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    for (int i=10; i<=99; i++)
    {
        int a=i%10+i/10;
        if (a==n) cout<<i<<" ";
    }
}
