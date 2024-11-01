#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("Parentheses.inp","r", stdin);
    string str;
    cin>>str;
    vector<int> s;
    int i=0;
    bool bol = true;
    //if (str.length()%2==1) bol=0;
    while (i<str.length() && bol){
        if (str[i]=='(') {
            s.push_back(1);
        }
        if (str[i]=='[') {
            s.push_back(2);
        }
        if (str[i]=='{') {
            s.push_back(3);
        }
        if (str[i]==')') {
            if (s[s.size()-1]==1) s.pop_back();
            else bol=0;
        }
        if (str[i]==']') {
            if (s[s.size()-1]==2) s.pop_back();
            else bol=0;
        }
        if (str[i]=='}') {
            if (s[s.size()-1]==3) s.pop_back();
            else bol=0;
        }
        i++;
    }
    if (bol && s.empty()) cout<<1;
    else cout<<0;
}
