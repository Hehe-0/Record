#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=500007;

int m,k,n;

//int p[N],c[N];
struct node
{
	int id,val;
	bool flag;
	int nouse;
	bool operator < (const node &x) const 
	{
		if(val==x.val)
		return flag<x.flag;
		return val<x.val;
	}
	
}a[N<<1];
int ans;
//priority_queue<node >q;
bool vis[N<<1];
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k>>m;

	for(int i=1;i<=n;i++)
	{
		int q,w;
		cin>>q>>w;
		//q.push()	
		a[i]=(node){i,q,0,q};
		a[i+n]=(node){i,w,1,q};
	}
	sort(a+1,a+1+n*2);
	
	for(int i=1;i<=n*2;i++)
	{
		if(vis[a[i].id])
		continue;
		
		if(!a[i].flag&&m>=a[i].val)
		{
			ans++;
			m-=a[i].val;
			vis[a[i].id]=1;
		}
		else if(a[i].flag)
		{
			if(a[i].nouse==a[i+1].val&&m>=a[i].nouse)
			{
				ans++;
				m-=a[i].nouse;
				vis[a[i].id]=1;
			}
			else if(k&&m>=a[i].val)
			{
				ans++;
				k--;
				m-=a[i].val;
				vis[a[i].id]=1;
			}	
			
		}

	}
	
	
	cout<<ans;
	
	return 0;
}
