#include<bits/stdc++.h>

using namespace std;
const int N=36;
const int mod=2017;

int base[N][N],num[N][N];
int n,m,ans;
int t;

void mul(int a[N][N],int b[N][N])
{//����˷� 
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
{//������ 
	while(t)
	{
		if(t&1)
			mul(num,base);
			
		mul(base,base);
		t>>=1;
	}
	//num�����������Ҫ�� 
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
		//����������п��Ե���ɿ����ӱ� 
		base[w][q]=1;
	}
	
	for(int i=0;i<=n;i++)
	{//ԭ�ز��� 
		base[i][i]=1;
		base[i][0]=1;
	//��ը���Կ���ǰ��һ������ȥ�ĳ���	
	}
	num[0][1]=1;
	//��ʼһ�ַ��� 
	cin>>t;
	qp();
	
	for(int i=0;i<=33;i++)
	{
		ans=(ans+num[0][i])%mod;
		//���һ��ͣ����ÿ�����еķ���������һ�º� 
	}
	cout<<ans%mod;
	return 0;
}
