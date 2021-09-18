#include<bits/stdc++.h>

using namespace std;

int n;
int a[10000],t[10000],b[10000],ans[10000];
struct node
{
	int minn,num;
}th[10000];

bool cmp(node x,node y)
{
	return x.minn<y.minn;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		th[i].num=i;
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>b[i];
		th[i].minn=min(a[i],b[i]);
	}
	sort(th+1,th+1+n,cmp);
	
	int l=0,r=n+1;
	for(int i=1;i<=n;i++)
	{
		if(th[i].minn==a[th[i].num])
		{
			l++;
			ans[l]=th[i].num;
		}
		else
		{
			r--;
			ans[r]=th[i].num;
		}
	}
	
	for(int i=1;i<=n;i++)
		t[i]=t[i-1]+a[ans[i]];
		
	int sum=t[1]+b[ans[1]];
	for(int i=2;i<=n;i++)	
	{
		sum=max(t[i],sum)+b[ans[i]];	
	}
	
	cout<<sum<<endl;
	
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<" ";	
	
	return 0;
}
