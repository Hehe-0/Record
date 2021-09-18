#include<bits/stdc++.h>

using namespace std;

int m;
int root,tot;

struct node
{
	int ch[2];
	int fa,cnt,siz,v;
}a[1000001];

void upsiz(int x)
{
	a[x].siz= a[a[x].ch[0]].siz+ a[a[x].ch[1]].siz +a[x].cnt;
	return ;
}
void rotate(int x)
{
	int y=a[x].fa;
	int z=a[y].fa;
	int flag=( a[y].ch[1]== x ) ;
	a[z].ch[ a[z].ch[1]==y ]=x;
	a[x].fa= z;
	
	a[y].ch[flag] =a[x].ch[ flag^1 ];
	a[ a[x].ch[ flag^1 ]].fa = y; 
	
	a[x].ch[ flag^1 ]= y;
	a[y].fa = x;
	
	upsiz(y);
	upsiz(x);
	return ;
}

void splay(int x,int goal)
{
	while(a[x].fa !=goal)
	{
		int y=a[x].fa;
		int z=a[y].fa;
		if(z!=goal)
		(a[y].ch[0]==x) ^ (a[z].ch[0]==y)?rotate(x):rotate(y);
		rotate(x);
	}
	
	if(!goal)
	root=x;
	
	return ;
}

void insert(int val)
{
	int p=root,f=0;
	while(p&& a[p].v!=val)
	{
		f=p;
		p=a[p].ch[val > a[p].v] ;
	}
	if(p)
	    a[p].cnt++;
	else
	{
		tot++;
		p=tot;
		if(f)
		{
			a[f].ch[val >a[f].v ] =p;
		}
		a[p].ch[0]=a[p].ch[1] =0;
		a[p].siz=a[p].cnt=1;
		a[p].fa=f;
		a[p].v=val;
	}
	splay(p,0) ;

	return ;
}

void find(int val)
{
	int p=root;
	while(a[p].ch[val> a[p].v]&& val!=a[p].v)
		p=a[p].ch[val> a[p].v] ;
	
	splay(p,0);
	return ;	
}

int sea(int x,int flag)
{
	find(x);
	
	int p=root;
	if((a[p].v<x &&!flag)||(a[p].v>x&&flag) )
		return p;
	p=a[p].ch[flag];
	while(a[p].ch[ flag^1] )
	p=a[p].ch[flag^1] ;
	
	return p;
}

void del(int x)
{
	int pre=sea(x,0);
	int nxt=sea(x,1);
	splay(pre,0);
	splay(nxt,pre);
	
	int d=a[nxt].ch[0];
	if(a[d].cnt>1)
	{
		a[d].cnt--;
		splay(d,0);
	}
	else
	a[nxt].ch[0]=0;
	
	
	return ;
}

int rankth(int rank)
{
	int p=root;
	
	while(1)
	{
		int y=a[p].ch[0];
		if(rank>a[y].siz+a[p].cnt)
		{
			rank-=a[y].siz+a[p].cnt ;
			p=a[p].ch[1];
		}
		else if(a[y].siz >=rank)
			p=y;
		else
			break;
	}
	
	return a[p].v;
}



int main()
{
	ios::sync_with_stdio(false);
	insert(-2147483647);
	insert( 2147483647);
	cin>>m;
	splay(1,0);
	while(m--)
	{
		int o,x;
		cin>>o>>x;
		switch(o)
		{
       		case 1:cout<<rankth(x+1)    <<endl;								break;
            case 2:find(x);cout<<a[a[root].ch[0]].siz<<endl;				break;
            case 3:cout<<a[sea(x,0)].v  <<endl;								break;
			case 4:cout<<a[sea(x,1)].v  <<endl;								break;
            case 5:insert(x);												break;
           		

		}
		
	}
	
	return 0;
}
