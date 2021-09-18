#include<bits/stdc++.h>

using namespace std;
const int N=7e7+7;
               
int n,m,l,u,v,t;

int a[N],p1[N],p2[N];
priority_queue<int > q;
double p;
int pos,sum;
int had,had1,had2;
int til,til1,til2;

bool cmp(int x,int y)
{
	return x>y;
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>l>>u>>v>>t;
	p=(double)u/v;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n,cmp);
	til=n;
	had=had1=had2=1;
	
	for(int i=1;i<=m;i++)
	{
		if(had>til)
		{
			if(p1[had1]>p2[had2])
			pos=p1[had1++];	
			else
			pos=p2[had2++];
		}
		else if(a[had]>=p1[had1]&&a[had]>=p2[had2])
		{
			pos=a[had];
			had++;
		}
		else if(p1[had1]>=p2[had2]&&a[had]<=p1[had1])
		{
			pos=p1[had1];
			had1++;
		}
		else
		{
			pos=p2[had2];
			had2++;
		}
		pos+=sum;
		int f1=floor(p*(double)pos),f2=pos-f1;
		sum+=l;
		f1-=sum;
		f2-=sum;
		p1[++til1]=f1;
		p2[++til2]=f2;
		
		if(!(i%t))
		cout<<pos<<' ';
	}
	cout<<endl;
	
	for(int i=had;i<=til;i++)
	q.push(a[i]);
	for(int i=had1;i<=til1;i++)
	q.push(p1[i]);
	for(int i=had2;i<=til2;i++)
	q.push(p2[i]);
	
	for(int i=1;!q.empty();i++)
	{
		if(!(i%t))
		cout<<q.top()+sum<<' ';
		
		q.pop();
	}
	
	return 0;
}
