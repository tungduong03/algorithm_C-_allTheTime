#include <bits/stdc++.h>
using namespace std;

string num_glo;
int number, mem = 0;

map <string, int> moneyTran;

vector<string> a;

map <string, vector<string> > from_bank;

int convertMoney(string money){
    int mon = 0;
    for (int i = 0; i < money.size(); i++ ){
        mon = mon*10 + int(money[i])-48;
    }
    return mon;
}

void solve(string num){
    if (num == num_glo && mem == 0) cout<<1, mem = 1;
}

void TRY(int v, string num){
    for (int i = 0; i < from_bank[num].size(); i++){
        if (v==number) {
            solve(from_bank[num][i]);
        }
        else TRY(v+1, from_bank[num][i]);
    }


}

int main(){
    freopen("Bank Transaction.inp", "r", stdin);
    freopen("Bank Transaction.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string type;
    int totalTran = 0, totalMoneyTran = 0;

    do {
        cin>>type;
        if (type == "#") continue;
        ++totalTran;

        string fbank, tbank, money, ftime, bank;
        fbank = type;
        cin >> tbank >> money >> ftime >> bank;

        totalMoneyTran+=convertMoney(money);

        //numberTran[fbank]++;
        moneyTran[fbank]+=convertMoney(money);

        a.push_back(fbank);
        a.push_back(tbank);

        from_bank[fbank].push_back(tbank);
    }
    while (type!="#");


    do {
        cin >> type;

        if (type == "#") continue;
        if (type == "?number_transactions")
            cout<<totalTran<<endl;

        if (type == "?total_money_transaction") {
            cout<<totalMoneyTran<<endl;
        }

        if (type == "?list_sorted_accounts") {
            sort(a.begin(), a.end());
            for (int i = 0; i < a.size(); i++){
                if (a[i] != a[i+1]) cout<<a[i]<<" ";
            }
            cout<<endl;
        }
        if (type == "?total_money_transaction_from") {
            cin >> num_glo;
            cout << moneyTran[num_glo] << endl ;
        }

        if (type == "?inspect_cycle"){
            cin>>num_glo;
            cin>>number;
            TRY(1, num_glo);
        }
    }
    while (type != "#");


}
