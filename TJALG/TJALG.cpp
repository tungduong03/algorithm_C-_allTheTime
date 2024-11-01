#include <bits/stdc++.h>
#define N 100005
#define oo 0x3c3c3c3c
using namespace std;
int n,m;
int Num[N],Low[N],cnt=0;
vector <int> a[N];
stack<int> st;
int Count=0;

void read()
{
    freopen("TJALG.INP","r",stdin);
    freopen("TJALG.OUT","w",stdout);
}
void visit(int u)
{
    Low[u]=Num[u]=cnt++;
    st.push(u);
    for (int i=0; int v=a[u][i]; i++)
        if (Num[v])
            Low[u]=min( Num[v], Low[u]);
        else {
            visit(v);
            Low[u]=min( Low[u], Low[v]);
        }
    if (Num[u]==Low[u]) {
            Count++;
            int v;
            do {
            v=st.top(); st.pop();
            Num[v]=Low[v]=oo; // remove v from graph
            } while (v!=u);
    }
}
int main()
{
    read();
    cin>>n>>m;
    for (int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for (int i=1; i<=n ;i++)
        a[i].push_back(0);

    for (int j=1; j<=n; j++)
    if (!Num[j]) visit(j);
    cout<<Count<<endl;
}
