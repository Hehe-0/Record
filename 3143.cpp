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

//̰�Ĳ���֤��,�����������϶��ǽ����ŵ� (�����������(���� 

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
	//��һ�������ܷż��� 
	for(int i=2;i<=n;i++)
	{
		//ÿ�γ���,��˵����nowΪ��˵�Ĺ��ܷ��� 
		while(a[i]-a[now]>k)
		now++;//ö����˵� 
		l[i]=max(l[i-1],i-now+1);
	}
	now=n;
	//�ڶ������� 
	for(int i=n-1;i>=1;i--)
	{
		//ͬ��,������ ,���Ҷ˵� 
		while(a[now]-a[i]>k)
		now--;
		
		r[i]=max(r[i+1],now-i+1);
	}
	for(int i=1;i<n;i++)
	{
		ans=max(ans,l[i]+r[i+1]);
	}//�Ҷ˵���������,��˵����� 
	//������ƴ������ 
	cout<<ans;
	return 0;
}
