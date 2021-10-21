#include<bits/stdc++.h>

using namespace std;
const int N=1e5+7;

int n;

struct node
{
	int x,v;
};
/*
bool operator < (yyyy a,yyyy b)
{
	return a.x>b.x;	
}*/

bool cmp(node x,node y)
{
	return x.x<y.x;
}
int ans;
vector<node >a;
vector<node >b;


int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,v;
		cin>>x>>v;
		if(x>0)
		{
			a.push_back((node){x,v});			
		}
		else
		{
			b.push_back((node){-x,v});
		}
	}
	sort(a.begin(),a.end(),cmp);
    sort(b.begin(),b.end(),cmp);
	
	int siz=min(a.size(),b.size());
	int flag;
	
	if(a.size()>b.size()) 
	ans+=a[b.size()].v;
    else if(a.size()<b.size()) 
	ans+=b[a.size()].v;
//	while(itorator)
	for(int i=0;i<siz;i++)
	{
		ans+=a[i].v;
		ans+=b[i].v;
	}
	
	cout<<ans;
	
	return 0;
}
