#include<bits/stdc++.h>

using namespace std;
const int N=333;

int n;
int a[N<<10];
int sum,ans;
int dp[N<<10];
bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++)
	{
		for(int j=sum;j>=0;j--)
		{
			if(j>=a[i])
			{
				dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
			}
			if(dp[j]>(sum>>1)&&(dp[j]-a[i]<=(sum>>1)))
			ans=max(ans,dp[j]);
		}
		
		
	}
	cout<<ans;
	
	return 0;
}
