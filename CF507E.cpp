#include<bits/stdc++.h>

using namespace std;
#define sz 100000
#define INF 0x3f3f3f3f

typedef struct Edge
{
    int v,next,hs;
    int in;
}Edge;

bool vis[sz+1];
Edge eg[2*sz+2];
int head[sz+1];
int rep[sz+1],dis[sz+1],site[sz+1],pre[sz+1];
int alb,n,m,tp;

void Add(int u,int v,int w)
{
    eg[tp].v = v;
    eg[tp].hs = w;
    eg[tp].next = head[u];
    eg[tp].in = 0;
    head[u] = tp++;
    return ;
}

struct cmp
{
    bool operator() (int a,int b)
    {
        return dis[a] > dis[b] || (dis[a] == dis[b] && rep[a] > rep[b]);
    }
};
    int u,v,w;
void Dijkstra()
{
    priority_queue <int,vector<int>,cmp> q;
    memset(vis,0,sizeof(vis));
    memset(dis,INF,sizeof(dis));
    memset(rep,INF,sizeof(rep));
    dis[1]  = rep[1] = 0;
    pre[1] = 1;
    q.push(1);
    int i,v,p,mm,j,ss,ned;
    while(1)
    {
        p = q.top();
        q.pop();

        if(p == n) return;
        vis[p] = 1;

        for(j = head[p]; j != -1; j = eg[j].next)
        {
            v = eg[j].v;
            ned = eg[j].hs^1;
            if(!vis[v] && (dis[p] + 1 < dis[v] || (dis[p]+1 == dis[v] && rep[p] + ned < rep[v])))
            {
                dis[v] = dis[p] + 1;
                rep[v] = rep[p] +ned;
                site[v] = j;
                pre[v] = p;
                q.push(v);
            }
        }
        
    }
    return ;
}

void Bfs()
{
    memset(vis,0,sizeof(vis));
    queue <int> q;
    q.push(1);
    int i,u,v;
    vis[1] = 1;

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(i = head[u]; i != -1; i = eg[i].next)
        {
            if(eg[i].in == -1) continue;
            v = eg[i].v;
            if(!eg[i].hs && eg[i].in)
            {
            	cout<<u<<' '<<v<<' '<<1<<endl;
            }
            else if(eg[i].hs && !eg[i].in)
            {
            	cout<<u<<' '<<v<<' '<<0<<endl;
            }
            eg[i].in = eg[i^1].in = -1;
            if(!vis[v])
            {
                q.push(v);
                vis[v] = 1;
            }
        }
    }
    
    cout<<endl;
    return ;
}

int main()
{

    cin>>n>>m;
    memset(head,-1,sizeof(head));
    tp = alb = 0;

    while(m--)
    {
        cin>>u>>v>>w;
        Add(u,v,w);
        Add(v,u,w);
        if(w) alb++;
    }

    Dijkstra();
    for(u = n; u != pre[u]; u = pre[u]) eg[site[u]].in = eg[site[u]^1].in = 1;
    cout<<rep[n]*2 + alb - dis[n]<<endl;
    Bfs();

    return 0;
}
