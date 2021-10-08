#include<bits/stdc++.h>

#define int long long
using namespace std;

int q;
int n;
int x;
int a[33]={1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401,22369621,1};

signed main()
{
	ios::sync_with_stdio(false);
	cin>>q;
	
	while(q--)
	{
		cin>>n;	
		x=n;
		if(n==3)
		{ 
			cout<<1<<endl;
			continue;
		}
		if(!(x&(x+1)))
		{
			int num=log2(n)-1;
			cout<<a[num]<<endl;
		}
		else
		{
			int num=0;
			while(x)
			{
				x>>=1;
				num++;
			}
			int f=1,p=1;
			for(int i=1;i<=num;i++)
			{
				f<<=1;
			}
			cout<<(f-1)<<endl;
		}
	}
	
	return 0;
}
