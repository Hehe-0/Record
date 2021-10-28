#include<bits/stdc++.h>

using namespace std;
/*const int N=123;

int n;
int _,cnt;
int head[N],nxt[N<<3],to[N<<1];
bool flag[N];
int dfn[N],low[N];
int st[N],top,num;
void add(int x,int y)
{
	_++;
	nxt[_]=head[x];
	to[_]=y;
	head[x]=_;
	return ;
}
int tot;
void init()
{
	_=0;
	tot=0;
	memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	cnt=0;
	
	return ;
}

int dfs(int x,int fa)
{
	low[x]=dfn[x]=++cnt;
	int d=dfn[x];
	int numx=0,numy=0;
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(!dfn[y])
		{
			num++;
			numy=dfs(y,x);
			numx=min(numx,numy);
			if(numy>=dfn[x])
			flag[x]=1;
		}
		else if(y!=fa)
		numx=min(numx,dfn[y]);
	}
	if(!fa&&num<2)
	flag[x]=0;
	return numx;	
}


*/

vector<int> graph[110];//vector型邻接表存图
int low[110],parent[110],num[110];
bool vis[110];//标记是否访问过（形成树的过程）
bool check[110];//当前这个点是否已经计算过（割点
int number,ans;//number是编号
void find_tree(int x)
{
    low[x]=num[x]=number++;//赋初值，low和num一样
    vis[x]=true;//标记已经访问过
    int tmp=0;//为了验证根节点有几个儿子  0.0
    for(int i=0; i<graph[x].size(); i++)
    {
        if(!vis[graph[x][i]])
        {
            parent[graph[x][i]]=x;
            tmp++;
            find_tree(graph[x][i]);
            if(low[graph[x][i]]>=num[x]&&x!=1&&!check[x])
            {
                 ans++;check[x]=true;
            }

            else if(tmp>1&&x==1&&!check[x])
            {
                ans++;
                check[x]=true;
            }
            low[x]=min(low[x],low[graph[x][i]]);//把x的low更新成包括他本身和他所有子节点的最小low值
        }
        else if(parent[x]!=graph[x][i])//反祖边
        {
            low[x]=min(low[x], num[graph[x][i]]);//把它赋成他的编号
        }
    }
}

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        memset(low,0,sizeof(low));
        memset(parent,0,sizeof(parent));
        memset(num,0,sizeof(num));
        int st,ed;
        for(int i=1;i<=n;i++)
        {
            graph[i].clear();
        }
        while(~scanf("%d",&st)&&st)
        {
            while(getchar()!='\n')
            {
                scanf("%d",&ed);
                graph[st].push_back(ed);
                graph[ed].push_back(st);
            }
        }
        memset(vis,0,sizeof(vis));
        memset(check,0,sizeof(check));
        number=0;
        ans=0;
        find_tree(1);
        printf("%d\n",ans);
    }
}

