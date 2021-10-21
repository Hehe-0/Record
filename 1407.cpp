#include<bits/stdc++.h>
using namespace std;

const int N=2e5+7;

struct node{
    int net;
    int to;
}a[N*2];
int n,m;

int low[N],dfn[N],sum,head[N];
int rs[N],st[N],top,dep,cnt;
bool vis[N];

map<string,int>al;

void add(int i,int j)
{
    a[++cnt].to=j;
    a[cnt].net=head[i];
    head[i]=cnt;
    return ;
}

void tarjan(int u)
{
    dfn[u]=low[u]=++dep;
    st[++top]=u;
    vis[u]=1;
    
    for(int i=head[u];i;i=a[i].net)
    {
        int v=a[i].to;
        if(!dfn[v])
        {
            tarjan(v);
            low[u]=min(low[u],low[v]);
        }
        
        else if(vis[v])
            low[u]=min(low[u],dfn[v]);
        
    }
    
    if(low[u]==dfn[u])
    {
        ++sum;
        int now;
        do
        {
            now=st[top--];
            rs[now]=sum;
            vis[now]=false;
        }while(now!=u);
        
    }
    
    return ;
}

int main()
{
	ios::sync_with_stdio(false);
	
    cin>>n;
    for(int i=1;i<=n;i++)
    {
		string x,y;
        cin>>x;
        cin>>y;
        al[x]=i;
        al[y]=i+n;
        add(i,i+n);
    }
    
    cin>>m;
    for(int i=1;i<=m;i++)
    {
    	string x,y;
        cin>>x;
        cin>>y;
        add(al[y],al[x]);
    }
    for(int i=1;i<=(n<<1);i++)
    {
        if(!dfn[i])
            tarjan(i);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(rs[i]==rs[i+n])
            puts("Unsafe");
        else
            puts("Safe");
    }
    
    return 0;
}
