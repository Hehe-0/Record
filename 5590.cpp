#include<bits/stdc++.h>

using namespace std;
const int N=2333;
const int M=1e5+7;

int x[N],y[N];
int n,m;
int _;
int head[N<<3],nxt[M],to[M];
int _1;
int head1[N<<3],nxt1[M],to1[M],edge[N];

void add(int x,int y)
{
	_++;
	to[_]=y;
	nxt[_]=head[x];
	head[x]=_;
	return ;
}
void add1(int x,int y,int z)
{
	_1++;
	to1[_1]=y;
	nxt1[_1]=head1[x];
	head1[x]=_1;
	edge[_1]=z;
	return ;
}
int d[N],p[N],f[N];
bool v[N];

bool spfa()
{
	memset(v,0,sizeof(v));
	memset(d,0x3f3f3f3f,sizeof(d));
	queue<int >q;
	q.push(0);
	d[0]=0;
	v[0]=1;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		v[x]=0;
		
		for(int i=head1[x];i;i=nxt1[i])
		{
			int y=to1[i];
			if(d[x]+edge[i]<d[y])
			{
				d[y]=d[x]+edge[i];
				p[y]=p[x]+1;
				if(p[y]>n)
				return 1;
				if(!v[y])
				{
					q.push(y);
					v[y]=1;
				}
			}
		}
	}
	
	return 0;
}

bool dfs(int x)
{
	if(x==n||f[x])
	return 1;
	
	for(int i=head[x];i;i=nxt[i])
	{
		int y=to[i];
		if(!v[i])
		{
			v[i]=1;
			if(dfs(y))
			{
				add1(x,y,9);
				add1(y,x,-1);
				f[x]=1;
			}
			
		}
		
		
	}
	return f[x];
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
		
	for(int i=1;i<=m;i++)	
	{
		cin>>x[i]>>y[i];	
			add(x[i],y[i]);
	}
	for(int i=1;i<=n;i++)
	add1(0,i,0);
	
	if(!dfs(1)||spfa())
	{
		cout<<-1;
		return 0;
	}
	cout<<n<<' '<< m<<endl;
	
	for(int i=1;i<=m;i++)
	{     
		cout<<x[i]<<' '<<y[i]<<' ';	
		int now=abs(d[x[i]]-d[y[i]]);
		if(now>0&&now<10)
		cout<<now<<endl;
		else
		cout<<1<<endl;
	}
	return 0;
}
