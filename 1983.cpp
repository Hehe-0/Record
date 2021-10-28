#include<bits/stdc++.h>

using namespace std;
const int N=2048;

int n,m;
int head[N],nxt[N<<14],to[N<<14];
int _;
void add(int x,int y)
{
	_++;
	nxt[_]=head[x];
	head[x]=_;
	to[_]=y;
	return ;
}

int ind[N],dep[N],is[N];
int ans;
queue<int > q;
int vis[N][N];
int cnt;
void topsort()
{
	for(int i=1;i<=n;i++)
	if(!ind[i])
	{
		dep[i]=1;
		q.push(i);
	}
	
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();	
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			dep[y]=dep[x]+1;
			ans=max(ans,dep[y]);
			ind[y]--;
			if(!ind[y])
			q.push(y);
		}
	}
	
	return ;
}
int a[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=m;i++)	
	{
		memset(a,0,sizeof(a));
		memset(is,0,sizeof(is));
		int x;
		cin>>x;
		for(int j=1;j<=x;j++)	
		{	
			cin>>a[j];
			is[a[j]]=1;
		}
		for(int j=a[1]+1;j<=a[x];j++)
		{
			if(!is[j])
			{
				for(int u=1;u<=x;u++)
				{
					if(!vis[j][a[u]])
					{
						ind[a[u]]++;
						add(j,a[u]);
						vis[j][a[u]];
					}
					
				}
			}
			
		}
	}
	topsort();
	
	cout<<ans;
	return 0;
}
