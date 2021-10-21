#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n,m;
int dp[1<<21|1];
int num[N],sum[N][22];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		num[x]++;
		for(int j=1;j<=m;j++) 
		sum[i][j]=sum[i-1][j];
        sum[i][x]++;
	}
	memset(dp,0x3f,sizeof(dp));
	dp[0]=0;
	
	for(int i=1;i<(1<<m);i++)
	{
		int len=0;
		for(int j=1;j<=m;j++)
		{
			if(i&(1<<(j-1)))
			len+=num[j];
		}
		for(int j=1;j<=m;j++)
		{
			if(i&(1<<(j-1)))
			{
				dp[i]=min(dp[i],dp[i^(1<<(j-1))]+num[j]-sum[len][j]+sum[len-num[j]][j]);					
			}
		}
	}

	
	cout<<dp[(1<<m)-1];
	
	return 0;
}
