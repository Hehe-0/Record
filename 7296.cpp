#include<bits/stdc++.h>

using namespace std;
const int N=2e5+7;
const int inf=1e9+7;

char s[N];
int n,m;
int dp[1<<20|1];
int a[N],b[N];
int sum[22][22];

int main()
{
	ios::sync_with_stdio(false);
	cin>>s+1;
	n=strlen(s+1);
	for(int i=1;i<=n;i++)
	{
		b[i]=s[i];
	}
	sort(b+1,b+1+n);
	int m=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++)
	a[i]=lower_bound(b+1,b+1+m,s[i])-b-1;
	for(int i=1;i<n;i++)
	sum[a[i]][a[i+1]]++;
	memset(dp,0x3f,sizeof(dp));
	dp[0]=1;
	
    for(int k=1;k<(1<<m);k++)
    {
    	for(int j=0;j<m;j++)
    	{
    		if(k&1<<j)
    		{
    			int ans=dp[k^1<<j];
    			for(int i=0;i<m;i++)
    			if(k&1<<i)
    			ans+=sum[j][i];
    			
    			dp[k]=min(ans,dp[k]);
			}
		}
    	
	}
    
    
    cout<<dp[(1<<m)-1];
    return 0;
}
