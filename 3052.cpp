#include<bits/stdc++.h>

using namespace std;
const int N=20;

int n,m;
int a[N];

int dp[N][(1<<18)+7];
//第i个集合中的物品状态 

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=0;i<n;i++) 
	cin>>a[i];
	int num=1<<n;
	memset(dp,0x3f,sizeof(dp));
	for(int i=0;i<n;i++)
	dp[1][1<<i]=a[i];
	
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<num;j++)
		{
			if(dp[i][j]!=0x3f3f3f3f)
			{
				for(int k=0;k<n;k++)
				{
					if(j&(1<<k))
					continue;
					int f=(j|(1<<k));
					if(dp[i][j]+a[k]<=m)
						dp[i][f]=min(dp[i][f],dp[i][j]+a[k]);
					else
						dp[i+1][f]=min(a[k],dp[i][f]);
					
				}
			}
			
		}
		
		
	}
	
	for(int i=0;i<=n;i++)
	{
		if(dp[i][num-1]!=0x3f3f3f3f)
		{
			cout<<i;
			return 0;
		}
	}
	
	
	return 0;
}
