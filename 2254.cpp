#include<bits/stdc++.h>

using namespace std;
const int N=333;
const int M=2e9+7;
int dx[5]={-1,1,0,0};
int dy[5]={0,0,-1,1};

struct node
{	
	int len;
	int x,y;
}q[N];

int n,m,x,y,k,ans;
char mp[N][N];
int dp[N][N];

int dis(int xx,int yy,int xxx,int yyy)
{
	return abs(xx-xxx)+abs(yy-yyy);
}

void solve(int x,int y,int len,int f)
{
	int l=1,r=0;
	f--;
	
	while(1)
	{
		if(x<1||y<1||x>n||y>m)
		break;
		if(mp[x][y]=='x')
		l=1,r=0;
		else
		{
			while(l<=r&&dp[x][y]>q[r].len+dis(x,y,q[r].x,q[r].y))
			r--;
			q[++r]=(node){dp[x][y],x,y};
			while(l<=r&&(abs(x-q[l].x)>len||abs(y-q[l].y)>len))
			l++;
			dp[x][y]=max(dp[x][y],q[l].len+dis(x,y,q[l].x,q[l].y));
			
			ans=max(ans,dp[x][y]);
		}
		x+=dx[f];
		y+=dy[f];
	}
	
	
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m>>x>>y>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>mp[i]+1;
	}
	
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		dp[i][j]=-M;
	}
	dp[x][y]=0;
	
	for(int i=1;i<=k;i++)
	{
		int S,L,R,D;
		cin>>S>>R>>D;
		L=R-S+1;
		if(D==1)
		{
			for(int j=1;j<=m;j++)
			solve(n,j,L,D);
		}
		else if(D==2)
		{
			for(int j=1;j<=m;j++)
			solve(1,j,L,D);			
		}
		else if(D==3)
		{
			for(int j=1;j<=n;j++)
			solve(j,m,L,D);
		}
		else if(D==4)
		{
			for(int j=1;j<=n;j++)
			solve(j,1,L,D);			
		}
	}
	
	cout<<ans;
	return 0;
}
