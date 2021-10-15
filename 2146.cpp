#include<bits/stdc++.h>


#define mid ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
#define int long long
using namespace std;
const int N=2e6+7;

int n;
int a[N];
int mark[N];
int son[N],id[N],siz[N],dep[N],top[N],f[N];

int _;
int head[N],to[N<<1],nxt[N<<1];
void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}

void dfs1(int x,int fa,int deep)
{
	f[x]=fa;
	siz[x]=1;
	dep[x]=deep;
	int maxson=-1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		continue;
		
		dfs1(y,x,deep+1);
		siz[x]+=siz[y];
		
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
	
	return ;	
}
int wt[N],w[N];
int cnt;
void dfs2(int x,int topf)
{
	top[x]=topf;
	id[x]=++cnt;
	wt[cnt]=w[x];
	if(!son[x])
	return ;
	
	dfs2(son[x],topf);
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==son[x]||y==f[x])
		continue;
		
		dfs2(y,y);
	}
	
	return ;
}

void update(int x)
{
	return (void)(a[x]=a[ls]+a[rs]);
}
void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x]=wt[l];
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	update(x);
	return ;
}

void addx(int x,int l,int r,int k)
{
		if(k==1)
	{
		a[x] = r - l + 1;
		mark[x] = 1;
	}
	if(k==2)
	{
		a[x] = 0;
		mark[x] = 2;
	}
	return ;
}

void push(int x,int l,int r)
{
	addx(ls,l,mid,mark[x]);
	addx(rs,mid+1,r,mark[x]);
	mark[x]=0;	
	return ;
}

void chance(int x,int l,int r,int L,int R,int k)
{
	if(r<L||l>R)
	return ;
	if(L<=l&&R>=r)
	{
		addx(x,l,r,k);
		return ;
	}
	push(x,l,r);
	chance(ls,l,mid,L,R,k);
	chance(rs,mid+1,r,L,R,k);
	
	update(x);
	return ;
}

int query(int x,int l,int r,int L,int R)
{
	if(r<L||l>R)
	return 0;
	if(L<=l&&R>=r)
	return a[x];
	push(x,l,r);
	
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}
int T;

void chr(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		swap(x,y);
		chance(1,1,n,id[top[x]],id[x],1);
		x=f[top[x]];
	}
	if(dep[x]>dep[y])
	swap(x,y);
	
	chance(1,1,n,id[x],id[y],1);
	return ;
}

int qr(int x,int y)
{
	int re=0;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
		swap(x,y);
		re+=query(1,1,n,id[top[x]],id[x]);
		
		x=f[top[x]];
	}
	if(dep[x]>dep[y])
	swap(x,y);
	re+=query(1,1,n,id[x],id[y]);
	return re;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		int q;		
		cin>>q;
		q++;
		add(q,i);
	}
	dfs1(1,0,1);
	dfs2(1,1);
	cin>>T;
	
//	build(1,1,);
	
	while(T--)
	{
		string op;
		cin>>op;
		int x;
		cin>>x;
		x++;
		
		if(op[0]=='i')
		{
			cout<<dep[x]-qr(1,x)<<endl;
			chr(1,x);
		}
		else
		{
			cout<<query(1,1,n,id[x],id[x]+siz[x]-1)<<endl;
			chance(1,1,n,id[x],id[x]+siz[x]-1,2);
		}
	}
	
	
	return 0;
}
