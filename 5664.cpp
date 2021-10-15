#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=111;
const int mod=998244353;

int n,m;
int a[N][N<<5];
int sum[N],ans[N];
int dp[N][N<<3];
int anssum=1;

int move(int x)
{
	return x+10+n;
}
int hsh(int x)
{
	return x+10+n;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			sum[i]=(sum[i]+a[i][j])%mod;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		anssum=(anssum*(sum[i]+1))%mod;
		
	}
	anssum=(anssum+mod-1)%mod;
	
	for(int j=1;j<=m;j++)
	{
		memset(dp,0,sizeof(dp));
//		dp[1][move(0)]=1;
//		dp[1][move(1)]=a[1][j];
//		dp[1][move(-1)]=(sum[1]+mod-a[1][j])%mod;
		dp[1][hsh(0)]=1;
		dp[1][hsh(1)]=a[1][j];
		dp[1][hsh(-1)]=(sum[1]+mod-a[1][j])%mod;
  
		for(int i=2;i<=n;i++)
		{
			for(int k=-n;k<=n;k++)
			{
				dp[i][move(k)]=(dp[i-1][move(k)]+a[i][j]*dp[i-1][move(k-1)]%mod+(sum[i]+mod-a[i][j])*dp[i-1][move(k+1)]%mod)%mod;
				
			}
			
		}
		
		for(int k=1;k<=n;k++)
		anssum=(anssum+mod-dp[n][move(k)])%mod;
	}

	
	cout<<anssum;
	
	
	return 0;
}
