#include<bits/stdc++.h>

using namespace std;
const int N=1e4+2;

//
//int match[N];//,nxt[N<<1],to[N<<1];
//int v[N];
int n,m,e,ans,match[N];
bool a[N][N], v[N];
//int a[N][N];

int _;



bool dfs(int x)//可行增广路 
{
	for(int i=1;i<=m;i++)
	{
		if(!v[i]&&a[x][i])
		{
			v[i]=1;
			if(!match[i]||dfs(match[i]))
			{
				match[i]=x;
				return 1;
			}
		}
		
	}
	return 0;	
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>e;
	for(int i=1;i<=e;i++)
	{
		int q,w;
		cin>>q>>w;
	//	add(q,w);
	//	add(w,q);
	a[q][w]=1;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=dfs(i);
		
		memset(v,0,sizeof(v));
	}
	
	
	cout<<ans;
	
	return 0;
}
