#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;

int _;
int head[N],nxt[N<<4],to[N<<4],edge[N<<4];
void add(int x,int y,int z)
{	
	_++;
	nxt[_]=head[x];
	head[x]=_;
	to[_]=y;
	edge[_]=z;
	return ;
}
int n,m;
int dfn[N],low[N];
int ind[N],col[N];
bool vis[N];
stack<int > s;
int x[N<<3],y[N<<3],z[N<<3];
int cnt;
int tot;
void dfs(int x)
{
	low[x]=dfn[x]=++cnt;
	vis[x]=1;
	s.push(x);
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(!dfn[y])
		{
			dfs(y);
			low[x]=min(low[x],low[y]);
		}
		else if(vis[y])
		low[x]=min(low[x],dfn[y]);
	}
	if(dfn[x]==low[x])
	{
		tot++;
		col[x]=tot;
		vis[x]=0;
		
		while(s.top()!=x)
		{
			col[s.top()]=tot;
			vis[s.top()]=0;
			s.pop();
		}
		s.pop();
	}
	
	return ;
}
int d[N];
bool v[N];
priority_queue< pair<int ,int > > q;
void dij()
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	q.push({0,col[1]});
	d[col[1]]=0;
	
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])
		continue;
		else
		v[x]=1;
		
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(d[y]>d[x]+edge[i])
			{
				d[y]=d[x]+edge[i];
				q.push({-d[y],y});
				
			}
		}
	}
	
	
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x[i]>>y[i]>>z[i];
		add(x[i],y[i],z[i]);
	}
	for(int i=1;i<=n;i++)
	{
		if(!dfn[i])
		dfs(i);
	}
	memset(head,0,sizeof(head));
	_=0;
	for(int i=1;i<=m;i++)
	if(col[x[i]]!=col[y[i]])
	add(col[x[i]],col[y[i]],z[i]);
	dij();
	
	
	cout<<d[col[n]];
	return 0;
}
