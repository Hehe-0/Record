#include<bits/stdc++.h>

#define int long long
using namespace std;

int gcd(int x,int y)
{
	return (!y)?x:gcd(y,x%y);
}
int lcm(int x,int y)
{
	return (x*y)/gcd(x,y);
}

int t;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	
	while(t--)
	{
		int ans=0;
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		int m=sqrt(b2+1);
		
		for(int i=1;i<=m;i++)
		{
			if(!(b2%i))
			{
				if(gcd(i,a1)==a2&&lcm(i,b1)==b2)
				ans++;
				if(i!=(b2/i))
				{
					if(gcd(b2/i,a1)==a2&&lcm(b2/i,b1)==b2)
					ans++;
				}
				
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
