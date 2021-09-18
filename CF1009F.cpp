#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;
//长链剖分 
int head[N],nxt[N<<1],to[N<<1];

int _;
void add(int x,int y)
{
	_++;
	to[_]=y;	
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
int n;
vector<int>dp[N];
//dp[x][i]表示x的子树中深度为i的点个数 

int son[N];
//到节点i距离为j的节点数 
int dep[N];
void dfs1(int x,int fa)
{

	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		continue;
		dfs1(y,x);
		if(dep[y]>=dep[son[x]])
		{//寻找长儿子，与轻重链剖分类似 
			son[x]=y;	
			dep[x]=dep[y]+1;//继承深度 
		}
	}

	return ;
}
int ans[N];
int cnt;
void solve(int x,int fa)
{
	if(son[x])
	{//如果有长儿子 
		solve(son[x],x);
		//优先处理长儿子 
		swap(dp[x],dp[son[x]]);
		//注意深度 
		dp[x].push_back(1);
		ans[x]=ans[son[x]];
		//层层递传 
		if(dp[x][ans[x]]==1)
		ans[x]=dep[x];
		//到底了，记录 

		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(y==fa||y==son[x])
			continue;//长儿子已处理 
			solve(y,x);
			
			for(int j=dep[y];j>=0;j--)
			{//分配空间 
				int tmp=j+dep[x]-dep[y]-1;
				//tmp当个指针 
				dp[x][tmp]+=dp[y][j];
			    //普通儿子直接暴力合并
				//长儿子利用tmp指针，+1 
				if(dp[x][tmp]>dp[x][ans[x]]||(dp[x][tmp]==dp[x][ans[x]]&&tmp>ans[x]))
     			ans[x]=tmp;	
			}
		}
		
	}
	
	else
	{
		//建 
		dp[x].push_back(1);
		ans[x]=0;
	}

	return ; 
}
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int q,w;
		cin>>q>>w;
		add(q,w);
		add(w,q);
	}

	dfs1(1,0);
	// 建树 
	solve(1,0);
	
	for(int i=1;i<=n;i++)
	cout<<dep[i]-ans[i]<<endl;
	return 0;
 } 
