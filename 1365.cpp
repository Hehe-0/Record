#include<bits/stdc++.h>

using namespace std;
const int N=3e5+7; 

int n;
long double dp[N],len;
//注意精度问题
//dp[i]->前 i的期望 
string a;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>a;
	for(int i=1;i<=n;i++)
	{
		
		if(a[i-1]=='?')
			{
				dp[i]=dp[i-1]+len+0.5;
				len=(len+1)/2;
			}
		else if(a[i-1]=='o')
			{
				dp[i]=dp[i-1]+(len*2)+1;
				len++;
			}
		else if(a[i-1]=='x')
			{
				dp[i]=dp[i-1];
				len=0;
			}
			
	}

	
	printf("%.4Lf",dp[n]);
	return 0;
 } 
