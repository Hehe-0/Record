#include<bits/stdc++.h>

using namespace std;

int head[222],nxt[222],to[222],edge[222];
int dp[123][321];
int siz[123];
int n,m;

int _;
void add(int x,int y,int z)
{
	_++;
	to[_]=y;
	edge[_]=z;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}

void makedp(int x,int fa)
{
	siz[x]++;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i],z=edge[i];
		if(y==fa)continue;
		makedp(y,x);
		siz[x]=siz[y]+1;
		
		for(int j=m;j;j--)
		{
			for(int k=j-1;k>=0;k--)
			dp[x][j]=max(dp[x][j],dp[x][j-k-1]+dp[y][k]+z);	
		}
		
		
	}
	
	
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<n;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		add(q,w,e);
		add(w,q,e);
	}
	makedp(1,0);
	
	cout<<dp[1][m];
	
	return 0;
}
