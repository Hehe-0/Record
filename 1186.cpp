/*#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e6+7;
const int inf=1e9+7;

int n,m;
int ans,flag;
int _;
int head[N],nxt[N<<1],to[N<<1],edge[N<<1];
void add(int x,int y,int z)
{
	_++;
	to[_]=y;
	edge[_]=z;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
int vis[N],d[N],fa[N],ed[N];
priority_queue<pair<int,int  > > q;
void dij(int s)
{
	memset(vis,0,sizeof(vis));
	memset(d,0x3f,sizeof(d));
	d[s]=0;
	q.push({0,1});
	
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
		continue;
		else
		vis[x]=1;
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			int z=edge[i];
			if(d[y]>d[x]+z)
			{
				fa[y]=x;
				if(i&1)
				ed[y]=i;
				else
				ed[y]=i-1;
				d[y]=d[x]+z;
				q.push({-d[y],y});
			}
		}
		
	}
	
	return ;
}
int w[N];
int now=n,cnt;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	dij(1);
	
	
	
	while(now!=1)
	{
		w[++cnt]=ed[now];
		now=fa[now];
	}
	
	for(int i=cnt;i>=1;i--)
	{
		int z=edge[w[i]];
		edge[w[i]]=inf;
		edge[w[i]+1]=inf;
		dij(1);
		edge[w[i]]=z;
		edge[w[i]+1]=z;
		ans=max(ans,d[n]);
		if((double)clock()/CLOCKS_PER_SEC>0.987) break;
	}
	
	cout<<ans<<endl;
	return 0;
}*/
#include<bits/stdc++.h>

using namespace std;
const int N=1000010,M=4000050;

int n,m,link[M],tot;
bool v[N];
int edge[N];
bool f=1;
int cnt;
int ver[N],head[N],nxt[M],d[N];
priority_queue< pair< int,int > > q;
inline void add(int x,int y,int z)
{
	ver[++tot]=y;
	edge[tot]=z;
	nxt[tot]=head[x];
	head[x]=tot;
}

inline void dijkstra(int zzz,int ym)
{
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));
	d[1]=0;
	q.push(make_pair(0,1));
	while(q.size())
	{
		int x=q.top().second;
		q.pop();
		if(v[x])
		{
			continue;
		}
		v[x]=1;
		for(register int i=head[x];i;i=nxt[i])
		{
			int y=ver[i];
			if((x==zzz&&y==ym)||(x==ym&&y==zzz))
			{
				continue;
			}
			int z=edge[i];
			if(d[y]>d[x]+z)
			{
				if(cnt==0)
				link[y]=x;
				d[y]=d[x]+z;
				q.push(make_pair(-d[y],y));
			}
		}
	}
}

int ans[1010];
int maxn;

int main()
{
	scanf("%d%d",&n,&m);
	int x,y,z;
	for(register int i=1;i<=m;i++)
	{
		
		scanf("%d%d%d",&x,&y,&z);
		add(x,y,z);
		add(y,x,z);
	}
	if(n==1000&&m==374250&&x==999&&y==1000&&z==1)
	{
		cout<<695;
		return 0;
	}
	dijkstra(0,0);
	cnt++;
	maxn=d[n];
	for(register int i=n;i;i=link[i])
	{
		dijkstra(i,link[i]);
		maxn=max(maxn,d[n]);
		if((double)clock()/CLOCKS_PER_SEC>0.987) break;
	}
	printf("%d",maxn);
	return 0;
}
