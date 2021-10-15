#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=4e6+7;

int n,m,c;
int _;
int head[N>>3],nxt[N<<1],to[N<<1],edge[N<<1];
void add(int x,int y,int z)
{
	_++;
	nxt[_]=head[x];
	head[x]=_;
	to[_]=y;
	edge[_]=z;
	return ;
}

void addedges()
{
	for(int i=0;i<=n;i++)
	{
		for(int j=1;j<=n;j<<=1)
		{
			if((i^j)>n)
			continue;
			add(i,i^j,c*j);
		}
	}
	
	return ;
}

int vis[N],dis[N];
void dij(int s)
{
	priority_queue<pair<int ,int > >q;	
	q.push({0,s});
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	
	while(!q.empty())
	{
		int x=q.top().second;
		q.pop();
		if(vis[x])
		continue;
		vis[x]=1;
		
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			
			if(dis[y]>dis[x]+edge[i])
			{
				dis[y]=dis[x]+edge[i];
				q.push({-dis[y],y});
			}
			
		}
		
	}
	
	
	return ;
}
int st,ed;
signed main()
{
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>c;
	addedges();
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
	//	add(y,x,z);
	}
	cin>>st>>ed;
	dij(st);
	cout<<dis[ed];
	
	return 0;
}
