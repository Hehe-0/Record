#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+7;

int n,k;
int a[N];
int l[N],r[N];
//int max1,min1,max2,min2;
//int minn=1e9+7,maxx;
int ans;

//贪心不难证明,最后两个区间肯定是紧挨着的 (是在排序过后(升序 

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	//	minn=min(minn,a[i]);
	//	maxx=max(maxx,a[i]);
	}
	sort(a+1,a+1+n);

	l[1]=r[n]=1;
	int now=1;
	//第一个柜子能放几个 
	for(int i=2;i<=n;i++)
	{
		//每次超了,就说明以now为左端点的柜不能放了 
		while(a[i]-a[now]>k)
		now++;//枚举左端点 
		l[i]=max(l[i-1],i-now+1);
	}
	now=n;
	//第二个柜子 
	for(int i=n-1;i>=1;i--)
	{
		//同理,倒着来 ,挑右端点 
		while(a[now]-a[i]>k)
		now--;
		
		r[i]=max(r[i+1],now-i+1);
	}
	for(int i=1;i<n;i++)
	{
		ans=max(ans,l[i]+r[i+1]);
	}//右端点向左衍生,左端点向右 
	//这样就拼出来了 
	cout<<ans;
	return 0;
}
