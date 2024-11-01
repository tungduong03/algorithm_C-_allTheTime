#include <bits/stdc++.h>
#define N 11
using namespace std;
int a[N][N], sol[N];
int n, maxx;
void Find_Node(int k)
{
	//tim la nho nhat 
	int node_min, i=1, node_par;
	bool bol=true;
	//cho i = 1 --> n, khi gap i chi co 1 lien ket thi ngat
	while (bol && i<=maxx)
	{
		int dem=0;
		for (int j=0; j<=maxx; j++)
		if (a[i][j] == 1) dem++,node_par=j;
		
		if (dem==1) {
			node_min=i;
			bol=false;
		}
		i++; 
	}
	//luu lai node
	sol[k]=node_par;
	//update xoa lien ket moi
	a[node_min][node_par]=0;
	a[node_par][node_min]=0;
}

int main()
{
	int b,c;
	//nhap n
	cin>>n;
	//tao mang lien ket giua cac node 
	for (int i=0; i<=N; i++) 
		for (int j=0; j<=N; j++) a[i][j]=0;
	//nhap lien ket giua cac node
	for (int i=1; i<=n; i++) {
		cin>>b>>c;
		a[b][c]=1;
		a[c][b]=1;
		if (b > maxx) maxx=b;
		if (c > maxx) maxx=c;
	}
	//xu li
	for (int k=1; k<=n-1; k++)
	{
		Find_Node(k);
		cout<<sol[k]<<" ";
	}
}
