#include<bits/stdc++.h>

#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=3e5+7;
const int inf=1e9;

struct edge
{
	int y,nxt;
}e[N*2];

int n,m,maxx,head[N];
int _,d[N],siz[N];
int rt[N],cnt,tot,dfn[N],fa[N];

struct node
{
	int l,r;
	int da;
}t[N*30];

void add(int x,int y)
{
    e[++_]=(edge){y,head[x]};
	head[x]=_;
	return ;
} 
void dfs1(int x)
{
	siz[x]=1;
    for(int i=head[x];i;i=e[i].nxt)
    {
    	int y=e[i].y;
	    if(!d[y])
		{
	        d[y]=d[x]+1;
			maxx=max(maxx,d[y]);
	        fa[y]=x;
			dfs1(y);
			siz[x]+=siz[y];
	    } 	
	}
    
	return ;
} 

void update(int &x,int l,int r,int v,int p)
{
    t[++cnt]=t[x];
	x=cnt;
	t[x].da+=v;
    if(l==r) 
	return;
	
    if(p<=mid) 
	update(t[x].l,l,mid,v,p);
    else 
	update(t[x].r,mid+1,r,v,p);
	return ;
} 

int query(int x,int y,int l,int r,int L,int R)
{
    if(L<=l&&r<=R) 
	return t[y].da-t[x].da;
	
    int re=0;
    if(L<=mid)
	re+=query(t[x].l,t[y].l,l,mid,L,R);
    if(mid<R)
	re+=query(t[x].r,t[y].r,mid+1,r,L,R);
	
    return re;
} 
void dfs2(int x)
{
     dfn[x]=++tot;
	 rt[tot]=rt[tot-1];
     update(rt[tot],1,maxx,siz[x]-1,d[x]);
     
     for(int i=head[x];i;i=e[i].nxt)
	 {
	     int y=e[i].y;
         if(y==fa[x]) 
		 continue;
         dfs2(y);
    } 
	return ;
} 
signed main()
{
	 ios::sync_with_stdio(false);
     cin>>n>>m;
     for(int i=1;i<n;i++)
     {
     	int x,y;
     	cin>>x>>y;
     	add(x,y);
     	add(y,x);
	 }
     
     d[1]=1;
	 dfs1(1);
	 dfs2(1);
     for(int i=1;i<=m;i++)
	 {
         int p,k;
		 cin>>p>>k;
         int ans=(siz[p]-1)*(min(k,d[p]-1));
         int l=dfn[p]-1,r=dfn[p]+siz[p]-1;
         if(d[p]==maxx)
		 {
			 cout<<0<<endl;
			 continue;
		 }
         int z=min(maxx,d[p]+k);
         ans+=query(rt[l],rt[r],1,maxx,d[p]+1,z);
         cout<<ans<<endl;
     } 
	 return 0;
}
