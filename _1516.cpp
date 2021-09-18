#include<bits/stdc++.h>

using namespace std;

#define int long long

int xx,yy,ans;
int exgcd(int a,int b,int &xx,int &yy)
{
	if(b==0)
	{
		xx=1;
		yy=0;
		return a;
	}
	ans=exgcd(b,a%b,xx,yy);
	int t=xx;
	xx=yy;
	yy=t-(a/b)*yy;
	return ans;
}
int x,y,m,n,l;
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
	if(a%ans!=0)
	{
		printf("Impossible");
	}
	else
	{
		cout<<((xx*(a/ans))%(l/ans)+(l/ans))%(l/ans);
	}
	return 0;
}
