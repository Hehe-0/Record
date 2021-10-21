#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;
int n,m;
int cnt;
int _;
int head[N],nxt[N<<1],to[N<<1];
void add(int x,int y)
{
	_++;
	nxt[_]=head[x];
	head[x]=_;
	to[_]=y;
	return ;	
}
int ans[N],ind[N];
void init()
{
	cnt=0;
	memset(ans,0,sizeof(ans));
	memset(ind,0,sizeof(ind));
	memset(head,0,sizeof(head));
	_=0;
	
	return ;
}
int T;

void topsort()
{
	priority_queue< int > q;
	for(int i=1;i<=n;i++)
	{
		if(!ind[i])
		q.push(i);
	}
	
	while(!q.empty())
	{
		int x=q.top();
		q.pop();
		ans[++cnt]=x;
		
		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			ind[y]--;
			if(!ind[y])
			q.push(y);
		}
	}
	
	return ;
}


int main()
{
	//ios::sync_with_stdio(false);
	cin>>T;
	
	while(T--)
	{
		init();
		cin>>n>>m;
		
		for(int i=1;i<=m;i++)
		{
			int x,y;
			cin>>x>>y;
			add(y,x);
			ind[x]++;
		}
		topsort();
		if(cnt<n)
		{
			cout<<"Impossible!"<<endl;
		}
		else
		{
			for(int i=n;i>=1;i--)
			{
				cout<<ans[i]<<' ';
			}
			cout<<endl;
		}
	}
	
	
	return 0;
}
