#include<bits/stdc++.h>

using namespace std;

int n,m;
int a[100001],w[100001],v[100001];
int dp[100001];
int _=1;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		int q,r,e;
		cin>>q>>r>>e;
		for(int j=1;j<=e;j<<=1)
		{
			_++;
			v[_]=q*j;
			w[_]=r*j;
			e-=j;
		}
		if(e) 
		{
		_++;
		v[_]=q*e;
		w[_]=r*e;
		}
	}
	for(int i=1;i<=_;i++)
	{
		for(int j=m;j>=w[i];j--)
			dp[j]=max(dp[j],dp[j-w[i]]+v[i]);
		
	}
	
	cout<<dp[m];
	
	
	
	return 0;
}
