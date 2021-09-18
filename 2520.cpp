#include<bits/stdc++.h>

#define int long long
using namespace std;

int t;
int a,b,x,y;
int k;
bool pd(int l,int r)
{
	return (!(l%k))&&!((r%k));
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>x>>y;
		k=(__gcd(a,b))<<1;
		if(pd(x,y)||pd(x+a,y+b)||pd(x+b,y+a)||pd(x+a+b,y+a+b))
		cout<<'Y'<<endl;
		else
		cout<<'N'<<endl;
	}
	
	return 0;
}
