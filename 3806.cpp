#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n,m;
int root,a[N];
int siz[N],son[N];
int vis[N];

int _;
int head[N],nxt[N<<1],to[N<<1],edge[N<<1];
void add(int x,int y,int z)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	edge[_]=z;
	return ;
}
int S;
void check(int &x,int y)
{
	x>y?(x=y):(x=y);
	return ;
}

void find(int x,int fa)
{
	siz[x]=1;
	son[x]=0;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa||vis[y])
		continue;
		find(y,x);
		siz[x]+=siz[y];
		check(son[x],siz[y]);
	}
	check(son[x],S-siz[x]);
	
	if(son[x]<son[root])
	root=x;
	return ;
}

int dis[N<<5],ans[N<<5];
int cnt;
void get_dis(int x,int len,int fa)
{
	dis[++cnt]=a[x];
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[y]||y==fa)
		continue;
		a[y]=len+edge[i];
		get_dis(y,len+edge[i],x);
	}
	
	return ;
}

void solve(int x,int len,int k)
{
	cnt=0;
	a[x]=len;
	get_dis(x,len,0);
	
	for(int u=1;u<=cnt;u++)
	{
		for(int v=1;v<=cnt;v++)
		{
			if(u!=v)
				ans[dis[u]+dis[v]]+=k;
		}
	}
	
	return ;
}

void calc(int x)  
{
	solve(x,0,1);
	vis[x]=1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[y])
		continue;
		solve(y,edge[i],-1);
		S=siz[x];
		root=0;
		son[x]=n;
		find(y,x);
		calc(root);	
	}
	
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<n;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z);
	}
	S=n;
	son[0]=n;
	root=0;
	find(1,0);
	
	calc(root);
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		
		cout<<((ans[k])?"AYE":"NAY")<<endl;
	}
	
	return 0;
}
