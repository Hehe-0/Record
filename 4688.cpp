#include<bits/stdc++.h>

using namespace std;

const int N=1e5+7;
const int M=(N/3)+7;

int n,m,bs;

int a[N],ans[M],cnt[N];
bitset<N>sum[M],now;

struct query
{
	int l,r,id;
	
	friend bool operator <(query a,query b)
	{
		if(a.l/bs==b.l/bs)
			if((a.l/bs)&1)
			return a.r<b.r;
			else 		  
			return a.r>b.r;
		return a.l<b.l;
	}
}q[M*3];

void s_set()
{
	static int data[N];
	memcpy(data,a,sizeof a);
	sort(data+1,data+1+n);
	
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(data+1,data+1+n,a[i])-data;
	}
	
	return ;
}
void add(int x)
{
	now.set(x+cnt[x]);
	cnt[x]++;
	return ;
}
void del(int x)
{
	cnt[x]--;
	now.reset(x+cnt[x]);
	return ;
}

void solve()
{
	int cnt=0,tot=0;
	now.reset();
	
	for(tot=0;tot<M-5&&m;tot++)
	{
		m--;
		ans[tot]=0;
		sum[tot].set();
		
		for(int j=0;j<3;j++)
		{
			cin>>q[cnt].l>>q[cnt].r;
			q[cnt].id=tot;
			
			ans[tot]+=q[cnt].r-q[cnt].l+1;
			cnt++;
		}
	}
	
	sort(q,q+cnt);
	
	for(int i=0,l=1,r=0;i<cnt;i++)
	{
		
		while(l>q[i].l)add(a[--l]);
		while(r<q[i].r)add(a[++r]);
		while(l<q[i].l)del(a[l++]);
		while(r>q[i].r)del(a[r--]);
		
		sum[q[i].id]&=now;
	}
	for(int i=0;i<tot;i++)
	{
		cout<<(ans[i]-(int)sum[i].count()*3)<<endl;
	}
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	s_set();
	bs=sqrt(n);
	solve();
	memset(cnt,0,sizeof(cnt));
	solve();
	memset(cnt,0,sizeof(cnt));
	solve();
	
	return 0;
}
