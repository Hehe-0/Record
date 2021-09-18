#include<bits/stdc++.h>

using namespace std;
const int N=36;
const int mod=2017;

int base[N][N],num[N][N];
int n,m,ans;
int t;

void mul(int a[N][N],int b[N][N])
{//矩阵乘法 
	int re[N][N]={};
	
	for(int i=0;i<=33;i++)
	{
		for(int j=0;j<=33;j++)
		{
			for(int k=0;k<=33;k++)
			re[i][j]=(re[i][j]+a[i][k]*b[k][j]%mod)%mod;
			
		}
		
	}
	memcpy(a,re,sizeof(re));
	return ;
}

void qp()
{//快速幂 
	while(t)
	{
		if(t&1)
			mul(num,base);
			
		mul(base,base);
		t>>=1;
	}
	//num是最后我们想要的 
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	
	for(int i=1;i<=m;i++)
	{
		int q,w;
		cin>>q>>w;
		base[q][w]=1;
		//这样代表城市可以到达（可看作加边 
		base[w][q]=1;
	}
	
	for(int i=0;i<=n;i++)
	{//原地不动 
		base[i][i]=1;
		base[i][0]=1;
	//爆炸可以看作前往一个出不去的城市	
	}
	num[0][1]=1;
	//初始一种方案 
	cin>>t;
	qp();
	
	for(int i=0;i<=33;i++)
	{
		ans=(ans+num[0][i])%mod;
		//最后看一看停留在每个城市的方案数，求一下和 
	}
	cout<<ans%mod;
	return 0;
}
