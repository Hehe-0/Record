#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;

struct node
{
	int pos,col;
}a[N];
int n,m;
int cnt,sum,ans=(N<<10);
int t[N>>5];

queue<node >q;
bool cmp(node x,node y)
{
	return x.pos<y.pos;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)	
	{
		int k;
		cin>>k;
		
		for(int j=1;j<=k;j++)
		{
			int x;
			cin>>x;
			a[++cnt].pos=x;
			a[cnt].col=i;
		}
	}
	sort(a+1,a+1+n,cmp);
	
	for(int i=1;i<=n;i++)
	{
		q.push(a[i]);
		t[a[i].col]++;
		if(t[a[i].col]==1)
		sum++;
		
		while(sum==m)
		{
			node st=q.front(),ed=q.back();
			if(ans>ed.pos-st.pos)
			ans=ed.pos-st.pos;
			q.pop();
			
			t[st.col]--;
			if(!t[st.col])
			sum--;
		}
		
	}
	
	cout<<ans;
	return 0;
}
