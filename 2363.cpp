#include<bits/stdc++.h>

using namespace std;
const int N=5555;

//枚举交点？ 
//然后再去找收益大小然后再  ——> 矩阵大小 
//或者直接暴力 
int n; 
int dp[N][N];
int a[N][N];
int d[N<<9];
int ans;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin>>a[i][j];
			dp[i][j]=dp[i][j-1]+dp[i-1][j]+a[i][j]-dp[i-1][j-1];
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int x=1;x<=i;x++)
            for(int y=1;y<=j;y++)
            d[dp[i][j]-dp[i][y-1]-dp[x-1][j]+dp[x-1][y-1]]++;
            
            for(int x=i+1;x<=n;x++)
            for(int y=j+1;y<=n;y++)
            ans=ans+d[dp[x][y]-dp[x][j]-dp[i][y]+dp[i][j]];
            
            for(int x=1;x<=i;x++)
            for(int y=1;y<=j;y++)
            d[dp[i][j]-dp[i][y-1]-dp[x-1][j]+dp[x-1][y-1]]=0;
            
            for(int x=1;x<=i;x++)
            for(int y=j+1;y<=n;y++)
            d[dp[i][y]-dp[x-1][y]-dp[i][j]+dp[x-1][j]]++;
            
            for(int x=i+1;x<=n;x++)
            for(int y=1;y<=j;y++)
            ans+=d[dp[x][j]-dp[i][j]-dp[x][y-1]+dp[i][y-1]];
            
            for(int x=1;x<=i;x++)
            for(int y=j+1;y<=n;y++)
            d[dp[i][y]-dp[x-1][y]-dp[i][j]+dp[x-1][j]]=0;
			
			
		}
		
	}
	cout<<ans;
	
	return 0;
}
