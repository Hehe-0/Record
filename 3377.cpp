#include<bits/stdc++.h>

using namespace std;
#define ls a[x].ch[0]
#define rs a[x].ch[1]

int n,m;
struct node
{
	int v;
	int f,dist,ch[3];
}a[10101];
//1552
int uni(int x,int y)
{
	if(!x||!y)
	return x^y;
	if(a[x].v>a[y].v)
	swap(x,y);
	rs=uni(rs,y);
	a[rs].f=x;
	if(a[ls].dist<a[rs].dist)
	swap(ls,rs);
	a[x].dist=a[rs].dist+1;
	
	return x;
}
int find(int k)
{
	if(a[k].f==k)
	return k;
	return a[k].f=find(a[k].f);
}

void delet(int x)
{
	a[x].f=a[ls].f=a[rs].f=uni(ls,rs);
	a[x].dist=a[x].v=-1;
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].v;
		a[i].f=i;
	}
	
	while(m--)
	{
		int flag,x,y;
		cin>>flag;
		if(flag==1)
		{
			cin>>x>>y;
			if(a[x].v==-1||a[y].v==-1)
			continue;
			int f1=find(x),f2=find(y);
			
			a[f1].f=a[f2].f=uni(f1,f2);
		}
		else
		{
			cin>>x;
			if(a[x].v==-1)
			cout<<"-1"<<endl;
			else
			{
			cout<<a[find(x)].v<<endl;
			delet(find(x));
			}
			
		}
	}
	
	
	
	return 0; 
}
