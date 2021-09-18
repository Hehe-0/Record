#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=888;
const int mod=1e9+7;

int a[N][N],b[N][N];
int n;

int power(int a,int b)
{
	int res=1;
	while(b)
	{
		if(b&1)res=res*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return res;
}

void solve()
{
	for(int i=1;i<=n;i++)
	{
		int pre=i;
		for(int j=i+1;j<=n;j++)
		{
			if(a[j][i]>0)pre=j;
		}
		swap(a[i],a[pre]);
		swap(b[i],b[pre]);
		int inv=power(a[i][i],mod-2);
		if(inv==0){cout<<"No Solution"<<endl;exit(0);}
		for(int j=1;j<=n;j++)
		{
			a[i][j]=a[i][j]*inv%mod;
			b[i][j]=b[i][j]*inv%mod;
		}
		
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			int div=a[j][i];
			for(int k=1;k<=n;k++)
			{
				a[j][k]=((a[j][k]-div*a[i][k])%mod+mod)%mod;
				b[j][k]=((b[j][k]-div*b[i][k])%mod+mod)%mod;
			}
			
			
		}
		
	}
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>a[i][j];
		
		b[i][i]=1;
	}
	
	solve();
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		cout<<b[i][j]<<' ';
		
		cout<<endl;
	}
	return 0;
}
