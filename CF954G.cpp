#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define int long long
using namespace std;
const int N=5e6+7;
const int inf=1e18+7;

int n;
int len,k;
int a[N];
int sum[N];

int l=inf>>1,r=inf<<1;
int w[N];
bool pd(int m)
{
	int f=k;
	int x=0;
	memset(w,0,sizeof(w));
	
	for(int i=1;i<=n;i++)
	{
		x+=w[i];
		
		if(sum[min(i+len,n)]-sum[max(i-len-1,0ll)]+x<m)
		{
			int dif=m-sum[min(i+len,n)]+sum[max(0ll,i-len-1)]-x;
			if(dif>f)
			return 0;
			f-=dif;
			x+=dif;
			
			w[i+len*2+1]-=dif;
		}
		
	}
	
	return 1;
}

int ans;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>len>>k;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
		l=min(l,a[i]);		
	}
	
	while(l<r)
	{
		if(pd(mid))
		{
			ans=mid;
			l=mid+1;	
		}
		else
		r=mid;
	}
	
	cout<<ans;
	return 0;
}
