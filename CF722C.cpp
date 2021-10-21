#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+7;

int n,m;
int a[N],b[N];
int x,y;
int q[N],f[N];

int find(int k)
{
	if(f[k]==k)
	return k;
	return f[k]=find(f[k]);
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;	
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	cin>>b[i];
	
	for(int i=n;i>=1;i--)
	{
		q[i]=x;	
		f[b[i]]=b[i];
		if(f[b[i]-1])
		{
			int fx=find(b[i]-1);
			a[b[i]]+=a[fx];
			f[fx]=f[b[i]];
		}
		if(f[b[i]+1])
		{
			int fx=find(b[i]+1);
			a[b[i]]+=a[fx];
			f[fx]=f[b[i]];
		}
		x=max(x,a[b[i]]);
	}
	
	for(int i=1;i<=n;i++)
	cout<<q[i]<<endl;
	return 0;
}
