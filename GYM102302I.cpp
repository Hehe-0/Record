#include<bits/stdc++.h>

#define int long long
using namespace std;


int n;
struct node
{
	int x,y;
	bool operator < (node T) const
	{
		return x==T.x?y>T.y:x<T.x;
	}
	node operator - (node T) const
	{
		return {x-T.x,y-T.y};
	}
	int operator ^ (node T) const
	{
		return x*T.y - y*T.x;
	}
};

struct Hull : public multiset<node>
{
	bool inside(iterator p)
	{
		auto t2=next(p);
		if(t2==end())
		return 0;
		if(p==begin())
		return t2->x > p->x && t2->y > p->y;
		auto t1=prev(p);
		if(((*t1-*p)^(*t2-*p)) < 0)
		return 1;
		else
		return 0;
	}
	
	void ins(node p)
	{
		auto t=insert(p);
		if(inside(t))
		{
			erase(t);
			return ;
		}
		while(t!=begin() &&inside(prev(t)))
		erase(prev(t));
		while(next(t)!=end() &&inside(next(t)))
		erase(next(t));
	}
	
};


signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	 
	Hull hull; 
	 
	for(int i=1;i<=n;i++) 
	{
		int x,y;
		cin>>x>>y;
		node t={x,y};		
		hull.ins(t);
		
		cout<<i-hull.size()<<endl;
	}
	return 0;
}
