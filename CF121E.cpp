#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n,m;
int a[N];
int l,r,w;
int tree[N<<2];
bool flag[N];

int lowbit(int x)
{
	return x&(-x);
}
void add(int x,int k)
{
	for(int i=x;i<=n;i+=lowbit(i))
		tree[i]+=k;
	
	return ;
}

int query(int x)
{
	int re=0;
	for(int i=x;i;i-=lowbit(i))
		re+=tree[i];
		
	return re;
}

string op;
int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	flag[4]=1;flag[7]=1;
	flag[44]=1;flag[47]=1;flag[74]=1;flag[77]=1;
	flag[444]=1;flag[447]=1;
	flag[474]=1;flag[477]=1;flag[744]=1;flag[747]=1;flag[774]=1;
	flag[777]=1;
	flag[4444]=1;
	flag[4447]=1;flag[4474]=1;flag[4477]=1;flag[4744]=1;flag[4747]=1;flag[4774]=1;
	flag[4777]=1;flag[7444]=1;flag[7447]=1;flag[7477]=1;flag[7474]=1;flag[7744]=1;flag[7747]=1;
	flag[7774]=1;flag[7777]=1;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(flag[a[i]])
		add(i,1);
	}
	
	while(m--)
	{
		cin>>op;
		if(op[0]=='c')
		{
			cin>>l>>r;
			cout<<query(r)-query(l-1)<<endl;
		}
		else
		{
			cin>>l>>r>>w;
			for(int p=l;p<=r;p++)
			{
				if(flag[a[p]])
				add(p,-1);
				a[p]+=w;
				
				if(flag[a[p]])
				add(p,1);
			}
		}
		
	}
	
	
	return 0;
 } 
