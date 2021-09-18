#include<bits/stdc++.h>

using namespace std;

struct node
{
	int x,y;
}a[10001];
int n;
int ans,cnt;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x>>a[i].y;
	}
	for(int i=1;i<n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			cnt=0;
			int xx=a[j].x-a[i].x;
			int yy=a[j].y-a[i].y;
			for(int k=1;k<=n;k++)
			{
				if(k==i||k==j)continue;
				int xxx=a[k].x-a[i].x;
				int yyy=a[k].y-a[i].y;
				
				if(!(xx*yyy-xxx*yy))
				cnt++;
			}
						
			ans=max(ans,cnt);
		}
		
	}
	cout<<ans+2;
	
	
	return 0;
}
