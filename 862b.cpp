#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+6;

int n,m;
int head[N<<1],nxt[N<<1],to[N<<1];
int dep[N<<1];

int _;
void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}

void dfs(int x,int fa,int deep)
{
	dep[x]=deep;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		continue;
		
		dfs(y,x,deep+1);
	}
	
	
	return ;
}

int ans1,ans2;

signed main(){
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int q,w;
		cin>>q>>w;
		add(q,w);
		add(w,q);
	}
	dfs(1,0,0);
	for(int i=1;i<=n;i++)
	{
		if(dep[i]&1)
		ans1++;
		else
		ans2++;
	}
	cout<<ans1*ans2-(n-1);
	return 0;
}
