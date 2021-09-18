#include<bits/stdc++.h>

#define pos ((k>>t)&1)
using namespace std;
const int N=6e5+7;

int n,m;
int a[N];
int root[N],p[N<<5];
int tree[N<<5][3];
int cnt=1;
string s;

void insert(int x,int y,int t,int k)
{
	if(t<0)
	return ;
	tree[x][!pos]=tree[y][!pos];
	tree[x][pos]=cnt++;
	
	p[tree[x][pos]]=p[tree[y][pos]]+1;
	insert(tree[x][pos],tree[y][pos],t-1,k);
	return ;
}

int query(int x,int y,int t,int k)
{
	if(t<0)
	return 0;
	
	if(p[tree[y][!pos]]>p[tree[x][!pos]])
	return (1<<t)+query(tree[x][!pos],tree[y][!pos],t-1,k);
	else
	return query(tree[x][pos],tree[y][pos],t-1,k);
	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	root[0]=cnt++;
	
	insert(root[0],0,25,0);
	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a[i]=a[i-1]^x;
		root[i]=cnt++;
		insert(root[i],root[i-1],25,a[i]);
	}
	
	for(int i=1;i<=m;i++)
	{
		
		cin>>s;
		if(s[0]=='A')
		{
			int x;
			cin>>x;
			n++;
			a[n]=a[n-1]^x;
			root[n]=cnt++;
			insert(root[n],root[n-1],25,a[n]);
		}
		else
		{
			int x,y,k;
			cin>>x>>y>>k;
			x--;
			y--;
			
			if(!x)
			cout<<query(0,root[y],25,k^a[n])<<endl;
			else
			cout<<query(root[x-1],root[y],25,k^a[n])<<endl;
		}
	}
	
	
	
	return 0;
}
