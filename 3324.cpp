#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=50*50*50;

int head[N>>1],nxt[N<<1],to[N<<1],edge[N<<1];
int _=1;
int n,m;
void add(int x,int y,int z)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	edge[_]=z;
	_++;
	to[_]=x;
	nxt[_]=head[y];
	head[y]=_;
	edge[_]=0;
	
	return ;
}

int d[N],a[N];
int st,ed;
queue<int >q;
int ht[N],k[N>>2][N>>2];

bool bfs()
{
	memset(d,0,sizeof(d));
	
	q.push(st);
	d[st]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i],z=edge[i];
			
			if(!d[y]&&z>0)
			{
				d[y]=d[x]+1;
				
				q.push(y);
				if(y==ed)
				{
					while(q.size())
					q.pop();
					return 1;
				}
				
			}
		}
		
	}
	while(q.size())
		q.pop();	
	
	return 0;
}
int sum;
int dfs(int x,int flow)
{
	int re=flow;
	if(x==ed)
	return flow;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i],z=edge[i];	
		if(!re)
		return flow;
		
		if(z&&d[y]==d[x]+1)
		{
			int t=dfs(y,min(re,z));
			if(!t)
			d[y]=0;
			
			edge[i]-=t;
			edge[i^1]+=t;
			re-=t;
		}
		
	}	
	
	return flow-re;
}

int dinic()
{
	int re=0;
	
	while(bfs())
	{
		re+=dfs(st,1e16);
	}
	return re;
}

void init()
{
	memset(head,0,sizeof(head));
	memset(nxt,0,sizeof(head));
	memset(to,0,sizeof(head));
	memset(edge,0,sizeof(head));			
	_=1;
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	st=0,ed=n+1+m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>ht[i];
		ht[i]*=10000;
		sum+=ht[i];
		
	}
	for(int i=1;i<=m;i++)
	cin>>a[i];
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		cin>>k[i][j];
	}
	
	double l=0,r=N;
	
	while(l<r)
	{
		double mid=((l+r)/2);
		init();
		for(int i=1;i<=m;i++)
			add(st,i,mid*a[i]);
		for(int i=1;i<=n;i++)
			add(i+m,ed,ht[i]);
		
		for(int i=1;i<=m;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(k[i][j])
					add(i,j+m,1e16);
			}
		}
		int ans=dinic();
		if(ans<sum)
		l=mid+1;
		else
		r=mid;
	}
	
	cout<<(double)l/(10000.0);
	
	
	return 0;
}
