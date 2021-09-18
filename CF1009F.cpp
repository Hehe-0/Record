#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;
//�����ʷ� 
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
//dp[x][i]��ʾx�����������Ϊi�ĵ���� 

int son[N];
//���ڵ�i����Ϊj�Ľڵ��� 
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
		{//Ѱ�ҳ����ӣ����������ʷ����� 
			son[x]=y;	
			dep[x]=dep[y]+1;//�̳���� 
		}
	}

	return ;
}
int ans[N];
int cnt;
void solve(int x,int fa)
{
	if(son[x])
	{//����г����� 
		solve(son[x],x);
		//���ȴ������� 
		swap(dp[x],dp[son[x]]);
		//ע����� 
		dp[x].push_back(1);
		ans[x]=ans[son[x]];
		//���ݴ� 
		if(dp[x][ans[x]]==1)
		ans[x]=dep[x];
		//�����ˣ���¼ 

		for(int i=head[x];i;i=nxt[i])
		{
			int y=to[i];
			if(y==fa||y==son[x])
			continue;//�������Ѵ��� 
			solve(y,x);
			
			for(int j=dep[y];j>=0;j--)
			{//����ռ� 
				int tmp=j+dep[x]-dep[y]-1;
				//tmp����ָ�� 
				dp[x][tmp]+=dp[y][j];
			    //��ͨ����ֱ�ӱ����ϲ�
				//����������tmpָ�룬+1 
				if(dp[x][tmp]>dp[x][ans[x]]||(dp[x][tmp]==dp[x][ans[x]]&&tmp>ans[x]))
     			ans[x]=tmp;	
			}
		}
		
	}
	
	else
	{
		//�� 
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
	// ���� 
	solve(1,0);
	
	for(int i=1;i<=n;i++)
	cout<<dep[i]-ans[i]<<endl;
	return 0;
 } 
