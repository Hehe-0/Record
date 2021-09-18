#include<bits/stdc++.h>

using namespace std;
const int N=3210;

int n,m;
int a[N][N];
bool vis[N];
int cnt=1;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;	
	
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q][w]=1;
		a[w][q]=1;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(vis[i])
		continue;
		for(int j=i+1;j<=n;j++ )
		{
			if(vis[j]||a[i][j])
			continue;
			vis[i]=1;
			vis[j]=1;
			break;
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		if(cnt*3>n)
		break;
		if(vis[i])
		continue;
		
		cout<<i<<' ';
		cnt++;
	}
	
	cout<<endl;
	return 0;
}
