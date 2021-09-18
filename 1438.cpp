#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define lson (x<<1),l,mid
#define rson (x<<1)+1,mid+1,r
using namespace std;
#define int long long 
const int N=1e5;

int n,m;
int tree[N<<3],mark[N>>3];
int a[N];

void add(int x,int l,int r,int k)
{
	tree[x]+=(r-l+1)*k;
	mark[x]+=k;
	return ;
}

void pushdown(int x,int l,int r)
{
	add(lson,mark[x]);
	add(rson,mark[x]);
	mark[x]=0;
	return ;
}

void updata(int x,int l,int r,int st,int end,int k)
{
	if(l>end||r<st)
	return ;
	if(l>=st&&r<=end)
	{
		add(x,l,r,k);
		return ;	
	}
	pushdown(x,l,r);
	
	updata(lson,st,end,k);
	updata(rson,st,end,k);
	tree[x]=(tree[x<<1]+tree[x<<1|1]);
	return ;
}

int query(int x,int l,int r,int st,int end)
{
	if(l>end||r<st)
	return 0;
	if(l>=st&&r<=end)
	return tree[x];
	
	pushdown(x,l,r);
	return query(lson,st,end)+query(rson,st,end);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	
	cin>>a[i];
	
	while(m--)
	{
		int flag;
		cin>>flag;
		if(flag==2)
		{
			int x;
			cin>>x;
			cout<<query(1,1,n,1,x)+a[x]<<endl;
		}
		else
		{
			int x,y,star,d;
			cin>>x>>y>>star>>d;
			updata(1,1,n,x,x,star);
			updata(1,1,n,x+1,y,d);
			updata(1,1,n,y+1,y+1,-(star+(y-x)*d));
		}
	}
	
	
	
	return 0;
}
