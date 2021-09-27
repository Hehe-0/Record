#include<bits/stdc++.h>

#define int long long
#define mid ((L+R)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
using namespace std;
const int N=8e5+7;

int n,m;
int a[N<<1];
double ssin[N],ccos[N];
int f[N];
int root;

void build(int x,int L,int R)
{
	if(L==R)
	{
		ssin[x]=sin(a[L]);
		ccos[x]=cos(a[L]);
		return ;	
	}
	build(ls,L,mid);
	build(rs,mid+1,R);
	
	ssin[x]=ssin[ls]+ssin[rs];
	ccos[x]=ccos[ls]+ccos[rs];
	return ;
}

void push(int x,double s,double c)
{
	double asin=ssin[x],acos=ccos[x];	
	ssin[x]=asin*c+acos*s;
	ccos[x]=acos*c-asin*s;
	return ;
}

void pushdown(int rt)
{
    if (!f[rt]) return;
    f[rt<<1]+=f[rt];
	f[rt<<1|1]+=f[rt];
    double sinx=sin(f[rt]),cosx=cos(f[rt]);
    push(rt<<1,sinx,cosx);
	push(rt<<1|1,sinx,cosx);
    f[rt]=0;
	return;
}
void ch(int L,int R,int l,int r,int x,double sx,double cx,int k)
{
	if(l<=L&&R<=r)
	{
		push(x,sx,cx);
		f[x]+=k;
		return ;
	}
	pushdown(x);
	if(mid>=l)
		ch(L,mid,l,r,ls,sx,cx,k);
	if(mid<r)
		ch(mid+1,R,l,r,rs,sx,cx,k);
	
	ssin[x]=ssin[ls]+ssin[rs];
	ccos[x]=ccos[ls]+ccos[rs];
	return ;
}

double query(int x,int L,int R,int l,int r)
{
	if(l<=L&&R<=r)
		return ssin[x];
	if(l>R||L>r)
		return 0;
	pushdown(x);
	
	return query(ls,L,mid,l,r)+query(rs,mid+1,R,l,r);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	cin>>a[i];
	build(1,1,n);
	cin>>m;
	
	int op;
	while(m--)
	{
		cin>>op;
		
		if(op==1)
		{
			int x,y,z;
			cin>>x>>y>>z;
			ch(1,n,x,y,1,sin(z),cos(z),z);
		}
		else
		{
			int x,y;
			cin>>x>>y;
			printf("%.1lf\n",query(1,1,n,x,y));
		}
	}
	
	return 0;
}
