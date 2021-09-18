#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[1010];
int dp[100][110];
//第几个人，在第几次被释放
// 第几个人，前面有几个人被释放 ，后面有几个人被释放
//dp[i][j][k] 
//dp[i][0][0]=n-1;
 
// 枚取断点? 
//dp[i][j]i~j需要几个‘r’ 
 
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	//	dp[i][i]=1;
	//	sum[i]=i-a[i];
	}
	sort(a+1,a+1+m);
	a[m+1]=n+1;
	
	for(int l=1;l<=n;l++)
	{
		for(int i=1;i<=n;i++)
		{
			int j=i+l-1;
			dp[i][j]=2147483640;
			for(int k=i;k<=j;k++)
			{
				//f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]+a[j+1]-a[i-1]-1-1);
				dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[j+1]-a[i-1]-2);
				
			}
			
			
		}
		
	}

	cout<<dp[1][m];
	
	
	
	return 0;
 } 
