#include<bits/stdc++.h>

#define int long long 
using namespace std;

int n,a[1005];
int f[1005][1005];
int root[1005][1005];

void print(int l,int r)
{
	if(l>r)
		return ;
	
	cout<<root[l][r]<<" ";
	print(l,root[l][r]-1);
	print(root[l][r]+1,r);
}

signed main() 
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i][i];
		root[i][i]=i;
	}
	
	for(int len=1;len<n;len++)
	{
		for(int i=1;i+len<=n;i++)
		{
			
			int j=i+len;
			
			f[i][j]=f[i+1][j]+f[i][i];
			root[i][j]=i;
			
			for(int k=i+1;k<=j;k++)
			{
				if(f[i][j]<f[i][k-1]*f[k+1][j]+f[k][k])
				{
					f[i][j]=f[i][k-1]*f[k+1][j]+f[k][k];
					root[i][j]=k;
				}
				
			} 
			
		}
		
		
	}
	
	cout<<f[1][n]<<endl;
	print(1,n);
	
	
	return 0;
}
