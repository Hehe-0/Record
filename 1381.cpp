#include<bits/stdc++.h>

using namespace std;
const int base=2333;
const int mod=114514;
const int N=1e5+7;

int n,m;
int a[N],b[N];
int flag[N<<5],p[N<<5];
int vis[N<<5];
int ans=2147483647;

int cnt;
int geth(char c[])
{
	int re=0,len=strlen(c);
	for(int i=0;i<len;i++)
	{
		re=(re*base+c[i])%mod;
	}
	return re;
}

char s[N];
int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		a[i]=geth(s);
		p[a[i]]=1;
	}
	cin>>m;
	
	for(int i=1;i<=m;i++)
	{
		cin>>s;
		b[i]=geth(s);
		if(p[b[i]]&&!vis[b[i]])
		{
			vis[b[i]]=1;
			cnt++;
		}
	}
	if(!cnt)
	{
		cout<<0<<endl<<0;
		return 0;
	}
	else
	cout<<cnt<<endl;
	int l=m,r=m;
	
	while(1)
	{
		if(!cnt)
		{
			while(!vis[b[r]])		
				r--;
			ans=min(ans,r-l);
			
			if(flag[b[r]]>=1)
			{
				if(flag[b[r]]==1)
				{
					cnt++;
				}
				flag[b[r]]--;
				r--;
			}
				
		}
		else
		{
			if(!l)
			break;
			if(vis[b[l]])
			{
				if(!flag[b[l]])
				{
					cnt--;
				}
				flag[b[l]]++;
			}
			
			l--;
		}
	}
	
	cout<<ans;
	
	return 0;
}
