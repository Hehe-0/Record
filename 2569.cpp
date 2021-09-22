#include<bits/stdc++.h>

using namespace std;
const int N=2048;


int t,p,w;
int dp[N][N];
//i天后的j只支票最大利益 
int l,r;
int as[N],ap[N],bs[N],bp[N];
int q[N*2];
int maxx=-2147483600;

int main()
{
	ios::sync_with_stdio(false);
	cin>>t>>p>>w; 
	
	memset(dp,128,sizeof(dp));	
	for(int i=1;i<=t;i++)
	{
		cin>>ap[i]>>bp[i]>>as[i]>>bs[i];
	}

	for(int i=1;i<=t;i++)
	{
		for(int j=0;j<=as[i];j++)
			dp[i][j]=j*-1*ap[i];
		
		for(int j=0;j<=p;j++)	
			dp[i][j]=max(dp[i][j],dp[i-1][j]);
		if(i-1-w<=0)
		continue;
		
		l=1,r=0;
		for(int j=0;j<=p;j++)
		{
			while(l<=r&&q[l]<j-as[i])
			l++;
			if(l<=r)
			{
				int x=q[l];
				dp[i][j]=max(dp[i][j],dp[i-w-1][x]+x*ap[i]-j*ap[i]);
			}
			while(l<=r&&dp[i-w-1][q[r]]+q[r]*ap[i]<=dp[i-w-1][j]+j*ap[i])
			r--;
			
			q[++r]=j;
		}
		l=1,r=0;
		
		for(int j=p;j>=0;j--)
		{
			while(l<=r&&q[l]>j+bs[i])
			l++;
			if(l<=r)
			{
				int x=q[l];
				dp[i][j]=max(dp[i][j],dp[i-w-1][x]+x*bp[i]-j*bp[i]);
			}
			
			while(l<=r&&dp[i-w-1][q[r]]+q[r]*bp[i]<=dp[i-w-1][j]+j*bp[i])
			r--;
			
			q[++r]=j;
		}
	}
	
	for(int i=0;i<=p;i++)
	maxx=max(maxx,dp[t][i]);
	
	cout<<maxx;
	return 0;
 } 
