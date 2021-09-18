#include<bits/stdc++.h>


using namespace std;


int f[200005],a[200005];
priority_queue<pair<int,pair<int,int> >,vector<pair<int,pair<int,int> > > ,greater<pair<int,pair<int,int> > > >q;
int n;
int vis[200005];
int ansa[200005],ansb[200005];
int ans;


int main()
{
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		char c;
		cin>>c;
		if(c=='B')
		{
			f[i]=1;
		}
		else
		{
			f[i]=2;
		}
	}
	for(int i=1;i<=n;i++)
	cin>>a[i];
	
	
	for(int i=1;i<n;i++)
	{
		if(f[i]!=f[i+1])
		{
			q.push(make_pair(abs(a[i]-a[i+1]),make_pair(i,i+1)));
		}
	}
	while(!q.empty())
	{
		int x=q.top().second.first;
		int y=q.top().second.second;
		q.pop();
		if(vis[x]||vis[y])continue;
		vis[x]=1;
		vis[y]=1;
		ans++;
		ansa[ans]=x;
		ansb[ans]=y;
		while(x>0&&vis[x]==1)
		{
			x--;
		}
		while(y<=n&&vis[y]==1)
		{
			y++;
		}
		if(x>0&&y<=n&&f[x]!=f[y])
		{
			q.push(make_pair(abs(a[x]-a[y]),make_pair(x,y)));
		}
	}
	cout<<ans<<endl;
	for(int i=1;i<=ans;i++)
		cout<<ansa[i]<<" "<<ansb[i]<<endl;
	
	return 0;
}
