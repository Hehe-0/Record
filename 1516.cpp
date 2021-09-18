#include<bits/stdc++.h>

#define int long long
using namespace std;

int x,y,m,n,l;
int xx,yy,ans;

int exgcd(int a,int b,int &xx,int &yy)
{
	if(!b)
	{
		xx=1;yy=0;
		return a;
	}
	ans=exgcd(b,a%b,xx,yy);
	int t=xx;
	xx=yy;
	yy=t-(a/b)*yy;
	
	return ans;
}


signed main()
{
	cin>>x>>y>>m>>n>>l;
	
	int b=n-m;
	int a=x-y;
	
	if(b<0)
	{
		b=-b;
		a=-a;
	}
	exgcd(b,l,xx,yy);
	if(a%ans)
		cout<<"Impossible";
	
	else
	{
		cout<<((xx*(a/ans))%(l/ans)+(l/ans))%(l/ans);
	}
	return 0;
}
