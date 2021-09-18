#include<bits/stdc++.h>

using namespace std;
const int N=1e7+7;
const int mov=1e6;

int a[N],n,m;
int ans,tot;

int main()
{
	ios::sync_with_stdio(false);	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int v,x;
		cin>>v>>x;
		a[x- 3*v+1+mov]++;
		
		a[x- 2*v+1+mov]-=2;
		a[x+ 1+mov]+=2;
		a[x+ 2*v+1+mov]-=2;
		a[x+ 3*v+1+mov]++;
	}

	for(int i=0;i<=mov;i++)
	{
		tot+=a[i];
		ans+=tot;
	}
	for(int i=mov+1;i<=m+mov;i++)
	{
		tot+=a[i];
		ans+=tot;
		
		cout<<ans<<' ';
	}
	return 0;
}
