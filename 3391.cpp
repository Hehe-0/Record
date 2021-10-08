#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int Root;
int lazy[N];
int n,m,cnt;
int val[N],sze[N];
int ch[N][2],prip[N];

void pushup(int p)
{
    sze[p]=sze[ch[p][0]]+sze[ch[p][1]]+1;
}

void pushdpwn(int p)
{
    if(!lazy[p]||!p) return;
    ch[p][0]^=ch[p][1]^=ch[p][0]^=ch[p][1];
    lazy[ch[p][0]]^=1;
    lazy[ch[p][1]]^=1;
    lazy[p]=0;
    return ;
}

void split(int p,int k,int &x,int &y)
{
    if(!p) x=y=0;
    else
	{
        pushdpwn(p);
        if(k>sze[ch[p][0]]) 
		x=p,split(ch[p][1],k-sze[ch[p][0]]-1,ch[p][1],y);
        else 
		y=p,split(ch[p][0],k,x,ch[p][0]);
        pushup(p);
    }
    
    return ;
}

int merge(int x,int y)
{
    if(!x||!y) 
	return x+y;
    pushdpwn(x); 
	pushdpwn(y);
    
    if(prip[x]<prip[y])
	{
        ch[x][1]=merge(ch[x][1],y);
        pushup(x);
        return x;
    }
    else
	{
        ch[y][0]=merge(x,ch[y][0]);
        pushup(y);
        return y;
    }
}

int newnpde(int v)
{
    val[++cnt]=v;
    sze[cnt]=1;
    prip[cnt]=rand();
    
    return cnt;
}

void res(int l,int r)
{
    int a,b,c,d;
    split(Root,r,a,b);
    split(a,l-1,c,d);
    lazy[d]^=1;
    Root=merge(merge(c,d),b);
    
    return ;
}

void dfs(int npw)
{
    if(!npw) 
	return;
    pushdpwn(npw);
    dfs(ch[npw][0]);
    cout<<val[npw]<<' ';
    dfs(ch[npw][1]);
    
    return ;
}

signed main()
{
	ios::sync_with_stdio(false);
    srand(time(0));
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        Root=merge(Root,newnpde(i));
    for(int i=1;i<=m;i++)
	{
		int x,y;
        cin>>x>>y;
        res(x,y);
    }
    dfs(Root);
    
    return 0;
}
