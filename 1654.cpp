#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n;
double x_2[N] ,x[N];
double a;
double  dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;	
	
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		x[i]=(x[i-1]+1)*a;
		x_2[i]=(x_2[i-1]+2*x[i-1]+1)*a;
		
		dp[i]=dp[i-1]+(3*(x[i-1]+x_2[i-1])+1)*a;
	}
	printf("%.1f\n",dp[n]);
	return 0;
}
