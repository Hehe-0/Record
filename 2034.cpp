#include<bits/stdc++.h>

#define int long long 
using namespace std;
const int N=1e5+7;

int n,k;
// ǰi��������ɾ��i���ܵõ������ֵ ���� 
//��ǰi��������ɾ�������ĺ͵���Сֵ���� 
int dp[N];
int head,tail;
int sum,maxx;
struct node
{
	int f,id;
}q[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>k;	
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		dp[i]=q[head].f+x;
		sum+=x;
		while(head<=tail&&q[tail].f>=dp[i])
		tail--;
		q[++tail].f=dp[i];
		q[tail].id=i;
		
		while(head<=tail&&q[head].id<i-k)
		head++;
	}
	for(int i=n-k;i<=n;i++)
	maxx=max(maxx,sum-dp[i]);
	
	cout<<maxx;
	return 0;
}
