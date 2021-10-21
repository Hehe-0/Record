#include<bits/stdc++.h>

#define mid ((l+r)>>1)
using namespace std;
const int N=5e5+7;

int n,m;
int a[N<<2];

bool small(int x,int y,int k)
{
	return a[x]<=k&&a[y]<=k;
}
bool big(int x,int y,int k)
{
	return a[x]>k&&a[y]>k;
}

bool pd(int k)
{
	for(int i=0;i<n-1;i++)
	{
		if(big(n+i,n+i+1,k)||big(n-i,n-i-1,k))
		return 1;
		if(small(n+i,n+i+1,k)||small(n-i,n-i-1,k))
		return 0;
	}
	
	return !small(1,1,k);
}
int l,r;
int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=(n<<1)-1;i++)
	cin>>a[i];
	
	l=1,r=(n<<1)-1;
	
	while(l<r)
	{
		if(pd(mid))
		l=mid+1;
		else
		r=mid;
	}
	
	cout<<r;
	return 0;
}
