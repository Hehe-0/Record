#include<bits/stdc++.h>

using namespace std;
const int N=4004;

int n,m,t,k;
int dp[N][N];
int q[N]={1000000000};
int ans;
int head=1,tail=1;

int w;
void push(int x)
{
	while(head<=tail&&dp[w-1][x]>dp[w-1][q[tail]])
	tail--;
	q[++tail]=x;
	return ;	
}
int query(int x)
{
	if(x+t<=m)
	push(x+t);
	while(q[head]+t<x)
	head++;
	return q[head]; 
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>t;
	for(int i=1;i<=k;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		dp[x][y]=z;
	}
	
	for(w=2;w<=n;w++)
	{
		for(int i=1;i<=t;i++)		
		push(i);
		for(int j=1;j<=m;j++)
		dp[w][j]+=dp[w-1][query(j)];
		head=tail=1;
		q[1]=0;
	}
	
	for(int i=1;i<=m;i++)
	ans=max(ans,dp[n][i]);
		
	cout<<ans;
	return 0;
}
