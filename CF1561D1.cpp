#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=3e5+7;

int n,mod;
int a[N];
int dp[N];

signed main()
{
	ios::sync_with_stdio(false);	
	cin>>n>>mod;
	dp[1]=a[1]=1;
	
	for(int i=2;i<=n;i++)
	{
		int pr,re=0;
		
		for(int j=1;j<=i;j=pr+1)
		{
			int x=i/j;
			pr=i/x;
				re=(re%mod+dp[x]*(pr-j+1)%mod)%mod;
						
		}
		dp[i]=dp[i]%mod+re%mod;
		dp[i]=dp[i]%mod+a[i-1]%mod;
		
		a[i]=(a[i-1]%mod+dp[i]%mod+mod)%mod;
	}
	
	cout<<dp[n]%mod;
	return 0;
}
