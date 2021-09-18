#include<bits/stdc++.h>

#define int long long 
using namespace std;

#define pii pair<int,int>
#define pil pair<int,ll>
#define mkp make_pair

const int INF=0x3f3f3f3f;
const int maxn=1e6+10;

struct Edge
{
    int x,y,w;
    int id,real;
}edge[maxn];

int n,m;
int vis[maxn],id[maxn],in[maxn],pre[maxn];
int lastEdge[maxn],used[maxn];
int addEdge[maxn],delEdge[maxn];

int zhuliu(int root,int n,int m)
{
    int res=0,edgeNum=m;
    while(true)
    {
        for(int i=1;i<=n;i++) 
		in[i]=INF;
        for(int i=1;i<=m;i++)//找到每个点的最小入边及其编号 
        {
            int x=edge[i].x,y=edge[i].y;
            if(edge[i].w<in[y]&&x!=y)
            {
                pre[y]=x;
                in[y]=edge[i].w;
                lastEdge[y]=edge[i].id;
            }
        }
        for(int i=1;i<=n;i++)//判断是否可以形成最小树形图 
        {
            if(i==root) continue;
            if(in[i]==INF) return -1;    
        }
        int cnt=0; 
		in[root]=0;
        memset(id,-1,sizeof id);
        memset(vis,-1,sizeof vis);
        
        for(int i=1;i<=n;i++)
        {
            res+=in[i];
            if(i!=root) 
			used[lastEdge[i]]++;
            int y=i;
            while(vis[y]!=i&&id[y]==-1&&y!=root)
            {
                vis[y]=i;
                y=pre[y];
            }
            if(y!=root && id[y]==-1)
            {
                cnt++;
                for(int x=pre[y];x!=y;x=pre[x]) id[x]=cnt;
                id[y]=cnt;    
            }
        }
        
        if(cnt==0) 
		break;
		
        for(int i=1;i<=n;i++)//独立点 
            if(id[i]==-1) id[i]=++cnt;
        
        for(int i=1;i<=m;i++)
        {
            int x=edge[i].x,y=edge[i].y;
            edge[i].x=id[x];edge[i].y=id[y];
            if(id[x]!=id[y])    
            {
                edge[i].w-=in[y];
                delEdge[++edgeNum]=lastEdge[y];
                addEdge[edgeNum]=edge[i].id;
                edge[i].id=edgeNum;    
            }
        }
        n=cnt;
        root=id[root];
    }
    
    for(int i=edgeNum;i>m;i--)
    {
        if(used[i])
        {
            used[delEdge[i]]--;
            used[addEdge[i]]++;
        }
    }
    
    return res;
}

signed main()
{
	ios::sync_with_stdio(false);
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        cin>>edge[i].x>>edge[i].y>>edge[i].w;
        edge[i].id=i;
        edge[i].real=edge[i].w;    
    }
    
    int res=zhuliu(1,n,m);
    
    if(res==-1||res==0) 
	cout<<res<<endl;
    else
    {
        cout<<res<<endl;
        for(int i=1;i<=m;++i)
        {
            if(used[i]&&edge[i].real)
                cout<<i<<' ';
        }
        cout<<endl;
    }
    
    return 0;    
}
