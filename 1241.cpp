#include<bits/stdc++.h>

using namespace std;
const int mod=998244353;

int n;
int h[1001];
string a;
stack<int >s;
char ans[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin>>a;
	int l=a.size();
	
	for(int i=0;i<l;i++)
	{
		if(a[i]=='(')
		{
			s.push(i);
			ans[i]=')';
		}
		if(a[i]=='[')
		{
			s.push(i);
			ans[i]=']';
		}		
		if(a[i]==')'||a[i]==']')
		{
			if(s.empty()||ans[s.top()]!=a[i])
			{
				if(a[i]==')')
				ans[i]='(';
				else
				ans[i]='[';
			}
			else
			{
				ans[s.top()]=' ';
				s.pop();
			}
		}
		
	}
	for (int i=0;i<l;i++)
    {
        if (ans[i]=='(' ||ans[i]=='[')
            cout<<ans[i];
        cout<<a[i];
        if (ans[i]==')'||ans[i]==']') 
		    cout<<ans[i];
    }
	
	
	return 0;
 } 
