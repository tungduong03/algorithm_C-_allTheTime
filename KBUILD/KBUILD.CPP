#include<bits/stdc++.h>
#define N 25005
#define M 15
using namespace std;
int n;
vector<int> a[N];
int hi[N], par[N][M+3];
bool xet[N][N];
void DFS(int u)
	{
		for (int i=0; i < a[u].size(); i++)
			if (a[u][i] != par[u][0])
				{
					int v=a[u][i];
					hi[v]=hi[u]+1;
					par[v][0]=u;
					DFS(v);
				}
	}
void ini()
	{
		DFS(1);
		for (int j=1; j <= M; j++)
			for (int i=1; i <= n; i++)
				par[i][j]=par[par[i][j-1]][j-1];
		hi[0]=-1;
	}
int getLCA(int u, int v)
	{
		if (hi[u] < hi[v])
			return getLCA(v,u);
		for (int i=M; i >= 0; i--)
			if (hi[par[u][i]] >= hi[v])
				u=par[u][i];
		if (u == v)
			return u;
		for (int i=M; i >= 0; i--)
			if (par[u][i] != par[v][i])
				{
					u=par[u][i];
					v=par[v][i];
				}
		return par[u][0];
	}
int main()
{
#ifndef ONLINE_JUDGE
	ifstream cin("KBUILD.INP");
	ofstream cout("KBUILD.OUT");
#endif
	ios::sync_with_stdio(0);
	cin.tie(NULL);
			memset(hi,0,sizeof hi);
			memset(par,0,sizeof par);
			memset(xet, false, sizeof xet);
			cin>>n;
			for (int i=1; i < n; i++)
				a[i].clear();
			for (int i=1; i < n; i++)
				{
                        int u,v;
                        cin>>u>>v;
                        a[v].push_back(u);
                        a[u].push_back(v);
                        xet[u][v]=true;
                        xet[v][u]=true;
				}
			ini();
			int q;
			cin>>q;
			while (q--)
				{
					int u,v;
					cin>>u>>v;
					int LCA=getLCA(u,v);
					while (u!=LCA)
                        {if (xet[u][par[u][0]])
                        {
                         xet[u][par[u][0]]=false;
                         xet[par[u][0]][u]=false;
                         n--;
                        }
                         u=par[u][0];
                        }
                    u=v;
                    while (u!=LCA)
                        {if (xet[u][par[u][0]])
                        {
                         xet[u][par[u][0]]=false;
                         xet[par[u][0]][u]=false;
                         n--;
                        }
                         u=par[u][0];
                        }
				}
    cout<<n-1;
	return 0;
}











