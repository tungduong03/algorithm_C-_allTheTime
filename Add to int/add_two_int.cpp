#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string a, b;
    cin>>a>>b;


    if (b.length() > a.length()) {
        string str = a;
        a = b;
        b = str;
    }

    int nLen1 = a.length(), nLen2 = b.length();
    //cout<<nLen1;
    int remember=0;
    string sol="";
    for (int i=0; i < nLen2; i++)
    {
        int temp = (a[nLen1 - i - 1] - '0') + (b[nLen2 - i - 1] - '0') + remember;
        //cout<<temp;
        if (temp >= 10) remember = 1, temp=temp-10;
        else remember = 0;
        sol = to_string(temp) + sol;
    }
    int i = nLen2;
    //cout<<nLen2<<" "<<nLen1<<endl;
    while (i < nLen1){
        int temp = (a[nLen1 - i - 1] - '0') + remember;
        //cout<<temp;
        if (temp >= 10) remember = 1, temp=temp-10;
        else remember = 0;
        sol = to_string(temp) + sol;
        i++;
    }
    if (remember == 1) sol = '1'+sol;
    cout<<sol;
}
