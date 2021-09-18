#include <bits/stdc++.h>
#define int long long
#define N (1000 + 7)
using namespace std;

int n,k,a[N],b[N];
double m, f[N];

signed main()
{
	cin>>k>>m>>n;
	fill(f+1,f+1+n,1e15+7);
	for (int i=1;i<=n;i++)
		cin>>a[i]>>b[i];
		
	for(int R=1;R<=n;R++)
	{
		int L=R,sum=a[L],spe=b[L];
		
		while(L&&sum<=k) 
		{	
			L--;
			f[R]=min(f[R],f[L]+m/spe);
			sum+=a[L],spe=min(spe,b[L]);
		}
		
	} 
	printf("%.1lf",f[n]*60);
	
	return 0;
}
