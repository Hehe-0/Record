#include<bits/stdc++.h>

#define int long long
using namespace std;

int t;
int n,num,ans;
int s1,s2,v1,v2;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		cin>>s1>>v1>>s2>>v2;
		ans=0;
		if(s1>s2)
		{
			swap(s1,s2);
			swap(v1,v2);
		}
		
		if(n>=(s2<<16))
		{
			for(int i=0;i<=s1;i++)
			{
				ans=max(ans,v2*i+(n-s2*i)/s1*v1);
			}
			for(int i=0;i<=s2;i++)
			{
				ans=max(ans,v1*i+(n-s1*i)/s2*v2);
			}
		}
		else
		{
			for(int i=0;i*s2<=n;i++)
			ans=max(ans,v2*i+(n-s2*i)/s1*v1);
		}
		cout<<"Case #"<<++num<<": "<<ans<<endl;
	}
	
	return 0;
}
