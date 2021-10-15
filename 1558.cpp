#include<bits/stdc++.h>

#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=1e5+7; 

int n,t,o;
int a[N<<2];
int mark[N<<1];

void push(int x)
{
//	return (void)(a[x]=a[ls]|a[rs]);
		a[x]=a[ls]|a[rs];
}

//void build(int x,int l,int r)
//{
// 	if(l==r)
// 	{
// 		a[x]=1<<1;
// 		return ;
//	}
// 	build(ls,l,mid);
// 	build(rs,mid+1,r);
// 	push(x);
// 	return ;
//}
 
void update(int x,int l,int r) 
{
	if(mark[x])	
	{
		a[ls]=(1<<mark[x]);
		a[rs]=(1<<mark[x]);
		mark[ls]=mark[x];
		mark[rs]=mark[x];
		mark[x]=0;
	}
	return ;
}
 
void add(int x,int l,int r,int L,int R,int k) 
{
	if(L<=l&&r<=R)
	{
		a[x]=(1<<k);
		mark[x]=k;
		return ;
	}
	update(x,l,r);
	
	if(L<=mid)
	{
		add(ls,l,mid,L,R,k);
	}
	if(mid<R)
	{
		add(rs,mid+1,r,L,R,k);
	}
//	push(x);
	a[x]=a[ls]|a[rs];
	return ;
}

int query(int x,int l,int r,int L,int R)
{
	int re=0;
	if(L<=l&&r<=R)
	{
		return a[x];
	}
	update(x,l,r);
	
	if(L<=mid)
		re|=query(ls,l,mid,L,R);
	if(mid<R)
		re|=query(rs,mid+1,r,L,R);
	
	return re;
}

void check(int &x,int &y)
{
	if(x>y)
	swap(x,y);
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);	
	cin>>n>>t>>o;
//	fill(a+1,a+1+n+n,1);
	
//	build(1,1,n);
	add(1,1,n,1,n,1);
	while(o--)
	{
		char op;
		int x,y,z=0;
		cin>>op;
		if(op=='C')
		{
			cin>>x>>y>>z;
			check(x,y);
			add(1,1,n,x,y,z);
		}
		else
		{
			cin>>x>>y;
			check(x,y);
			int pos=query(1,1,n,x,y);
			for(int i=1;i<=t;i++)
			if(pos&(1<<i))
			z++;
			cout<<z<<endl;;
		}
	}
	
	
	
	return 0;
} 
