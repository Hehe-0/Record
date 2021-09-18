#include<bits/stdc++.h>

using namespace std;
const int N=1011;

int head[N],nxt[N<<1],to[N<<1],edge[N<<1];
int _;
void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
int n;
int cnt,ans;
int f[N],dep[N];
void dfs(int x,int fa,int deep)
{
	f[x]=fa;
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
int vis[N];
void dfs1(int x,int deep)
{
	if(deep>2)
	return ;
	vis[x]=1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		dfs1(y,deep+1);
	}
	return ;
}

struct cmp
{
    bool operator ()(int &a,int &b)
	{
        return dep[a]<dep[b];
    } 
};
priority_queue<int,vector<int>,cmp> q;

signed main()
{
 	ios::sync_with_stdio(false);
	cin>>n;
	cnt=n;
	
	for(int i=1;i<n;i++)
	{
		int w;
		cin>>w;
		add(w,i+1);
		add(i+1,w);
	}
	dfs(1,0,1);
	
	for(int i=1;i<=n;i++)
	q.push(i);
	int x;
	while(!q.empty())
	{
		while(!q.empty()&&vis[x=q.top()])
		q.pop();
		if(q.empty())
		break;
		
		if(f[f[x]])
		dfs1(f[f[x]],0);
		else
		dfs1(1,0);
		ans++;
	}
	
	cout<<ans;
	return 0; 	
}














