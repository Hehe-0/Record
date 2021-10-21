#include<bits/stdc++.h>

using namespace std;

double f[110][110];
int l[110],r[110];
int n;
int t[210],cnt;
double ans[110];

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for (int i=1;i<=n;i++) 
	{
		cin>>l[i]>>r[i];
		t[++cnt]=l[i],t[++cnt]=r[i];
	}
	sort(t+1,t+cnt+1);
	cnt=unique(t+1,t+cnt+1)-t-1;
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		ans[j]=0;
		
		for (int j=1;j<cnt;j++)
		if (l[i]<=t[j]&&t[j+1]<=r[i])
		{
			int pos=1;
			for (int i1=0;i1<=n;i1++)
				for (int j1=0;j1<=n;j1++)
					f[i1][j1]=0;
			f[0][0]=1;
			
			for (int k=1;k<=n;k++)
			if (i!=k)
			{
				if (r[k]<=t[j]) 
				{
				pos++; 
				continue;
				}
				if (l[k]>=t[j+1]) 
				continue;
				double num1=1.0*(r[k]-t[j+1])/(r[k]-l[k]),num2=1.0*(t[j+1]-t[j])/(r[k]-l[k]),num3=1.0*(t[j]-l[k])/(r[k]-l[k]);
				for (int i1=k;i1>=0;i1--)
					for (int j1=k-i1;j1>=0;j1--)
					{
						f[i1+1][j1]+=f[i1][j1]*num3;
						f[i1][j1+1]+=f[i1][j1]*num2;
						f[i1][j1]*=num1;
					}
			}
			
			for (int i1=0;i1<=n-pos;i1++)
			{
				for (int j1=n-i1-pos;j1>=0;j1--) 
				{
					ans[i1+pos]+=f[i1][j1]*(t[j+1]-t[j])/(j1+1);
					ans[i1+pos+j1+1]-=f[i1][j1]*(t[j+1]-t[j])/(j1+1);
				}
			}
			
		}
		for (int j=1;j<=n;j++) 
		ans[j]+=ans[j-1];
		for (int j=1;j<=n;j++) 
		printf("%.10f%c",ans[j]/(r[i]-l[i]),j==n?'\n':' ');
	}
	return 0;
}

