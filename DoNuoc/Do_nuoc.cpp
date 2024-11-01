#include <bits/stdc++.h>
using namespace std;
int a=0,b=7,c=4, rel=0;
int X[11][11][11];
vector <int> res;
void Sol(int a, int b, int c){
    //rel=1;
    res.push_back(a);
    res.push_back(b);
    res.push_back(c);
}

void DFS(int a, int b, int c){
if (b==2 || c==2) rel=1;
if (X[a][b][c] != 1 && rel !=1){
    X[a][b][c] = 1;
    if (a>0 && b<7) {                               //đổ ca 1 sang 2
        if (a > (7-b) && rel !=1 && X[a-(7-b)][7][c]!=1) {
                a=a-(7-b); b=7;                //đổ đầy ca 2
                DFS(a,b,c);
                }
        if (a <= (7-b) && rel !=1 && X[0][b+a][c]!=1) {
                b=b+a; a=0;                    //đổ hết ca 1 sang 2
                DFS(a,b,c);
        }
    }
    if (a>0 && c<4) {                               //đổ ca 1 sang 3
        if (a > (4-c) && rel !=1  && X[a-(4-c)][b][4]!=1){
                a=a-(4-c); c=4;                //đổ đầy ca 3
                DFS(a,b,c);
            }
        if (a <= (4-c) && rel !=1 && X[0][b][c+a]!=1) {
                c=c+a; a=0;                    //đổ hết ca 1 sang 3
                DFS(a,b,c);
        }
    }
    if (b>0 && c<4) {                               //đổ ca 2 sang 3
        if (b > (4-c)  && rel !=1  && X[a][b-(4-c)][4]!=1) {
                b=b-(4-c); c=4;                //đổ đầy ca 3
                DFS(a,b,c);
        }
        if (b <= (4-c) && rel !=1  && X[a][0][c+b]!=1) {
                c=c+b; b=0;                    //đổ hết ca 2 sang 3
                DFS(a,b,c);
        }
    }
    if (b>0 && a<10) {                               //đổ ca 2 sang 1
        if (b > (10-a)  && rel !=1 && X[10][b-(10-a)][c]!=1) {
                b=b-(10-a); a=10;                //đổ đầy ca 1
                DFS(a,b,c);
        }
        if (b <= (10-a)  && rel !=1  && X[a+b][0][c]!=1) {
                a=a+b; b=0;                    //đổ hết ca 2 sang 1
                DFS(a,b,c);
        }
    }
    if (c>0 && a<10) {                               //đổ ca 3 sang 1
        if (c > (10-a)  && rel !=1 && X[10][b][c-(10-a)]!=1) {
                c=c-(10-a); a=10;                //đổ đầy ca 1
                DFS(a,b,c);
        }
        if (c <= (10-a)  && rel !=1  && X[a+c][b][0]!=1) {
                a=a+c; c=0;                    //đổ hết ca 3 sang 1
                DFS(a,b,c);
        }
    }
    if (c>0 && b<7) {                               //đổ ca 3 sang 2
        if (c > 7-b && rel !=1 && X[a][7][c-(7-b)]!=1) {
                c=c-(7-b); b=7;                //đổ đầy ca 2
                DFS(a,b,c);
        }
        if (c <= 7-b && rel !=1  && X[a][b+c][0]!=1) {
                b=b+c; c=0;                    //đổ hết ca 3 sang 2
                DFS(a,b,c);
        }
    }
}
if (rel==1) Sol(a,b,c);
}
int main(){
    cout<<0<<" "<<7<<" "<<4<<endl;
    DFS(a,b,c);
    while (res.size()>5){
        cout<<res[res.size()-3]<<" "<<res[res.size()-2]<<" "<<res[res.size()-1]<<endl;
        res.pop_back();
        res.pop_back();
        res.pop_back();
    }
}
