#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+66;
const int inf=1e16+7;

int n,k;
int ans,tot;
int sum[N],a[N];
int coin[22];
int dp[N];
int g;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>k>>n;
	
	for(int i=1;i<=k;i++)
	{
		cin>>coin[i];
		tot+=coin[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	sum[n+1]=inf;
	
	for(int i=1;i<(1<<k);i++)
	{
		for(int j=0;j<k;j++)
		{
			if(!(i&(1<<j)))
			continue;
			
			int f=i^(1<<j);	
			int now=dp[f];
			int x=lower_bound(sum+1,sum+1+n,sum[now]+coin[j+1])-sum;
			if(sum[x]>sum[now]+coin[j+1])	x--;
			dp[i]=max(x,dp[i]);
		}	
		if(dp[i]>=n)
		{
			g=1;
			int now=0;
			for(int j=0;j<k;j++)
			{
				if(i&(1<<j))
					now+=coin[j+1];
			}
			ans=max(ans,tot-now);
		}
	}
	if(g)
	cout<<ans;
	else
	cout<<-1;
	return 0;
}
