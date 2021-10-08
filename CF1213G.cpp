#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=2e5+7;

int n,m;
int maxx=-1;
int f[N];
int num[N],ans[N];
struct node
{
	int x,y,z;
}tr[N];

int find(int x)
{
	if(f[x]==x)
	return x;
	return f[x]=find(f[x]);
}

void init()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=i;
		num[i]=1;
	}
	
	return ;
}
bool cmp(node x,node y)
{
	return x.z>y.z;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=n-2;i>=0;i--)
	{
		cin>>tr[i].x>>tr[i].y>>tr[i].z;
		maxx=max(maxx,tr[i].z);
	}
	init();
	sort(tr,tr-1+n,cmp);
	
	for(int i=n-2;i>=0;i--)
	{
		int z=tr[i].z;
		int fa=find(tr[i].x),fb=find(tr[i].y);
		f[fa]=fb;
		ans[z]+=(num[fa]*num[fb]);
		num[fb]+=num[fa];
		
	}
	for(int i=1;i<=maxx;i++)
	ans[i]+=ans[i-1];
	
	
	while(m--)
	{
		int x;
		cin>>x;	
		if(x>maxx)
		x=maxx;
		cout<<ans[x]<<' ';
	}
	
	return 0;
}
