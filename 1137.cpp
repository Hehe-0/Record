#include<bits/stdc++.h>

using namespace std;
const int N=100011;
int n,m;
int head[N<<1],nxt[N<<1],to[N<<1];
int dp[N];

queue<int >q;
int in[N];
vector<int>s;

int _;
void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}

void bfs()//(topsort
{
	
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			in[y]--;
			if(!in[y] )
			{
				q.push(y);
				s.push_back(y);
			}
		}
	}
	
	return ;	
}

int main()
{
	ios::sync_with_stdio(false);
 	cin>>n>>m;
 	fill(dp+1,dp+n+1,1);
 	
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		add(q,w);
		in[w]++;
	}
	
	for(int i=1;i<=n;i++)
	{
		if(!in[i])
		{
		
		q.push(i);
		s.push_back(i);
		}
	}
	
	bfs();
	
	for(int i=1;i<=n;i++)
	{
		int x=s[i-1];
		for(int j=head[x];j;j=nxt[j])
		{
			int y=to[j];
			dp[y]=max(dp[x]+1,dp[y]);
			
		}
	
	}
	for(int i=1;i<=n;i++)
	cout<<dp[i]<<endl;
	
	
	
	return 0;
} 
