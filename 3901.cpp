#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;


int n,m,base;
int ans[N];
int cnt[N];

struct node
{
	int l,r;
	int num;
}q[N];

int sum,st ,end;
int a[N];

void move(int x)
{
	if((++cnt[a[x]])==1)
	sum++;
	return ;
}

void delet(int x)
{
	if(!(--cnt[a[x]]))
	sum--;
	return ;
}


bool cmp(node x,node y)
{
	if(x.l/base==y.l/base)
	return x.r<y.r;
	return x.l<y.l;
}
int main()
{ 
	ios::sync_with_stdio(false);	
	cin>>n>>m;
	base=sqrt(n);
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	for(int i=1;i<=m;i++)
	{
		cin>>q[i].l>>q[i].r;
		q[i].num=i;
	}
	sort(q+1,q+1+m,cmp);
	
	for(int i=1;i<=m;i++)
	{
		int l=q[i].l,r=q[i].r;
		
		while(st<l)
		delet(st),st++;		
		while(st>l)
		st--,move(st);		
		
		while(end<r)
		end++,move(end);
		while(end>r)
		delet(end),end--;
		
		if(sum==(r-l+1))
		ans[q[i].num]=1;
	}
	
	for(int i=1;i<=m;i++)
	{
		if(ans[i])
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	
	return 0;
}
