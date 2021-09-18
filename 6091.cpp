#include <bits/stdc++.h>

using namespace std;
const int N=1e6+2;
typedef long long ll;


int ss[N],mn[N],fmn[N],phi[N];
int t,n,gs,i,d;
bool ed[N],av[N],yg[N];

void getfac(int x,int *a,int &n)
{
	register int y=x,z;
	while(x>1)
	{
		x/=(a[++n]=z=mn[x]);
		while (x%z==0) x/=z;
	}
	
	for(i=1;i<=n;i++) 
	av[a[i]]=0,a[i]=y/a[i];
	
	return ;
}
int ksm(register int x,register int y,register int p)
{
	register int r=1;
	while (y)
	{
		if (y&1) r=(ll)r*x%p;
		x=(ll)x*x%p;y>>=1;
	}
	return r;
}

bool ck(int x,int *a,int n,int p)
{
	for (int i=1;i<=n;i++) if (ksm(x,a[i],p)==1) return 0;
	return 1;
}

void getrt(int x,int d)
{
	static int a[100],b[N];
	
	int n=0,y,i,g=0,c=d;y=phi[x];
	fill(av+1,av+y+1,1);
	
	getfac(y,a,n);
	for (i=1;i<x;i++) if (__gcd(i,x)==1&&ck(i,a,n,x)) break;
	if (i==x) return puts("0\n"),void();
	yg[g=i]=1;
	
	int j=(ll)g*g%x;
	for (i=2;i<=y;i++) av[i]=av[mn[i]]&av[fmn[i]];
	for (i=2;i<y;i++,j=(ll)j*g%x) if (av[i]) yg[j]=1;
	printf("%d\n",g?phi[y]:0);
	for (i=1;i<x;i++) if (yg[i]) 
	{
		yg[i]=0;
		if (--c==0) printf("%d ",i),c=d;
	}
	puts("");
	return ;
}
void init()
{
	register int i,j,k,n=N-1;
	mn[1]=phi[1]=1;
	for (i=2;i<=n;i++)
	{
		if (!ed[i]) phi[mn[i]=ss[++gs]=i]=i-1;
		for (j=1;j<=gs&&(k=ss[j]*i)<=n;j++)
		{
			ed[k]=1;mn[k]=ss[j];
			if (i%ss[j]==0) {phi[k]=phi[i]*ss[j];break;}
			phi[k]=phi[i]*(ss[j]-1);
		}
	}
	for (i=1;i<=n;i++) 
	fmn[i]=i/mn[i];
	
	return ;
}
int main()
{
	
	init();
	scanf("%d",&t);
	while (t--)
	{
		scanf("%d%d",&n,&d);
		getrt(n,d);
	}
	
	return 0;
}
