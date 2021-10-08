#include<bits/stdc++.h>

const int N=3333;
using namespace std;
#define pi pair<int,int>
#define fi first
#define se second 


int n,m,f,a,b,c;
int par[N][N];

int main()
{
	
	cin>>n>>m>>f;
	pi ans={-1,-1};
	vector<int> g[n+1];
	
	for(int i=0;i<m;i++) 
	cin>>a>>b,g[a].push_back(b),g[b].push_back(a);
	
	map<pair<pi,int>,int> h;
	for(int i=0;i<f;i++) 
	cin>>a>>b>>c,h[{{a,b},c}]++;
	
	queue<pi> q;
	q.push({1,1});
	
	while(!q.empty())
	{
		pi x=q.front();
		q.pop();
		if(x.se==n)
		{
			ans=x;
			break;
		}
		for(int i:g[x.se])
		{
			if(par[x.se][i]||h[{x,i}]) 
			continue;
			
			par[x.se][i]=x.fi; 
			q.push({x.se,i});
		}
		
	}
	if(ans.fi==-1) 
	{
		cout<<"-1";
		return 0;
	}
	
	
	vector<int>path;
	while(ans.se!= 1) 
	{
		path.push_back(ans.se);
		ans={par[ans.fi][ans.se],ans.fi};
	}
	
	path.push_back(1);
	cout<<path.size()-1<<endl;
	for(int i=path.size()-1;i>=0;i--) 
	cout<<path[i]<<' ';
	
	return 0;
}
