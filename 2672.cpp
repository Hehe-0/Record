#include<bits/stdc++.h>

using namespace std;

int n,x;

struct node
{
	int s;
	int t;	
}a[101010];
int sum[101010];

int dp[101010];
int fi[101010];
//前i项的最大值？ 

bool cmp(node x,node y)
{
	return x.t>y.t;
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i].s;
	for(int i=1;i<=n;i++)
	cin>>a[i].t;
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++)
	sum[i]=sum[i-1]+a[i].t;
		

	for(int i=n;i>=1;i--)
	fi[i]=max(fi[i+1],2*a[i].s+a[i].t);	
	
	for(int i=1;i<=n;i++)
	dp[i]=max(dp[i-1],a[i].s);
	

	for(int i=1;i<=n;i++)
	{
		cout<<max(sum[i]+2*dp[i],sum[i-1]+fi[i])<<endl;
	}
	
	return 0;
}
