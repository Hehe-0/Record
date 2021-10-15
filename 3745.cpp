#include<bits/stdc++.h>

#define lt (sumt[m]-sumt[q]-i*(m-q))
#define fr (i*q-sumt[q])
#define int unsigned long long
using namespace std;
const int N=1e5+7;

int n,m;
int A,B,C;
int num,maxx;
int t[N],b[N];
int minn=1e18;
int sumt[N],sumb[N];
int ans=1e18;

signed main()
{
	ios::sync_with_stdio(false);
	cin>>A>>B>>C;
	cin>>n>>m;
	/*if(A>B)
	{
		
		for(int i=1;i<=n;i++)
	{
		cin>>t[i];
	}
	sort(t+1,t+1+n);
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
		maxx=max(maxx,b[i]);
	}
	sort(b+1,b+1+n);
	
	for(int i=1;i<=maxx;i++)
	{
		int num=0;
		for(int j=1;j<=m;j++)
		{
			if(b[j]>i)
			{
				num+=(B*(b[j]-i));		
				
			}
		}	
		for(int j=1;j<=n;j ++)
		{
			if(t[j]<i)
			num+=((i-t[j])*C);
		}
		minn=min(minn,num);
	}
	cout<<minn;
	return 0;	
	}*/
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=1;i<=m;i++)
		cin>>t[i];
		
	sort(t+1,t+1+m);
	sort(b+1,b+1+n);	
	for(int i=1;i<=n;i++)
		sumb[i]=sumb[i-1]+b[i];	
	for(int i=1;i<=m;i++)
		sumt[i]=sumt[i-1]+t[i];

	int p=n,q=m;
	/*for(int i=t[m];i>=b[1];i--)
	{
		num=0;
		while(b[p]>=i)
		p--;
		while(b[q]>i)
		q--;
		
		num+=(i*p-sumb[p])*C;
		/*int frm=((sumt[m]-sumt[q]-i*(m-q)));
		int lat=(i*q-sumt[q]);
		
		
		if(A>=B)
		num+=frm*B;
		else
		{
			if(lat>frm)
				num+=lat*A;
			else
				num+=lat*A+(frm-lat)*B;
		}*/
	/*	int s1=sumt[m]-sumt[q]-i*(m-q);//后面需要的时间 
		int s2=i*q-sumt[q];//前面多余的时间 
		if (B<=A)num+=s1*B;
		else
			if (s2>s1)num+=s1*A;//全用A操作，用前面的补 
			else num+=s2*A+(s1-s2)*B;//能用A的用A，不能的用B 
		ans=min(ans,num);
	}*/
	
	for(int i=t[m];i>=b[1];i--)
	{
		num=0;
		while(b[p]>=i)
		p--;
		while(t[q]>i)
		q--;
		
		num+=(i*p-sumb[p])*C;
		 
		if (A>=B)
		num+=lt*B;
		else
		{
			if(fr>lt)
			num+=lt*A;
			else 
			num+=fr*A+(lt-fr)*B;
		}
			
		ans=min(ans,num);
	}
	cout<<ans;
	
	return 0;
}
