#include<bits/stdc++.h>

#define int long long

using namespace std;

const int N=1e6+7;
const int mod=1000000007;
int qpow(int a,int b)
{
	int ans=1,c=a;
	while(b)
	{
		if(b&1)
			ans=ans*c%mod;
		b>>=1;
		c=c*c%mod;
	}
	return ans;
}

int fac[N];
int solve(int a,int b)
{
	return fac[a]*qpow(fac[b]*fac[a-b]%mod,mod-2)%mod;
}	

int n,ans=1;
int a[1234];

signed main()
{
	ios::sync_with_stdio(false);
	fac[0]=1;
	for(int i=1;i<=1000000;i++)
		fac[i]=fac[i-1]*i%mod;

	cin>>n;
	int sum=0;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	
	
	for(int i=n-1;i>-1;i--)
	{
		ans=ans*solve(sum-1,a[i]-1)%mod;
		sum-=a[i];
	}
	cout<<ans;
}
