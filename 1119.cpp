#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=233;
const int inf=1e9+7;

int n,m,t;
int a[N],num;
int d[N][N];

void update(int x)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	if(d[i][j]>d[i][x]+d[j][x])
	d[i][j]=d[j][i]=d[i][x]+d[j][x];	
	}
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=0;i<n;i++)
	cin>>a[i];
	
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
		if(i==j)
		continue;
		d[i][j]=inf;
	}
	
	/*for(int i=0;i<n;i++)
	d[i][i]=0;*/
	
	for(int i=0;i<m;i++)
	{
		int x,y,z;
		cin>>x>>y>>z;
		d[x][y]=d[y][x]=z;
	}

	cin>>t;
	while(t--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		
		while(a[num]<=z&&num<n)
		{
			update(num);
			num++;
		}
		if(a[x]>z||a[y]>z)
		cout<<-1<<endl;
		else
		{
			if(d[x][y]==inf)
			cout<<-1<<endl;
			else
			cout<<d[x][y]<<endl;
		}
	}
	
	
	return 0;
}
