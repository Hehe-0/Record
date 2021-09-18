#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=5e4+7;

int n,m,base,k;

struct modui
{
	int l,r;
	int num;
}q[N];

int a[N];
int cnt[N],ans[N];

int l,r;
int sum;
void move(int x,int k)
{
	if(x==0)
	return ;
	sum-= cnt[a[x]]*cnt[a[x]];
	cnt[a[x]]+=k;
	sum+=cnt[a[x]]*cnt[a[x]];
	
	return ;
}

bool cmp(modui x,modui y)
{
	if(x.l/base ==y.l/base)
	return x.r<y.r;
	return x.l<y.l;
}

int st,end;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
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
		
		while(st>l)
		st--,move(st,+1);
		while(end<r)
		end++,move(end,+1);
		while(st<l)
		move(st,-1),st++;
		while(end>r)
		move(end,-1),end--;
		
		ans[q[i].num]=sum;	
	}
	
	for(int i=1;i<=m;i++)
	cout<<ans[i]<<endl;
	
	return 0;
}
