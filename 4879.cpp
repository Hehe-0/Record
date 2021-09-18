#include<bits/stdc++.h>

#define int long long
#define mid ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int N=5e5+7;

int n,m;
int da[N<<3];
struct node
{
	int sum,cnt;
}a[N<<2];

void upit(int x)
{
	a[x].cnt=a[ls].cnt+a[rs].cnt;
	a[x].sum=a[ls].sum+a[rs].sum;	
	return ;
}

void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x].sum=da[l];
		if(da[l])
		a[x].cnt++;
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	upit(x);
	return ;
}

void ch(int x,int l,int r,int u,int y)
{
	if(l==r)
	{
		a[x].sum-=y;
		return ;
	}
	if(u<=mid)
	ch(ls,l,mid,u,y);
	else
	ch(rs,mid+1,r,u,y);
	upit(x);
	return ;
}

void add(int x,int l,int r,int u,int y)
{
	if(l==r)
	{
		a[x].sum=y;
		a[x].cnt=1;
		return ;
	}
	if(u<=mid)
	add(ls,l,mid,u,y);
	else
	add(rs,mid+1,r,u,y);
	
	upit(x);
	return ;
}

void del(int x,int l,int r,int k)
{
	if(l>r)
	return ;
	if(l==r&&k==a[x].cnt)
	{
		a[x].sum=0;
		a[x].cnt--;
		return ;
	}
	if(k<=a[ls].cnt)
	del(ls,l,mid,k);
	else
	del(rs,mid+1,r,k-a[ls].cnt);
	
	upit(x);
	
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>da[i];
	
	build(1,1,N-10);
	while(m--)
	{
		string s;
		cin>>s;
		if(s[0]=='C')
		{
			int q,w;
			cin>>q>>w;
			ch(1,1,N-10,q,w);
		}
		if(s[0]=='I')
		{
			int q,w;	
			cin>>q>>w;
			add(1,1,N-10,q,w);
		}
		if(s[0]=='D')
		{
			int q;
			cin>>q;
			del(1,1,N-10,q);
		}
		if(s[0]=='Q')
		{
			cout<<a[1].sum<<endl;
		}
	}
	
	
	return 0;
}
