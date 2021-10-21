#include<bits/stdc++.h>

using namespace std;
const int N=1e7+7;
const int inf=1e9+7;

int n;
int a[N];
int buc[N];
int l[N],r[N];
int maxx,ans=inf;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	memset(l,0x3f,sizeof(l));
	fill(r,r+N+1,-inf);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		l[a[i]]=min(l[a[i]],i);
		r[a[i]]=max(r[a[i]],i);
		
		buc[a[i]]++;
	}
	for(int i=1;i<=N;i++)
	{
		maxx=max(maxx,buc[i]);
	}
	int pos;	
	for(int i=1;i<=N;i++)	
	{
		if(maxx==buc[i]&&ans>r[i]-l[i]+1)
		{
			ans=r[i]-l[i]+1;
			pos=i;
		}
		
	}
	
	
	cout<<l[pos]<<" "<<r[pos];
	return 0;
}
