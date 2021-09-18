#include<bits/stdc++.h>

using namespace std;
const int N=50*2500;

//后语：但是貌似有很多可设状态


int n,m;
int a[66],b[66];
int w[66][66];
int pl=114514;
int dp[66][N];

int main()
{
	ios::sync_with_stdio(false);	
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	cin>>a[i]>>b[i];
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++)	
	cin>>w[i][j];
	memset(dp,0x80,sizeof(dp));
	dp[0][pl]=0;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<N;j++)
		{
			for(int k=0;k<i;k++)
			{
				if(dp[k][j-a[i]]!=dp[0][0])
				dp[i][j]=max(dp[i][j],dp[k][j-a[i]]+b[i]+w[k][i]);
				
			}
			
		}
	}
	int ans=dp[0][0];
	
	for(int i=0;i<=n;i++)
	ans=max(ans,dp[i][m+pl]);
	
	if(ans!=dp[0][0])
	cout<<ans;
	else
	cout<<-1;
	return 0;
}



