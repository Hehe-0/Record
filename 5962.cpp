#include<bits/stdc++.h>

#define MAXN 1000010

using namespace std;

int n;
int fa[MAXN],sz[MAXN],cnt;
int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}

void merge(int x,int y)
{
	int a=get(x),b=get(y);
	if(a==b)return;
	if(sz[a]<sz[b])
	fa[a]=b,sz[b]+=sz[a];
	else 
	fa[b]=a,sz[a]+=sz[b];
}
int build(int siz)
{
fa[++cnt]=cnt;
sz[cnt]=siz;
return cnt;
}

char s[MAXN];
struct Node{
int l,r,pos;
}pre[MAXN],now[MAXN];
int pcnt,ncnt;
int ton[MAXN];

int getnum(int& pos)
{
	int ret=0;
	while(isdigit(s[pos]))
		ret=ret*10+s[pos++]-48;
	return ret;
}

int main()
{
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{
		memcpy(pre,now,sizeof(Node)*ncnt);
		pcnt=ncnt;ncnt=0;int p=0;
		
		scanf("%s",s+1);
		for(int j=1;j<=strlen(s+1);j++)
		{
			if(s[j]==';')break;
			int x=getnum(j),y=x;
			
			if(s[j]=='-'){j++;y=getnum(j);}
			now[ncnt]={x,y,build(y-x+1)};
			for(;p<pcnt&&pre[p].r<x;p++);
			for(;p<pcnt&&pre[p].l<=y;p++)
				merge(now[ncnt].pos,pre[p].pos);
				
			ncnt++;
			if(p)p--;
		}
	}
	for(int i=1;i<=cnt;i++)
		if(fa[i]==i)ton[sz[i]]++;
	for(int i=1000;i>0;i--)
	
		if(ton[i])printf("%d %d\n",i,ton[i]);
	return 0;
}

/*#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;

int n;
int f[N],siz[N];
struct node
{
	int l,r;
	int id;	
}x[N],y[N];
int len1,len2;

int find(int x)
{
	if(f[x]==x)
	return x;
	return f[x]=find(f[x]);
}
int _;
int build(int xx)
{
	_++;
	f[_]=_;
	siz[_]=xx;
	return _;
}

void merge(int xx,int yy)
{
	int fa=find(f[xx]),fb(f[yy]);
	if(siz[fa]<siz[fb])
	{
		f[fa]=fb;
		siz[fb]+=fa;
	}
	else
	{
		f[fb]=fa;
		siz[fa]+=fb;
	}
	return ;
}
char s[N];
inline int read(int &pos)
{
	int res=0;
	while(s[pos]>='0'&&s[pos]<='9')
		res=res*10+s[pos++]-'0';
	return res;
}
int ans[N];
int main()
{
//	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		memcpy(y,x,sizeof(node)*len1);		len2=len1;
		len1=0;
		int p=0;	
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0; j<len; j++)
		{
			if(s[j]==';') break;
			int u=read(j);
			int v=u;
			if(s[j]=='-') j++,v=read(j);
			x[len1]=(node){u,v,build(v-u+1)};
			for(; p<len2&&y[p].r<u; p++);	
			for(; p<len2&&y[p].l<=v; p++)	
				merge(x[len1].id,y[p].id);
			len1++;
			if(p) p--;
		}

		
		
		
		
	}
	
		for(int i=1; i<=_; i++)
		if(f[i]==i) ans[siz[i]]++;
	for(int i=1000; i>=1; i--)	
		if(ans[i]) printf("%d %d\n",i,ans[i]);
	
	return 0;
}*/
