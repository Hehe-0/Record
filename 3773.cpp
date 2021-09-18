#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=3e5+7,mod=1e9+7;

int n,ans;
int a[N];
int f[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(register int i=1;i<=n;i++)
	cin>>a[i];
	
	for(register int i=n;i>=1;i--)
	{
			
		for(register int j=a[i];j>0;j=(a[i]&(j-1)))
		f[a[i]]=((f[a[i]]+f[j])%mod+mod)%mod;
		
		ans=((ans+f[a[i]])%mod+mod)%mod;
		f[a[i]]=((f[a[i]]+1)%mod+mod)%mod;
	}
	cout<<ans;
	return 0;
}
