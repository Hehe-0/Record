#include<bits/stdc++.h>

using namespace std;

int n;
int a[114514];
int ans;

void dfs(int x,int k)
{
	if(x==n)
	{
		if(k==(1<<26)-1)
		ans++;
		return ;
	}
	dfs(x+1,k);
	dfs(x+1,(k|a[x]));
	return ;
}
string s;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		cin>>s;
		int m=s.size();
		for(int j=0;j<m;j++)
		a[i]|=(1<<(int)(s[j]-'a'));
	}
	dfs(0,0);
	
	cout<<ans<<endl;
	return 0;
}
