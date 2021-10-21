#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e7+7;
const int inf=1e9+7;

int n,s;
int maxx;

int sum[N<<1];
int pre[N<<1],dp[N<<1];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>s;
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		maxx=max(x,maxx);
		pre[i]=i;
		sum[i]=sum[i-1]+x;
	}
	for(int i=n+1;i<=n+n;i++)
	sum[i]=sum[i-1]+sum[i-n]-sum[i-n-1];
	
	while(s--)
	{
		int x;
		cin>>x;
		if(x<maxx)
		{
			cout<<"NIE"<<endl;
			continue;
		}
		else
		{
			for(int i=n+1,pos=1;i<=(n<<1);i++)
			{
				while(sum[i]-sum[pos]>x)
					pos++;
				
				dp[i]=dp[pos]+1;
				pre[i]=pre[pos];
				
				if(i-pre[i]>=n)
				{
					cout<<dp[i]<<endl;
					break;
				}
			}
			
		}
	}
	
    return 0;
}
