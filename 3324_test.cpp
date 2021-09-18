#include<bits/stdc++.h>
using namespace std;
const int N=2000;
const int M=50000;
int cnt=1,head[N],nxt[M],ver[M];
long long edge[M];
void addedge(int x,int y,long long z)
{
	ver[++cnt]=y;
	edge[cnt]=z;
	nxt[cnt]=head[x];
	head[x]=cnt;
}
void add(int x,int y,long long z)
{
	addedge(x,y,z);
	addedge(y,x,0);
}
int d[N];
int s,t;
bool bfs()
{
	memset(d,0,sizeof d);
	queue<int> q;
	d[s]=1;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			long long z=edge[i];
			if(!d[y]&&z>0)
			{
				d[y]=d[x]+1;
				q.push(y);
				if(y==t)return true;
			}
		}
	}
	return false;
}
long long dfs(int x,long long flow)
{
	long long re=flow;
	if(x==t)
	return flow;
	
	for(int i=head[x];i;i=nxt[i])
	{
		long long y=ver[i],z=edge[i];	
		if(!re)
		return flow;
		
		if(z&&d[y]==d[x]+1)
		{
			long long k=dfs(y,min(re,z));
			if(!k)
			d[y]=0;
			
			edge[i]-=k;
			edge[i^1]+=k;
			re-=k;
		}
		
	}	
	
	return flow-re;
}
long long dinic()
{
	long long res=0;
	while(bfs())
	{
		res+=dfs(s,1e15);
	}
	return res;
}
int n,m;
long long hp[N],atk[N];
long long sum;
int x[N][N];
void init()
{
	memset(head,0,sizeof head);
	memset(nxt,0,sizeof nxt);
	memset(ver,0,sizeof ver);
	memset(edge,0,sizeof edge);
	cnt=1;
}
void build(long long tim)
{
	for(int i=1;i<=m;i++)
	{
		add(s,i,tim*atk[i]);
	}
	for(int i=1;i<=n;i++)
	{
		add(i+m,t,hp[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i][j])
			{
				add(i,j+m,1e15);
			}
		}
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	s=0,t=n+m+1;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&hp[i]);
		hp[i]*=10000ll;
		sum+=hp[i];
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%lld",&atk[i]);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			scanf("%d",&x[i][j]);
		}
	}
	long long l=0,r=100000000000ll;
	while(l<r)
	{
		long long mid=((l+r)>>1ll);
		init();
		build(mid);
		long long ans=dinic();
		if(ans<sum)l=mid+1;
		else 	   r=mid;
	}
	printf("%.4f",(double)l/10000.0);
	return 0;
}
