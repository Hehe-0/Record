#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;

int n,m;
int siz;
int v[N],mark[N];
int belong[N];

vector<int >a[N];

void resort(int x)
{
	a[x].clear();
	for(int i=siz*(x-1)+1;i<=min(n,x*siz);i++)
	a[x].push_back(v[i]);
	
	sort(a[x].begin(),a[x].end());
	return ;
}

void add(int x,int y,int z)
{
	for(int i=x;i<=min(belong[x]*siz,y);i++)
	v[i]+=z;
	resort(belong[x]);	
	if(belong[x]!=belong[y])
	{
		for(int i=(belong[y]-1)*siz+1;i<=y;i++)
		v[i]+=z;
		resort(belong[y]);	
	}
	
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
		mark[i]+=z;
	return ;
}

int query(int x,int y,int z)
{
	int re=0;
	for(int i=x;i<=min(belong[x]*siz,y);i++)
	{
		if(v[i]+mark[belong[x]]<z)
		re++;
	}
	if(belong[x]!=belong[y])
	{
		for(int i=(belong[y]-1)*siz+1;i<=y;i++)
		{
			if(v[i]+mark[belong[y]]<z)
			re++;
		}
	}
	for(int i=belong[x]+1;i<=belong[y]-1;i++)
	{
		int f=(z-mark[i]);
	      	
		re+=lower_bound(a[i].begin(),a[i].end(),f)-a[i].begin();
	}
	
	return re;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	siz=sqrt(n);
	for(int i=1;i<=n;i++)
	cin>>v[i];
	
	for(int i=1;i<=n;i++)
	{
		belong[i]=(i-1)/siz+1;
		a[belong[i]].push_back(v[i]);
	}
	for(int i=1;i<=belong[n];i++)
	sort(a[i].begin(),a[i].end());
	
	for(int i=1;i<=m;i++)
	{
		char op;
		int x,y,z;
		cin>>op;
		cin>>x>>y>>z;
		if(op=='M')
		{
			add(x,y,z);
		}
		else
		{
			cout<<y-x+1-query(x,y,z)<<endl;
		}
	}
	
	return 0;
}
