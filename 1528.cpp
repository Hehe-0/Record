#include<bits/stdc++.h>

using namespace std;
const int N=(1<<11)|1;

int n,m;
int mid;
int a[N],p[N];
int sum,pl;
int s[N],dp[N];

bool pd(int x,int deep)
{
	if(deep<=0)
	return 1;
	if(sum-pl<s[mid])
	return 0;
	
	for(int i=x;i<=n;i++)
	{
		if(dp[i]>=p[deep])
		{
			dp[i]-=p[deep];
			if(dp[i]<p[1])
			pl+=dp[i];
			
			if(p[deep]==p[deep-1])
			{
				if(pd(i,deep-1))
				return 1;
			}
			else if(pd(1,deep-1))
			return 1;
			if(dp[i]<p[1])
			pl-=dp[i];
			
			dp[i]+=p[deep];
		}
		
	}
	
	
	return 0;
}

int cmp(const void *a, const void *b)
{
    return(*(int *)a-*(int *)b);
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];	
		sum+=a[i];
	}
	cin>>m;
	
	for(int i=1;i<=m;i++)
		cin>>p[i];	

    qsort(a+1,n,sizeof(int),cmp);
    qsort(p+1,m,sizeof(int),cmp);
	s[0]=0;
	
	for(int i=1;i<=m;i++)
	s[i]=s[i-1]+p[i];
	
	while(s[m]>sum)
	m--;
	
	int l=0,r=m;
	while(l<=r)
    {
        mid=l+r>>1;    
        for(int i=1;i<=n;i++)
		dp[i]=a[i];
        pl=0;
        if(pd(1,mid))
		l=mid+1;
        else 
		r=mid-1;        
    }
    cout<<l-1;
	
	return 0;
}
