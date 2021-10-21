#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=2e5+7;

int w,h,n;

multiset<int >a,b;
multiset<int >xx,yy;
multiset<int >::iterator p;

signed main()
{
	ios::sync_with_stdio(false);	
	cin>>w>>h>>n;
	xx.insert(w);
	yy.insert(h);
	a.insert(0);
	b.insert(0);
	a.insert(w);
	b.insert(h);
	
	for(int i=1;i<=n;i++)
	{
		char c;
		int x;
		cin>>c>>x;
		if(c=='H')
		{
			b.insert(x);
			p=b.find(x);
			p--;
			int l=*p;
			p++;
			p++;
			int r=*p;
			p=yy.find(r-l);
			yy.erase(p);
			yy.insert(r-x);
			yy.insert(x-l);
		}
		else if(c=='V')
		{
			a.insert(x);
			p=a.find(x);
			p--;
			int l=*p;
			p++;
			p++;
			int r=*p;
			p=xx.find(r-l);
			xx.erase(p);
			xx.insert(r-x);
			xx.insert(x-l);
			
		}
		p=xx.end();
		p--;
		int l=*p;
		p=yy.end();
		p--;
		int r=*p;
		
		cout<<l*r<<endl;
	}
	
	
	return 0;
} 
