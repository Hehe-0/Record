#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int N=1e5+7;

inline int read(){
    int x = 0 , f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; } 
    while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; } 
    return x * f ;
}

struct node
{
	int val,maxx; 
}a[N<<3];
int n,m;

void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x].maxx=a[x].val=read();
		
		return ;
	}
	build(ls,l,mid);
	build(rs,mid+1,r);
	a[x].val=a[ls].val+a[rs].val;
	a[x].maxx=max(a[ls].maxx,a[rs].maxx);
	
	return ;
}

void mood(int x,int l,int r,int L,int R,int mod)
{
	if(r<L||l>R||a[x].maxx<mod)
	{
		return ;
	}
	if(l==r)
	{
		a[x].val=a[x].maxx=a[x].maxx%mod;
		return ;
	}
	mood(ls,l,mid,L,R,mod);
	mood(rs,mid+1,r,L,R,mod);
	a[x].maxx=max(a[ls].maxx,a[rs].maxx);
	a[x].val=a[ls].val+a[rs].val;
	
	return ;
}

void change(int x,int l,int r,int y,int k)
{
	if(l==r)
	{
		a[x].maxx=a[x].val=k;
		return ;
	}
	if(y<=mid)
	{
		change(ls,l,mid,y,k); 
	}
	else
	{
		change(rs,mid+1,r,y,k);
	}
	
	a[x].val=a[ls].val+a[rs].val;
	a[x].maxx=max(a[ls].maxx,a[rs].maxx);
	return ;
}

int query(int x,int l,int r,int L,int R)
{
	//int re=0;
	if(l>R||r<L)
	return 0;
	if(l>=L&&r<=R)
	{
		return a[x].val;
	}
	
	return query(ls,l,mid,L,R)+query(rs,mid+1,r,L,R);
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	build(1,1,n);
	
	for(int i=1;i<=m;i++)
	{
		int op,x,y,z;
		cin>>op;
		if(op==1)
		{
			cin>>x>>y;
			cout<<query(1,1,n,x,y)<<endl;
				
		}
		else if(op==2)
		{
			cin>>x>>y>>z;			

			mood(1,1,n,x,y,z);
		}
		else if(op==3)
		{
			cin>>x>>y;
			change(1,1,n,x,y);
		}
	}
	
	return 0;
}
