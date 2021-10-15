#include<bits/stdc++.h>

#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=1e6+7;

int n;
int a[N];
int ans;

signed main()
{
	ios::sync_with_stdio(false);	
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++)
	{
		cin>>a[i];	
		ans+=max(a[i-1],a[i]);
	}
	
	
	cout<<ans;
	
	
	return 0;
}
