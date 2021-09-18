#include<bits/stdc++.h>

using namespace std;

vector<int >a;
int n;


int main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=1;i<=n;i++)
	{
		int q;
		cin>>q;
		a.insert(upper_bound(a.begin(),a.end(),q),q);
		
		if(i&1)
		cout<<a[(i-1)/2]<<endl;
	}
	
	
	
	return 0;
}
