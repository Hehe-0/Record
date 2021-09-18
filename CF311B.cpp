#include<bits/stdc++.h>

#define int long long
using namespace std;

int n,m,p;
int a[100010],q[100010];
int sum[100010],suma[100010];
int dp[110][100010];
int l,r;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	for(int i=2;i<=n;i++)
	{
		int w;
		cin>>w;
		sum[i]=sum[i-1]+w;
	}
	
	for(int i=1;i<=m;i++)
	{
		int h,t;
		cin>>h>>t;
		a[i]=t-sum[h];
	}
	sort(a+1,a+1+m);
	for(int i=1;i<=m;i++)
		suma[i]=suma[i-1]+a[i];
	
	memset(dp,0x3f,sizeof(dp));
	dp[0][0]=0;
	
	for(int i=1;i<=p;i++)
	{
		
		q[l=r=1]=0;
		for(int j=1;j<=m;j++)
		{
			int k=a[j];
				  
			while(l<r&&dp[i-1][q[l+1]]+suma[q[l+1]]-dp[i-1][q[l]]-suma[q[l]]<k*(q[l+1]-q[l]))
			l++;
			
			dp[i][j]=dp[i-1][q[l]]+suma[q[l]]-q[l]*a[j]+j*a[j]-suma[j];	
			
			while(l<r&&(dp[i-1][q[r]]+suma[q[r]]-dp[i-1][q[r-1]]-suma[q[r-1]])*(j-q[r])>(dp[i-1][j]+suma[j]-dp[i-1][q[r]]-suma[q[r]])*(q[r]-q[r-1]))
			r--;
			
			r++;
			q[r]=j;
		}
		
	}
	
	cout<<dp[p][m]<<endl;
	
	return 0;
}
