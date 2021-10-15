#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=111;
const int mod=9999973; 

int n,m;
int ans;
int dp[N][N][N];
//前i行，有j列有一个炮，有k 个有两个棋子   
//


signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			for(int k=0;k<=m-j;k++)
			{
				dp[i][j][k]=(dp[i-1][j][k]+dp[i][j][k])%mod;
				if(k)	
				dp[i][j][k]=(dp[i][j][k]+(dp[i-1][j+1][k-1]*(j+1))%mod)%mod;
				if(j)
				dp[i][j][k]=(dp[i][j][k]+(dp[i-1][j-1][k]*(m-j-k+1))%mod)%mod;
				
				if(k>=2)
				{
					dp[i][j][k]=(dp[i][j][k]+(dp[i-1][j+2][k-2]*(((j+1)*(j+2))>>1))%mod)%mod;
				}
				if(k>=1)
				{
					dp[i][j][k]=(dp[i][j][k]+(dp[i-1][j][k-1]*(m-j-k+1)*j)%mod)%mod;
				}
				if(j>=2)
				{
					dp[i][j][k]=(dp[i][j][k]+(dp[i-1][j-2][k]*((m-j-k+2)*(m-j-k+1))>>1)%mod)%mod;
				}
				dp[i][j][k]%=mod;
			}
		}
		
	}
	
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=m;j++)
		ans=(ans+dp[n][i][j])%mod;
	}
	
	cout<<ans;
	return 0;
}
