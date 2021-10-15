#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;

int n,k;

int a[N<<1];
int siz[N*22];
int trie[N*22][3];

int cnt;
void add(int x)
{
	int pos=0;
	
	for(int i=21;i>=0;i--)
	{
		int nowx=((x>>i)&1);
		if(!trie[pos][nowx])
		{
			trie[pos][nowx]=++cnt;
		}
		
		pos=trie[pos][nowx];
		siz[pos]++;
	}
	
	return ;
}
/*
int query(int x)
{
	int re=0;
	
	for(int i=21;i>=0;i--)
	{
		int pos=0;
		int nowx=((x>>i)&1);
		int nowk=((k>>i)&1);
		if(nowk==1)
		{
			re+=siz[trie[pos][1-(nowx^nowk)]];
		}
		if(!trie[pos][nowx^nowk])
		break;
		
		pos=trie[pos][nowx^nowk];
	}
	
	return re;
}*/
int query(int x)
{
	int re=0;
	for(int i=21,p=0;i>=0;i--)
	{
		int c=(x>>i)&1;
		int t=(k>>i)&1;
		if(t==1)
		re+=siz[trie[p][1-(c^t)]];
		if(!trie[p][c^t])
		break;
		p=trie[p][c^t];
	}
	return re;
}


int ans;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		add(a[i]);
	}
	
	for(int i=0;i<(N<<1);i++)
	{
		ans=max(ans,query(i));
		if(ans==n)
		break;
	}
	
	cout<<ans;
	return 0;
}
