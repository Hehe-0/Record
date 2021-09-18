#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+7;

map<int ,int >m;

int n;
int a[N<<1];
int da[N];
int cnt,num;

int lowbit(int x)
{
	return x&-x;
}

void add(int x)
{
	for(int i=x;i<=n;i+=lowbit(i))
		a[i]++;
	
	return ;
}

int query(int x)
{
	int re=0;
	
	for(int i=x;i;i-=lowbit(i))
	re+=a[i];
	
	return re;
}


signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		cin>>da[i];	
		add(da[i]);
		cnt+=(i-query(da[i]));
		m[da[i]]=i;
		//
	}
	num=cnt;
	
	for(int i=n;i>=1;i--)
	{
		cnt=cnt+(m[i]-1)-n+m[i];
		num=min(num,cnt);
	}
	
	
	cout<<num;
	return 0;
}
