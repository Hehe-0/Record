#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=5e5+7;

char s[N];
int n;
int _;
int head[N],nxt[N<<1],to[N<<1];
int f[N];
void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
stack<int >st;
int g[N],sum[N];

void dfs(int x)
{
	int p=0;
	if(s[x]==')')
	{
		if(st.size())		
		{
			p=st.top();	
			g[x]=g[f[p]]+1;
			st.pop();
		}
			
	}
	else if(s[x]=='(')
	{
		st.push(x);
	}
	sum[x]=sum[f[x]]+g[x];
	
	for(int i=head[x];i;i=nxt[i])
	dfs(to[i]);
	
	if(p)
	st.push(p);
	else if(st.size())
	st.pop();
	return ;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i];
	
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		add(x,i);
		f[i]=x;
	}
	dfs(1);
	
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans^=(i*sum[i]);
	}
	cout<<ans;
	return 0;
}
