#include<bits/stdc++.h>

#define int long long
using namespace std;
const int inf=256*256-2*256+1;

int n;
bool dp[inf<<1];
int a[55];
int ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	dp[0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=a[i];j<=inf;j++)
		{
			dp[j]=dp[j]||dp[j-a[i]];	
		}
	}
	
	for(int i=inf;i;i--)
	{
		if(!dp[i])
		{
			ans=i;
			break;
		}
	}
	if(ans>65024)
	cout<<0;
	else
	cout<<ans;
	
	
	return 0;
}
