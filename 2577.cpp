#include<bits/stdc++.h>

using namespace std;
const int N=210;
int n;

//在窗口2排队的时间为在窗口1排队的时间的补集
int dp[N][N*N];	
int ans=2147483644;
struct node
{
	int wait,eat;
	bool operator <(node k) const{
			return eat>k.eat;
	}
}d[N];
int sum[N];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>d[i].wait>>d[i].eat;
	
	sort(d+1,d+1+n);
	
	for(int i=1;i<=n;i++)
		sum[i]=sum[i-1]+d[i].wait;
	
	memset(dp,0x3f,sizeof(dp));
	
	dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=sum[i];j++)
		{
			if(j>=d[i].wait) 
			dp[i][j]=min(dp[i][j],max(dp[i-1][j-d[i].wait],j+d[i].eat));
			
			dp[i][j]=min(dp[i][j],max(dp[i-1][j],sum[i]-j+d[i].eat));
		}
	}

	
	for(int i=1;i<=sum[n];i++)
		ans=min(ans,dp[n][i]);
	
	cout<<ans;
}

