#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e6+7;

int n,s;
int sumf[N],sumt[N];
int dp[N];
int q[N];

int l=1,r=1;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>s;
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=n;i++)
	{
		int e,w;
		cin>>e>>w;
		sumt[i]=sumt[i-1]+e;
		sumf[i]=sumf[i-1]+w;
	}
	dp[0]=0;
	
	for(int i=1;i<=n;i++)
	{
		while(l<r&&dp[q[l+1]]-dp[q[l]]<=(s+sumt[i])*(sumf[q[l+1]]-sumf[q[l]]))
		l++;
		
		dp[i]=dp[q[l]]-(s+sumt[i])*sumf[q[l]]+sumt[i]*sumf[i]+s*sumf[n];
		
		while(l<r&&(dp[q[r]]-dp[q[r-1]])*(sumf[i]-sumf[q[r]])>=(dp[i]-dp[q[r]])*(sumf[q[r]]-sumf[q[r-1]]))
		r--;
		q[++r]=i;
	}
	
	
	cout<<dp[n];	
	return 0;
}
