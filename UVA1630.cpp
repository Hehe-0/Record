/*#include<bits/stdc++.h>

using namespace std;
const int N=111;

int n;
int dp[N][N];
//dp[l][r]  -> l到r的折叠最短长度
// dp[l][r] ->min k*  l,mid  mid+1,r
//dp[l][r]  -> 一个字符串能被拼出折叠的形式
//那么他的长度也可以被长度至少大于等于1的字符串拼出 
 
int leng[N]; 
char a[N];


void pd(int x,int y,int len)
{
	if((y-x+1)%len)
	return ;

	for(int i=x;i<=y;i++)
	{
		if(a[i]!=a[(i-x)%len+x])
		return ;
		
	}
	dp[x][y]=min(dp[x][y],dp[x][x+len-1]+2+leng[(y-x+1)/len]); 
	return ;
}
int ans=2147483647;

int main ()
{
	ios::sync_with_stdio(false);
	while(cin>>a+1)
	{
			int n=strlen(a+1);
		memset(dp,0x3f,sizeof(dp));
		for(int i=1;i<=n;i++)
		{
			dp[i][i]=1;
		}
		for(int i=1;i<100;i++)
		{
			if(i>=10)
			leng[i]=2;
			else
			leng[i]=1;
		}
		leng[100]=3;
		
		for(int l=1;l<=n;l++) 
		{
			for(int i=1,j=i+l;j<=n;j++,i++)
			{
				
				
				for(int k=i;k<j;k++)
				{
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
				}
					for(int len=1;len<=j-i;len++)
					{
						pd(i,j,len);
						
									
					}	
				
			}
		}
		cout<<dp[1][n]<<endl;	
		memset(dp,0,sizeof(dp));
		memset(leng,0,sizeof(leng));
		
	}
	

	
	return 0;
}*/
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 125;
int numlen[N],f[N][N],n;
bool st[N][N];
string s,res[N][N];

bool check(int l,int r,int m)
{
	for(int i = l;i < l + m;++i)
	{
		for(int j = i;j <= r;j += m)
		{
			if(s[j] != s[i])
				return 0;
		}
	}
	return 1;
}
inline void _ct(int l,int r)
{
	for(int i = l;i <= r;++i)
		res[l][r] += s[i];
}

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	while(cin >> s)
	{
		n = s.size();s = "#" + s;
		for(int i = 1;i <= 9;++i)	numlen[i] = 1;
		for(int i = 10;i <= 100;++i)	numlen[i] = 2;
		
		for(int len = 1;len <= n;++len)
		{
			for(int l = 1;l + len - 1 <= n;++l)
			{
				int r = l + len - 1;
				f[l][r] = len;res[l][r] = s.substr(l,len);
				for(int k = l;k < r;++k)	
				{
					if(f[l][r] > f[l][k] + f[k + 1][r])
					{
						f[l][r] = f[l][k] + f[k + 1][r];
						res[l][r] = res[l][k] + res[k + 1][r];
					}
					
				}
				for(int m = 1;m < len;++m)
				{
					if(len % m)	
					continue;
					if(check(l,r,m))	
					{
						
						if(f[l][r] > f[l][l + m - 1] + numlen[len / m] + 2)
						{
							f[l][r] = f[l][l + m - 1] + numlen[len / m] + 2;
							res[l][r] = to_string(len / m) + 
							"(" + res[l][l + m - 1] + ")";
						}
					}
						
				}
			}
		}
		cout << res[1][n] << endl;
	}

    return 0;
}
