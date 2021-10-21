#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;
const int inf=1e9+7;

int n,m;
int maxx;
int a[N],b[N];
int sum[N];

inline int read()
{
	int x = 0,fl = 1;char ch = getchar();
	while(ch<'0'||'9'<ch){if(ch=='-')fl=-1;ch = getchar();}
	while('0'<=ch&&ch<='9'){x = (x<<3) + (x<<1) + ch - '0';ch = getchar();}
	return x * fl;
}
int x,y;
int ans;
int main()
{
	
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		maxx=max(maxx,a[i]);
	}
	
	for(int i=1;i<=n;i++)
	{
		x=a[i];
		int j=0,k=0,las=-1;
		while(x>0)
		{
			if(!las)
			{
				b[x]++;
				sum[x]+=j;
				las=(x&1);
				x>>=1;
				j++;
				continue;
			}
			y=x;
			k=0;
			while(y<=maxx)
			{
				b[y]++;
				sum[y]+=j+k;				
				y<<=1;
				k++;
			}
			las=(x&1);
			x>>=1;
			j++;
		}
	}
	
	ans=inf;
	for(int i=0;i<=maxx;i++)
	{
		if(b[i]>=n)
			ans=min(ans, sum[i]);
		
	}
	cout<<ans<<endl;
	return 0;
}
