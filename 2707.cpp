#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+7;
//第i个景点收益：（ai-bi*x）*x 
//(ax-bx^2 )
// 1~n(x_i)<=k

int n,k;
//int a[N],b[N];
priority_queue< pair<int ,int > >q;
int ans;

signed main()
{
 	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		int x,y;	
		cin>>x>>y;
		if(x-y>0)
		q.push({x-y,y});
	}	
	
 	while((k--)&&(!q.empty()))
 	{
 		int x=q.top().first,y=q.top().second;
 		q.pop();
 		ans+=x;
 		x-=(y<<1);
 		if(x<=0)
 		continue;
 		else
 		q.push(make_pair(x,y) );
	 }
 	
 	 cout<<ans;
	return 0; 	
}
