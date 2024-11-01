#include <bits/stdc++.h>
using namespace std;
int main(){
    string str;
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("SimulationStack.INP","r",stdin);
    cin>>str;
    vector<int> s;
    while (str!="#"){
        if (str=="PUSH"){
            int x;
            cin>>x;
            s.push_back(x);
        }
        if (str=="POP"){
            if (s.empty()) cout<<"NULL"<<endl;
            else {
                cout<<s[0]<<endl;
                vector<int>::iterator it;
                it = s.begin();
                s.erase(it);
            }
        }
        cin>>str;
    }

}
