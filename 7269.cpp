/*#include<bits/stdc++.h>

using namespace std;
const int N=1e7+7;

int n,m;

stack<int >st;
//1 ->'('    2->')'   3->']'
int q[N],l,r;

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++)
	{
		char s;
		cin>>s;
		if(s=='(')
		{
			st.push(1);
		}
		else if(s==')')
		{
			if(st.empty())
			{
				if(r-l+1)
					q[l]--;
				else
				{
					cout<<0;
					return 0;					
					
				}

			}
			st.pop();
		}
		else if(s==']')
		{
			q[++r]=st.size();
			while(st.size())
			st.pop();
		}
	}
	if(l-r+1)
	{
		cout<<0;
		return 0;
	}
	else
	{
		while(l-r+1)
		{
			cout<<q[l]<<endl;
			l++;
		}
	}
	return 0;
}*/
