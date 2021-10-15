#include<bits/stdc++.h>

using namespace std;

int t,n;
unordered_map<int ,bool>s;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>t;
	
	while(t--)
	{
		s.clear();
		cin>>n;
		
		for(register int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			
			if(!s[x])
			{
				cout<<x<<' ';
				s[x]=1;
			}		
		
		}
		cout<<endl;
	}
	
	
	return 0;
	
}
