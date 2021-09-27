#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;
const int inf=1e9+7;

int _=1;
int head[N],nxt[N],to[N],l[N],f[N];
int now[N],a[N];
int n,k;
bool vis[N];
void add(int x,int y,int z,int c)
{
	_++;
	to[_]=y;
	f[_]=c;
	l[_]=z;
	nxt[_]=head[x];
	head[x]=_;
	_++;
	to[_]=x;
	f[_]=-c;
	l[_]=0;
	nxt[_]=head[y];
	head[y]=_;
	
	return ;
}
int dis[N],flow[N];
int pre[N],c[N];
queue<int >q;
bool spfa(int st,int ed)
{
	memset(dis,0x3f,sizeof(dis));
	q.push(st);
	dis[st]=0;
	flow[st]=inf;
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		vis[x]=0;
		
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(dis[y]>dis[x]+f[i]&&l[i])
			{
				dis[y]=dis[x]+f[i];
				pre[y]=i;
				flow[y]=min(flow[x],l[i]);
				if(!vis[y])
				{
					vis[y]=1;
					q.push(y);
				}
			}
		}
	}
	
	
	return dis[ed]!=0x3f3f3f3f; 
}
int ans;
void solve(int st,int ed)
{
	int x=ed;
	
	while(x!=st)
	{
		int i=pre[x];
		l[i]-=flow[ed];
		l[i^1]+=flow[ed];
		x=to[i^1];
	}
	ans+=flow[ed]*dis[ed];
	return ;
}



int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>c[i];
	
	for(int i=1;i<=n;i++)
	{
		if(i!=n)
		add(i,i+1,k-1,0);
		add(0,i,1,c[a[i]]);
        add(i,i+n,1,0);
		add(i+n,2*n+1,1,0);
		now[a[i]]=i;
        if(now[a[i+1]])
		{
            add(i,now[a[i+1]]+n,1,-c[a[i+1]]);
        }
    }
    
    while(spfa(0,2*n+1))solve(0,2*n+1);
    cout<<ans; 
    
	return 0;
}
