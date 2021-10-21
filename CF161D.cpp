#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=5e4+7;

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
int root,sum;
int n,m,k;
int siz[N],maxx[N],vis[N];
int cnt;
/*
void getroot(int x,int fa)
{
	siz[x]=1;
	maxx[x]=0;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa||vis[y])
		continue;
		getroot(y,x);
		siz[x]+=siz[y];
		
		maxx[x]=max(siz[y],maxx[x]);
	}
	maxx[x]=max(maxx[x],sum-siz[x]);
	
//	if(!root||maxx[x]<maxx[root])
//	root=x;
	return ;
}
*/
inline void getroot(int now,int fa){
    siz[now]=1;maxx[now]=0;
    for(int i=head[now];i;i=nxt[i]){
        int y=to[i];
        if(vis[y]||y==fa) continue;
        getroot(y,now);
        siz[now]+=siz[y];
        maxx[now]=max(maxx[now],siz[y]);
    }
    maxx[now]=max(maxx[now],sum-siz[now]);
    if(maxx[now]<maxx[root]) root=now;
}
int ans;
int a[N],dep[N];

void getdis(int x,int fa)
{
	a[++cnt]=dep[x];
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa||vis[y])
		continue;
		dep[y]=dep[x]+edge[i];
		getdis(y,x);
	}
	return ;
}
/*
int calc(int x,int k)
{
	int re=0;
	cnt=0;
	dep[x]=k;
	getdis(x,0);
	sort(a+1,a+1+cnt);
	int l=1,r=cnt;
	
	while(l<r)
	{
		if(a[l]+a[r]<=k)
		{
			re+=(r-l);
			l++;	
		}
		else
		r--;
	}
	l=1,r=cnt;
	
	while(l<r)
	{
		if(a[l]+a[r]<k)
		{
			re-=(r-l);
			l++;
		}
		else
		r--;
	}
	
	return re;
}*/
inline int calc(int now,int w){
    cnt=0;dep[now]=w;
    getdis(now,0);
    sort(a+1,a+1+cnt);
    int l=1,r=cnt,res=0;
    while(l<r){
        if(a[l]+a[r]<=k) res+=(r-l),l++;
        else r--;
    }
    l=1,r=cnt;
    while(l<r){
        if(a[l]+a[r]<k) res-=(r-l),l++;
        else r--;
    }
    return res;
}

void solve(int x)
{
	ans+=calc(x,0);
	vis[x]=1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(vis[y])
		continue;
		ans-=calc(y,edge[i]);
		root=0;
		sum=siz[y];
		getroot(y,0);
		solve(root);
	}
	return ;
}
signed main()
{
	ios::sync_with_stdio(false);
 	cin>>n>>k;
 	
 	for(int i=1;i<n;i++)
 	{
 		int x,y;
 		cin>>x>>y;
 		add(x,y,1);
 		add(y,x,1);
	 }
 	sum=maxx[0]=n;
 	root=0;
 	getroot(1,0);
 	solve(root);
 	
 	cout<<ans;
 	
 	
    return 0;
}
