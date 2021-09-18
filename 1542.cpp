#include<bits/stdc++.h>

using namespace std;

int n;

struct node
{
	long double st,end,h;	
}a[200011];

long double l=0,r=10000001; 

bool pd(long double mid)
{
	long double now=0;
	for(int i=1;i<=n;i++)
	{
		now+=(a[i].h/mid);
		
		if(now<=a[i].end)
			now=max(now,a[i].st);
		else
			return 1;
	}
	
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].st>>a[i].end>>a[i].h;
	}
	
	while(r-l>0.000000001)
	{
		long double mid=(l+r)/2;	
		if(pd(mid))
		l=mid;
		else
		r=mid;
	}
	
	printf("%.2Lf",l);

	return 0;
}
