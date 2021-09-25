#include<bits/stdc++.h>

using namespace std;
const int N=5e5+7;

int n,m;
int a[N],sum[N];
int ans=-2147483640;
int q[N];
int l=1,r=1;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];	
	}
	
	for(int i=1;i<=n;i++)	
	{
		while(l<=r&&q[l]<i-m)
		l++;
		ans=max(ans,sum[i]-sum[q[l]]);
		while(l<=r&&sum[i]<=sum[q[r]])
		r--;
		
		q[++r]=i;
	}
	
	cout<<ans;
	return 0;
} 
