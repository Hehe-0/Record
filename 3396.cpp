#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=16e5+7;

int n,m;
int a[N];
int h[555][555];
char op;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<=sqrt(n);j++)
		h[j][i%j]+=a[i];
	}
	
	while(m--)
	{
		cin>>op;
		int x,y;
		cin>>x>>y;
		
		if(op=='A')
		{
			if(x<=sqrt(n))
			cout<<h[x][y]<<endl;
			else
			{
				int re=0;
				for(int i=y;i<=n;i+=x)
					re+=a[i];
					
				cout<<re<<endl;
			}
		}
		else
		{
			for(int i=1;i<=sqrt(n);i++)
			h[i][x%i]+=y-a[x];
			
			a[x]=y;
		}
	}
	
	
	
	return 0;
}
