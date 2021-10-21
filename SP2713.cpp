#include <bits/stdc++.h>

#define int long long
using namespace std;

const int N=1e5+5;
int n,q,opt,x,y,now;
int a[N],sum[N<<2],mark[N<<2];

void build(int k,int l,int r)
{
	if (l==r) {sum[k]=a[l]; mark[k]=(sum[k]<=1); return;}
	int mid=l+r>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	mark[k]=mark[k<<1]&mark[k<<1|1]; 
	
	return ;
}

void change(int k,int l,int r,int qx,int qy)
{
	if (mark[k]) return;
	if (l==r) {sum[k]=(int)sqrt(sum[k]*1.0); mark[k]=(sum[k]<=1); return;}
	int mid=l+r>>1;
	if (qx<=mid) change(k<<1,l,mid,qx,qy);
	if (mid<qy) change(k<<1|1,mid+1,r,qx,qy);
	sum[k]=sum[k<<1]+sum[k<<1|1];
	mark[k]=mark[k<<1]&mark[k<<1|1];
	
	return ;
}

int query(int k,int l,int r,int qx,int qy)
{
	if (qx<=l && r<=qy) return sum[k];
	int res=0;
	int mid=l+r>>1;
	if (qx<=mid) res+=query(k<<1,l,mid,qx,qy);
	if (mid<qy) res+=query(k<<1|1,mid+1,r,qx,qy);
	return res;
}

signed main()
{
	while (~scanf("%lld",&n))
	{
		now++;
		printf("Case #%lld:\n",now);
		for (register int i=1; i<=n; ++i) scanf("%lld",&a[i]);
		build(1,1,n);
		scanf("%lld",&q);
		while (q--)
		{
			scanf("%lld%lld%lld",&opt,&x,&y);
			if (x>y) swap(x,y);
			if (opt==0) change(1,1,n,x,y);
			else printf("%lld\n",query(1,1,n,x,y));
		}
		putchar('\n');
	}
return 0;
}

/*#include <bits/stdc++.h>

#define mid ((l+r)>>1)
#define ls (x<<1)
#define rs (x<<1|1)
#define int long long
using namespace std;
const int N=1e5+7;

int n,m;
int a[N<<2],mark[N<<2];
int da[N];

void push(int x)
{
    a[x]=a[ls]+a[rs];
    if(mark[ls]&&mark[rs])
    mark[x]=1;
    else
    mark[x]=0;
    return ;
}

void build(int x,int l,int r)
{
    if(l==r)
    {
        a[x]=da[l];
        if(a[x]==1||a[x]==0)
            mark[x]=1;
        else
        mark[x]=0;
        return ;
    }
    build(ls,l,mid);
    build(rs,mid+1,r);
	push(x);
    return ;
}


void change(int x,int l,int r,int L,int R)
{
    if(l==r)
    {
        a[x]=sqrt(a[x]);
        if(a[x]==1||a[x]==0)
        mark[x]=1;
        return ;
    }

    if(L<=mid&&!mark[ls])
    change(ls,l,mid,L,R);
    if(R>mid&&!mark[rs])
    change(rs,mid+1,r,L,R);
    push(x);
    return ;
}

int query(int x,int l,int r,int L,int R)
{
    int re=0;
    if(l>=L&&r<=R)
    {
        return a[x];
    }

    if(L<=mid)
    re+= query(ls,l,mid,L,R);
    if(R>mid)
    re+= query(rs,mid+1,r,L,R);
    
    return re;
}

int T;
signed main()
{
    ios::sync_with_stdio(false);
    
    while(cin>>n)
    {
        cout<<"Case #"<<++T<<':'<<endl;
        memset(a,0,sizeof(a));
        memset(mark,0,sizeof(mark));
        memset(da,0,sizeof(da));
        for(int i=1;i<=n;i++)
        cin>>da[i];
        
		build(1,1,n);
		cin>>m;
        while(m--)
        {
            int op,l,r;     
           cin>>op>>l>>r;
           if(l>r)
            swap(l,r);
            if(!op)
            {
                change(1,1,n,l,r);
            }
            else
            {
                cout<<query(1,1,n,l,r)<<endl;
            }
        }   
    }

    return 0;
}*/

