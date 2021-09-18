#include<bits/stdc++.h>

using namespace std;

int n,num;

struct node
{
	int l,h,t;

}a[10001];
int dp[10001];
//i高度的存活时间 
bool cmp(node x,node y)
{
	return x.t<y.t;
}

int main()
{
	ios::sync_with_stdio(false);
	memset(dp,-1,sizeof(dp));
	cin>>n>>num;
	for(int i=1;i<=num;i++)
	{
		cin>>a[i].t>>a[i].l>>a[i].h;
	}
	
	sort(a+1,a+1+num,cmp);
	dp[0]=10;
	
	for(int i=1;i<=num;i++)
	{
		for(int j=n;j>=0;j--)
		{
			if(dp[j]>=a[i].t)
			{
				if(j+a[i].h>=n)
				{
					cout<<a[i].t;
					return 0;
				}
				dp[j+a[i].h]=max(dp[j],dp[j+a[i].h]);
				dp[j]+=a[i].l;
			}
			
		}

	}
	cout<<dp[0];
	
	return 0;
}
