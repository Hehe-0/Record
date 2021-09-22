#include<bits/stdc++.h>

using namespace std;

inline int rd(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-1; c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0'; c=getchar();}
    return f*x;
}

const int maxn=(8e4)+50;
int N,M,lc[maxn],rc[maxn],val[maxn],pr[maxn],tot=0,siz[maxn];
int u,rt=0,s,t,x,y,z,id[maxn],fa[maxn],k;
//id[i]表示编号为i的书所在的节点编号
char o[15];
inline int New_node(int x){
    val[++tot]=x;
    siz[tot]=1;
    pr[tot]=rand();
    return tot;
}
inline void Pushup(int x){
    siz[x]=siz[lc[x]]+siz[rc[x]]+1;
    fa[lc[x]]=fa[rc[x]]=x;
    return;
}
inline void Split(int now,int k,int &x,int &y){
    if(!now){
        x=y=fa[x]=fa[y]=0;
        return;
    }
    if(siz[lc[now]]+1<=k){
        x=now;
        Split(rc[now],k-siz[lc[now]]-1,rc[now],y);
    }
    else {
        y=now;
        Split(lc[now],k,x,lc[now]);
    }
    Pushup(now);
    return;
}
inline int Merge(int x,int y){
    if(!x||!y){
        fa[x]=fa[y]=x+y;
        return x+y;
    }
    if(pr[x]<pr[y]){
        rc[x]=Merge(rc[x],y);
        Pushup(x);
        return x;
    }
    else{
        lc[y]=Merge(x,lc[y]);
        Pushup(y);
        return y;
    }
}
inline int Find(int x){//寻找x节点上有多少书
    int sum=0;
    sum+=siz[lc[x]];
    while(x!=rt){
        if(rc[fa[x]]==x)sum+=siz[lc[fa[x]]]+1;
        x=fa[x];
    }
    return sum;
}
inline int Query(int k){
    int now=rt;
    while(now){
        if(k<=siz[lc[now]])now=lc[now];
        else if(k==siz[lc[now]]+1)return now;
        else k-=siz[lc[now]]+1,now=rc[now];
    }
    return 0;
}
int main(){
    srand(20030304);
    N=rd();M=rd();
    for(int i=1;i<=N;i++){
        u=rd();
        rt=Merge(rt,id[u]=New_node(u));
    }
    while(M--){
        scanf("%s",o); s=rd();
        if(o[0]=='T'){
            k=Find(id[s]);
            Split(rt,k+1,x,z);
            Split(x,k,x,y);
            rt=Merge(Merge(x,Merge(lc[y],rc[y])),z);
            rt=Merge(id[s],rt);
        }
        else if(o[0]=='B'){
            k=Find(id[s]);
            Split(rt,k+1,x,z);
            Split(x,k,x,y);
            rt=Merge(Merge(x,Merge(lc[y],rc[y])),z);
            rt=Merge(rt,id[s]);
        }
        else if(o[0]=='I'){
            t=rd();
            k=Find(id[s]);
            Split(rt,k+1,x,z);
            Split(x,k,x,y);
            rt=Merge(Merge(x,Merge(lc[y],rc[y])),z);
            Split(rt,k+t,x,y);
            rt=Merge(Merge(x,id[s]),y);
        }
        else if(o[0]=='A'){
            printf("%d\n",Find(id[s]));
        }
        else {//Q
            printf("%d\n",val[Query(s)]);
        }
    }
    
    return 0;
}

/*#include<bits/stdc++.h>

using namespace std;
const int N=8e5+7;

int da[N],pos[N];
int n,m,root;
struct node
{
	int ls,rs,r;
	int s,siz,fa;
	bool rt;
}a[N];

void pd(int x)
{
	if(a[x].rt)
	{
		a[x].rt=0;
		a[a[x].ls].rt^=1;
		a[a[x].rs].rt^=1;	
		a[x].ls^=a[x].rs^=a[x].ls^=a[x].rs;	
	}
	return ;
}

void update(int x)
{
	a[x].siz=a[a[x].ls].siz+a[a[x].rs].siz+1;
	a[a[x].ls].fa=x;
	a[a[x].rs].fa=x;
	return ;
}

int merge(int x,int y)
{
	if(!x||!y)
	return x^y;
	pd(x);
	pd(y);
	
	if(a[x].r<a[y].r)
	{
		a[x].r=merge(a[x].rs,y);
		update(x);
		return x;
	}
	a[y].ls=merge(x,a[y].ls);
	update(y);
	
	return y;
}

void split(int now,int k,int &x,int &y)
{
	pd(now);	
	if(!k)
	{
		x=0;
		y=now;
		return ;
	}
	if(k==a[now].siz)
	{
		x=now;
		y=0;
		return ;
	}
	
	if(a[a[now].ls].siz>=k)
	{
		split(a[now].ls,k,x,a[now].ls);
		y=now;	
	}
	else
	{
		split(a[now].rs,k-a[a[now].ls].siz-1,a[now].rs,y);
		x=now;
	}
	update(now);
	return ;
}

int find(int x)
{
	int sz=a[a[x].ls].siz+1;
	for(int i=x;i;i=a[i].fa)
	{
		if(i==a[a[i].fa].rs)
		sz+=a[a[a[i].fa].ls].siz+1;
	}
	
	return sz;
}
string flag;

int main()
{
	srand(time(NULL));
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>da[i];
		pos[da[i]]=i;
		a[i]=(node){0,0,rand(),da[i],1,0,0};
		root=merge(root,i);
	}
	int p,x,t,y,z,f;
	while(m--)
	{
		cin>>flag;
		
		if(flag[0]=='T')
		{
			cin>>p;
			x=find(pos[p]);
			split(root,x-1,x,y);
			split(y,1,y,z);
			root=merge(merge(y,x),z);
			continue;
		}
		if(flag[0]=='B')
		{
			cin>>p;
			x=find(pos[p]);
			split(root,x-1,x,y);
			split(y,1,y,z);
			root=merge(merge(x,z),y);
			continue;
		}		
		if(flag[0]=='I')
		{
			cin>>p>>t;
			if(t)
			{
				int x=find(pos[p]);
				if(t==-1)
				{
					split(root,x-2,x,y);
					split(y,1,y,z);
					split(z,1,z,f);
					root=merge(merge(merge(x,z),y),f);
				}
				else
				{
					split(root,x-1,x,y);
					split(y,1,y,z);
					split(z,1,z,f);
					root=merge(merge(merge(x,z),y),f);					
					
				}
			}
			
		}
		if(flag[0]=='A')
		{
			cin>>p;
			cout<<find(pos[p])-1<<endl;
		}
		if(flag[0]=='Q')
		{
			cin>>p;
			split(root,p-1,x,y);
			split(y,1,y,z);
			cout<<a[y].s<<endl;
			
			root=merge(merge(x,y),z);
		}
		
	}
	
	
	return 0;
}*/
