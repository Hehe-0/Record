#include<bits/stdc++.h>

using namespace std;
const int N=888;

int n,m,k,l;
int a[N][N],ans[N][N];

int p[N],q[N],f[N];
int num;
int x,T=1;
bool cmp(int g,int h)
{
	return a[g][x]>a[h][x];
}
bool cmpp(int g,int h)
{
	return a[g][x]<a[h][x];
}

int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>k>>l;
	
	for(int i=1;i<=n;i++)
	{
		string s;
		cin>>s;
		for(int j=1;j<=m;j++)
		{
			a[i][j]=s[j-1]-'0';
			
			
		}
			
	}
	
	for(int j=m;j;j--)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i][j])
				a[i][j]=a[i][j+1]+1;
		}
	}
	
	/*for(int j=1;j<=m;j++)
	{
		x=j;
		num=0;
		for(int i=1;i<=n;i++)
		{
			if(f[i]!=T&&a[i][j])
			p[++num]=i;
		}
	
		sort(p,p+1+num,cmp);
		T++;
		
		if(j==1)
		{
			if(num<l)
			{
				cout<<"-1"<<endl;
				return 0;	
			}
		}
		else
		{
			sort(q+1,q+1+k,cmpp);
			num=min(l,num);
			
			for(int i=1;i<=num;i++)
			{
				if(a[p[i]][j]>a[q[i]][j])
				swap(p[i],q[i]);
			}
			if(num<=k&&!a[q[num]][j])
			{
				cout<<"-1"<<endl;
				
				return 0;
			}
			
			swap(p,q);
		}
		
		for(int i=1;i<=k;i++)
		{
			ans[j][i]=p[i];
			f[p[i]]=T;
		}
		
		swap(p,q);
	}*/
	
    for (int j=1;j<=m;j++)
	{
        x=j,p[0]=0;
        for (int i=1;i<=n;i++)
            if (f[i]!=T&&a[i][j]) p[++p[0]]=i;
            
        sort(p+1,p+p[0]+1,cmp),T++;
        if (j==1)
		{ 
		if (p[0]<l) 
			{
				cout<<"-1"<<endl;
				
				return 0;
			}
		}
        		else
		{
			sort(q+1,q+1+k,cmpp);
			int minn=min(l,p[0]);
			
			for(int i=1;i<=minn;i++)
			{
				if(a[p[i]][j]>a[q[i]][j])
				swap(p[i],q[i]);
			}
			if(minn<=k&&!a[q[minn]][j])
			{
				cout<<"-1"<<endl;
				
				return 0;
			}
			
			swap(p,q);
		}
        
       	for(int i=1;i<=k;i++)
		{
			ans[j][i]=p[i];
			f[p[i]]=T;
		}
		
		swap(p,q);
    }
	
	
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=k;i++)
		cout<<ans[j][i]<<' ';
		cout<<endl;
	}
	
	return 0;
}
