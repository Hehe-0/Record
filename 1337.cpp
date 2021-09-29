#include<bits/stdc++.h>

using namespace std;
const int N=1234;
const int cnt=1e5;
const int maxx=32767;
const double cold=0.996;

int n;
double ans,ansx,ansy; 
int T=4;

struct node
{
	int x,y,w;
}a[N];

double solve(double x,double y)
{
	double e=0.0;
	for(int i=1;i<=n;i++)
	{
		e+=sqrt((x-a[i].x)*(x-a[i].x)+(y-a[i].y)*(y-a[i].y))*a[i].w;
	}
	
	return e;
}

void annealing()
{
	double t=cnt;
	
	while(t>0.000000000000000001)
	{
		double xx=ansx+(rand()+rand()-maxx)*t;
		double yy=ansy+(rand()+rand()-maxx)*t;
		double f=solve(xx,yy),d=f-ans;
		
		if(d<0.0)
		{
			ans=f;
			ansx=xx;
			ansy=yy;
		}
		else if(exp(-d/t)*maxx>rand())
		{
			ansx=xx;
			ansy=yy;
		}
		
		t*=cold;
	}
	
	return ;
}

int main()
{
	ios::sync_with_stdio(false);
	//srand(time(NULL));
	srand(rand());
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].w;
		ansx+=a[i].x;
		ansy+=a[i].y;
	}
	ansx/=n;
	ansy/=n;
	ans=solve(ansx,ansy);
	
	while(T--)
	annealing();
	
	printf("%.3lf %.3lf\n",ansx,ansy);	
	
	return 0;
}
