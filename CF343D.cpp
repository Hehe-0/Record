/*#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define ls ((l+r)<<1)
#define rs ((l+r)<<1|1)
using namespace std;
const int N=5e5+7;

int n;
int a[N<<2],siz[N<<2],mark[N<<2];
int f[N<<2],top[N<<2],dep[N<<2],son[N<<2];
int id[N<<2],wt[N<<2],w[N<<2];
int head[N],nxt[N<<1],to[N<<1];
int _,cnt;

void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
void push_down(int x,int l,int r)
{
	a[ls] = a[rs] = a[x];
	mark[ls] = mark[rs] = mark[x];
	mark[x] = -1;
}
void ch(int x,int l,int r,int s,int e,int k)
{
	if(s <= l && r <= e)	
	{
		a[x] = k;
		mark[x] = k;
		return ;
	}
	if(mark[x] >= 0)	push_down(x,l,r);
	if(s <= mid)	ch(ls,l,mid,s,e,k);
	if(e > mid)		ch(rs,mid+1,r,s,e,k);
}

int query(int x,int l,int r,int k)
{
	if(l == r)	return a[x];
	if(mark[x] >= 0)	push_down(x,l,r);
	if(k <= mid)	return query(ls,l,mid,k);
	else	return query(rs,mid+1,r,k);
}	
void dfs1(int x,int fa,int deep)
{
	f[x]=fa;
	dep[x]=deep;
	siz[x]=1;
	int maxson=-1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==fa)
		continue;
		dfs1(y,x,deep+1);
		
		siz[x]+=siz[y];
		
		if(siz[y]>maxson)
		{
			maxson=siz[y];
			son[x]=y;
		}
	}
	
	return ;
}

void dfs2(int x,int topf)
{
	cnt++;	
	id[x]=cnt;
	wt[cnt]=w[x];
	top[x]=topf;
	
	if(!son[x])
	return ;
	dfs2(son[x],topf);
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(y==f[x]||y==son[x])
		continue;
		
		dfs2(y,y);
	}
	
	return ;
}

void chr(int x,int y)
{
    while(top[x]!=top[y])
    {
        if(dep[top[x]]<dep[top[y]])
        swap(x,y);

        ch(1,1,n,id[top[x]],id[x],0);
        x=f[top[x]];
    }
    if(dep[x]>dep[y])
    swap(x,y);
    ch(1,1,n,id[x],id[y],0);
	return ;
}
int m;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dep[1]=1;
	memset(mark,-1,sizeof(mark));
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		int op,x;
		cin>>op>>x;
		
		if(op==1)
		ch(1,1,n,id[x],id[x]+siz[x]-1,1);
		else if(op==2)
		chr(1,x);
		else
		cout<<query(1,1,n,id[x])<<endl;
	}
	
	
	
	return 0;
}*/




#include<bits/stdc++.h>		
const int N = 5e5 + 5;
using namespace std;
int n, m, head[N], cnt, dfn[N], hev[N], dep[N], siz[N], top[N], sum, fa[N];
struct node{
	int u, v, nxt;
}edge[N << 1];
void add(int u, int v){
	edge[++ cnt].u = u;
	edge[cnt].v = v;
	edge[cnt].nxt = head[u];
	head[u] = cnt;
}
struct tree{
	protected:
		#define ls(o) (o << 1)
		#define rs(o) (o << 1 | 1)
		#define mid ((l + r) >> 1)
		int tr[N << 2], laz[N << 2];
		void up(int o){ tr[o] = tr[ls(o)] + tr[rs(o)];}
		void down(int o, int l, int r){
			laz[ls(o)] = laz[rs(o)] = laz[o];
			tr[ls(o)] = laz[o] * (mid - l + 1);
			tr[rs(o)] = laz[o] * (r - mid);
			laz[o] = -1;
		}
		void build(int o, int l, int r){
			if(l == r){ tr[o] = 0; return ;}
			build(ls(o), l, mid); build(rs(o), mid + 1, r);
			up(o);
		}
	public:
		void change(int o, int l, int r, int L, int R, int val){
			if(L <= l && r <= R){
				tr[o] = val * (r - l + 1); laz[o] = val;
				return ;
			}
			if(laz[o] != -1) down(o, l, r);
			if(L <= mid) change(ls(o), l, mid, L, R, val);
			if(R > mid) change(rs(o), mid + 1, r, L, R, val);
			up(o);
		}
		int query(int o, int l, int r, int x){
			if(l == r){ return laz[o];}
			if(laz[o] != -1) down(o, l, r);
			if(x <= mid) return query(ls(o), l, mid, x);
			else return query(rs(o), mid + 1, r, x);
		}
		void cz(int x){ build(1, 1, x);}
}St_tree;
struct Powtree{
	void Ps(int x){
		siz[x] = 1;
		for(int i = head[x]; i; i = edge[i].nxt){
			int to = edge[i].v;
			if(to == fa[x]) continue;
			dep[to] = dep[x] + 1;
			fa[to] = x;
			Ps(to);
			siz[x] += siz[to];
			if(siz[to] > siz[hev[x]]) hev[x] = to;
		}
	}
	void dfs(int x, int topp){
		top[x] = topp;
		dfn[x] = ++ sum;
		if(hev[x]) dfs(hev[x], topp);
		for(int i = head[x]; i; i = edge[i].nxt){
			int to = edge[i].v;
			if(to == fa[x] || to == hev[x]) continue;
			dfs(to, to);
		}
	}
	void cz(){
		dep[1] = 1;
		Ps(1);
		dfs(1, 1);
	}
}Pow_tree;
int read(){
	int op = 0, opp = 1; char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') opp = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0'){ op = (op << 1) + (op << 3) + (ch ^ 48); ch = getchar();}
	return op * opp;
}
void Build_tree(){
	Pow_tree.cz();
	St_tree.cz(n);
}
void Jump(int x){
	while(x){
		St_tree.change(1, 1, n, dfn[top[x]], dfn[x], 0);
		x = fa[top[x]];
	}
}
void maiin(){
	n = read();
	for(int i = 1, x, y; i < n; i ++){
		x = read(); y = read();
		add(x, y); add(y, x);
	}
	Build_tree();
	m = read();
	for(int i = 1, x, y; i <= m; i ++){
		x = read(); y = read();
		if(x == 1) St_tree.change(1, 1, n, dfn[y], dfn[y] + siz[y] - 1, 1);
		if(x == 2) Jump(y);
		if(x == 3) printf("%d\n", St_tree.query(1, 1, n, dfn[y]));
	}
}
int main(){
	maiin();
	return 0;
}
