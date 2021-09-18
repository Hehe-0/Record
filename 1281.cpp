#include<bits/stdc++.h>

using namespace std;
#define int long long
//审题：看到标签了
//可以考虑二分每个人的抄写书的页数？ 
int n,m;
int a[1010];
int sum;
int l=-1,r=10;

bool pd(int mid)
{
	int re=1,now=0;
	for(int i=n;i>=1;i--)
	{
		if(now+a[i]>mid)
		now=0,re++;
		
		now+=a[i];
	}
	
	return re<=m;
}


int st[1001],en[1001];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	if(!n)
	return 0;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];r+=a[i];
		l=max(l,a[i]);
	}
	
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(pd(mid))
		r=mid;
		else
		l=mid;
	}
	int now=0,num=1;
	en[1]=n;
	
	for(int i=n;i>=1;i--)
	{
		if(now+a[i]>r)
		{
			now=0;
			st[num]=i+1;
			num++;
			en[num]=i;
		}
		now+=a[i];	
		
	}	
	st[num]=1;

	for(int i=m;i>=1;i--)	
		cout<<st[i]<<" "<<en[i]<<endl;

	
	return 0; 
}
