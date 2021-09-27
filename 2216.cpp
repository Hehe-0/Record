#include<bits/stdc++.h>

using namespace std;

int n,m,k;

int head,tail,ans = 2147483647;
int f[1005][1005],g[1005][1005];
int x[1005][1005],y[1005][1005];
int q[1005],s[1005][1005];	

int main() 
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>s[i][j];
			
	for(int i=1;i<=n;i++) 
	{
		head=tail=q[1]=1;
		for(int j=2;j<=m;j++) 
		{
			while(head<=tail&&s[i][q[tail]]<=s[i][j]) 
			tail--;
			q[++tail]=j;
			
			while(head<=tail&&q[head]<=j-k)
			head++;
			if(j>=k) 
			f[i][j-k+1]=s[i][q[head]];
		}
	}
	
	memset(q,0,sizeof(q));
	for(int i=1;i<=m-k+1;i++) 
	{
		head=tail=q[1]=1;
		for(int j=1;j<=n;j++) 
		{
			while(head<=tail&&f[q[tail]][i]<=f[j][i]) 
			tail--;
			q[++tail]=j;
			
			while(head<=tail&&q[head]<=j-k)
			head++;
			if(j>=k) 
			x[j-k+1][i]=f[q[head]][i];
		}
	}
	
	memset(q,0,sizeof(q));
	
	for(int i=1;i<=n;i++) 
	{
		head=tail=q[1]=1;
		for(int j=2;j<=m;j++) 
		{
			while(head<=tail&&s[i][q[tail]]>=s[i][j]) 
			tail--;
			
			q[++tail]=j;
			while(head<=tail&&q[head]<=j-k) 
			head++;
			if(j>=k) 
			g[i][j-k+1]=s[i][q[head]];
		}
	}
	
	memset(q,0,sizeof(q));
	for(int i=1;i<=m-k+1;i++) 
	{
		head=tail=q[1]=1;
		for(int j=1;j<=n;j++) 
		{
			while(head<=tail&&g[q[tail]][i]>=g[j][i]) 
			tail--;
			
			q[++tail]=j;
			while(head<=tail&&q[head]<=j-k)
			head++;
			
			if(j>=k) 
			y[j-k+1][i]=g[q[head]][i];
		}
	}
	
	for(int i=1;i<=n-k+1;i++)
		for(int j=1;j<=m-k+1;j++) 
			ans=min(ans,x[i][j]-y[i][j]);
	
	cout<<ans;
	return 0;
}
