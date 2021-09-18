#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n;
int a[N];
int dp[N],maxx[N];


int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
		
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	fill(dp,dp+1+n,1);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=i-1;j;j--)
		{
	//		if(dp[i]>maxx[i-1])
	//		break;
			
			if(a[i]&a[j])
			dp[i]=max(dp[j]+1,dp[i]);
		}
		
	//	maxx[i]=max(maxx[i-1],dp[i]);
	}
	
	cout<<dp[n];
	return 0;
}
