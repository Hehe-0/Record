/*#include<bits/stdc++.h>

#define mid ((l+r)>>1)
#define lson ((l+r)<<1)
#define rson ((l+r)<<1|1)
#define lso (x<<1)
#define rso (x<<1|1)
#define mide ((a[x].l+a[x].r)>>1)
using namespace std;
const int N=2e5+7;

int n,m;
int data[N];
struct node
{
	int l,r;
	int lsum,rsum;
	int ls,rs;
	int sum;
}a[N<<2];

node push(node x,node y)
{
	node re;      
	re.l=x.l;
	re.r=y.r;
	re.sum=x.sum+y.sum;
	if(x.rs<y.ls)
	re.sum+=x.sum*y.sum;
	
	if(x.ls==x.r-x.l+1&&x.rs<y.ls)
	re.lsum=x.lsum+y.lsum;
	else
	re.lsum=x.lsum;
	if(y.rsum==y.rs-y.ls+1&&x.rs<=y.ls)
	re.rsum=x.rsum+y.rsum;
	else
	re.rsum=y.rsum;
	
	re.ls=x.ls;
	re.rs=y.rs;
	return re;
}

void build(int x,int l,int r)
{
	if(l==r)
	{
		a[x].l=l;
		a[x].r=r;
		a[x].sum=1;
		a[x].lsum=a[x].rsum=1;
		a[x].ls=a[x].rs=data[l];
		
		return ;
	}
	build(lson,l,mid);
	build(rson,mid+1,r);
	
	a[x]=push(a[lson],a[rson]);
	
	return ;
}

void updat(int x,int f,int k)
{
	if(a[x].l==f&&a[x].r==f)
	{
		a[x].ls=a[x].rs=k;
		return ;
	}
	if(f<=mide) updat(lso,f,k);
	else updat(rso,f,k);
	a[x]=push(a[lso],a[rso]);
	return ;	
}
node query(int x,int l,int r)
{
	if(a[x].l>=l&&a[x].r<=r)
	return a[x];
	if(l<=mide&&r>mide)
	return push(query(lso,l,r),query(rso,l,r));
	if(l<=mid&&r>mid) 
	return push(query(lso,l,r),query(rso,l,r));
	else if(r<=mid) 
	return query(lso,l,r);
	else return 
	query(rso,l,r);
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>data[i];
	build(1,1,n);
	
	for(int i=1;i<=m;i++)
	{
		int q,w,e;
		cin>>q>>w>>e;
		if(q==1)
		updat(1,w,e);
		if(q==2)
		cout<<query(1,w,e).sum<<endl;
	}
	
	return 0;
}*/
#include<bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson (x<<1),l,mid
#define rson (x<<1|1),mid+1,r
using namespace std;
typedef long long LL;
const int maxn = 2e5+20;
int n,m;
struct node{
    int lx,rx,len;
    LL sum,suml,sumr;
}Tree[maxn<<2];

inline int read(){
    int x = 0 , f = 1 ; char c = getchar() ;
    while( c < '0' || c > '9' ) { if( c == '-' ) f = -1 ; c = getchar() ; } 
    while( c >= '0' && c <= '9' ) { x = x * 10 + c - '0' ; c = getchar() ; } 
    return x * f ;
}

node pushup(node x,node y){
    node z;
    z.lx = x.lx ;z.rx = y.rx ;
    z.sum = x.sum + y.sum ;z.len = x.len + y.len ;
    if(x.rx<=y.lx){
        z.sum += 1ll * x.sumr * y.suml ;
        if(x.suml==x.len) z.suml = x.len + y.suml ;
        else z.suml = x.suml ;
        if(y.sumr==y.len) z.sumr = x.sumr + y.len ;
        else z.sumr = y.sumr ;
    }
    else z.suml = x.suml ,z.sumr = y.sumr ;
    return z; 
}

void build(int x,int l,int r){
    if(l==r){
        Tree[x].lx = Tree[x].rx = read();
        Tree[x].len = Tree[x].sum = Tree[x].suml = Tree[x].sumr = 1;
        return ; 
    }
    build(lson);build(rson);
    Tree[x] = pushup(Tree[x<<1],Tree[x<<1|1]);
}

void update(int x,int l,int r,int pos,int k){
    if(l==r){
        Tree[x].lx = Tree[x].rx = k;
        return ;
    }
    if(pos<=mid) update(lson,pos,k);
    else update(rson,pos,k);
    Tree[x] = pushup(Tree[x<<1],Tree[x<<1|1]);
}

node query(int x,int l,int r,int L,int R){
    if(L<=l&&r<=R) return Tree[x];
    if(R<=mid) return query(lson,L,R);
    if(mid<L) return query(rson,L,R);
    return pushup(query(lson,L,R),query(rson,L,R));
}

int main(){
    n = read();m = read();
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int op = read(),l = read(),r = read();
        if(op==1) update(1,1,n,l,r);
        else printf("%lld\n",query(1,1,n,l,r).sum);
    }
    return 0;
}
