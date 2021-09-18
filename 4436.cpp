#include<bits/stdc++.h>

using namespace std;
const int N=1e6+7;

int n,m,p;

struct node
{
	int s,l,r;	
	
}a[N];

void get()
{
	int L,R;
	
	for(int i=n;i>=1;i--)
	{
		L=R=i;
		
		while(1)
		{
			while(L>1&& (!a[L-1].s||(L<=a[L-1].s&&R>=a[L-1].s)) )
			L--;
			while(R<n&& (!a[R].s||(L<=a[R].s&&R>=a[R].s)))
			{
				R++;
				if(a[R].l)
				{
				L=min(L,a[R].l)	;
				R=a[R].r;	
				}
				
			}
			
			if(L==1||(a[L-1].s&&(L>a[L-1].s||R<a[L-1].s)))
			break;
		}
		a[i].l=L;
		a[i].r=R;
	}
	
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>p;
	
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		a[q].s=w;
	}
	get();
	
	for(int i=1;i<=p;i++)
	{
		int q,w;
		cin>>q>>w;
		if(q==w||(w<q&&a[q].l<=w)||(q<w&&a[q].r>=w))
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
	}
	
	return 0;
}
