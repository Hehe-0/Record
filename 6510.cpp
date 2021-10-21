#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=1e5+7;

//stack<int >s;

int n;
int m;
int ans;
int a[N];
int s1[N],s2[N];
int top1,top2;
/*
void cl()
{
	while(s.size())
	s.pop();
	return ;
}*/

signed main()
{
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=1;i<=n;i++)    
	    cin>>a[i];
	/*for(int i=1;i<n;i++)    
    {
    	int x;
    	cin>>x;
    	if(x>(int)s.top())
    	{
    		s.push(x);
		}
		else
		{
			maxx=max(maxx,(int)s.size());
			cl();
		}
	}*/
    for(int i=1;i<=n;i++)
    {
    	while(top1&&a[s1[top1]]>=a[i])
    	top1--;
    	while(top2&&a[s2[top2]]<a[i])
		top2--;
		
		int pos=upper_bound(s1+1,s1+1+top1,s2[top2])-s1;
		if(pos!=(top1+1))
		{
			if(ans<i-s1[pos]+1) 
			ans=i-s1[pos]+1;
		}
		s1[++top1]=i;
		s2[++top2]=i;
		
	}
    
    cout<<ans;
    
	return 0;
}
