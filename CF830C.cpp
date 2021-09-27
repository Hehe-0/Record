#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=123;

int n,k,d;
int a[N];
int solve(int m,int x)
{
	int re=0;
	for(int i=1;i<=m;i++)
	re+=((a[i]-1)/x);
	return re;
}
int sum;
bool pd(int x)
{
	return (n+solve(n,x))*x<=sum;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	sum+=k;
	
	for(int i=1;i*i<=sum;i++)
	{
		if(pd(i))
		d=max(d,i);
		if(pd(sum/i))
		d=max(d,sum/i);
	}
	
	cout<<d;
	return 0;
 } 
