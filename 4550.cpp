#include<bits/stdc++.h>

using namespace std;
const int N=3e4+7;

double n;
double ans[N],sum[N];

int main() 
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		ans[i]=ans[i-1]+n/(double)(n-i+1);
		sum[i]=sum[i-1]+ans[i]*n/(double)(n-i+1);		
	}
	printf("%.2lf\n",sum[(int)n]);
	
	return 0;
}
