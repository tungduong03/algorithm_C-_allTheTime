#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("MaMorse1.INP","r",stdin);
    freopen("MaMorse1.OUT","w",stdout);
    string Str_Morse;
    getline(cin,Str_Morse);
    string Str_decode="";
    for (int i=0; i< Str_Morse.size(); i++)
    {
        if (Str_Morse[i]=='X') Str_decode+="-";
        if (Str_Morse[i]=='Y') Str_decode+=".";
        if (Str_Morse[i]==' '  || Str_Morse[i]=='_') Str_decode+=" ";
    }
    cout<<Str_decode;
}

