#include<bits/stdc++.h>

using namespace std;
const int N=4e4+7;
const int M=211;

int n,m,re;
int T;
int dat[N];
int sum[M][N],ans[M][N];
int block[N],belong[N];
struct node
{
	int id;
	int w,x;
}a[N];

bool cmp(node x, node y)
{
	return x.w<y.w;
}
bool cmpp(node x,node y)
{
	return x.id<y.id;
}

int cnt;
void find(int L,int R)
{
	int l=L/T+1,r=R/T-1;
	
	if(r-l<=1)
	{
		re=0;
		for(int i=L;i<=R;i++)
		{
			if((++block[a[i].x]>block[re])||(block[a[i].x]==block[re]&&a[i].x<re))
			re=a[i].x;			
		}
		for(int i=L;i<=R;i++)
		block[a[i].x]--;
		
		cout<<dat[re]<<endl;
		return ;
	}
	else
	{
		int mil=l*T-1,mir=(r+1)*T;
		re=ans[l][r];
		
		for(int i=L;i<=mil;i++)
		{
			block[a[i].x]++;
			if(block[a[i].x]+sum[r][a[i].x]-sum[l-1][a[i].x]>block[re]+sum[r][re]-sum[l-1][re])
			re=a[i].x;
			else if(block[a[i].x]+sum[r][a[i].x]-sum[l-1][a[i].x]==block[re]+sum[r][re]-sum[l-1][re]&&a[i].x<re)
			re=a[i].x;
		}
		
		for(int i=mir;i<=R;i++)
		{
			block[a[i].x]++;
			if(block[a[i].x]+sum[r][a[i].x]-sum[l-1][a[i].x]>block[re]+sum[r][re]-sum[l-1][re])
			re=a[i].x;
			else if(block[a[i].x]+sum[r][a[i].x]-sum[l-1][a[i].x]==block[re]+sum[r][re]-sum[l-1][re]&&a[i].x<re)
			re=a[i].x;
		}
		
		for(int i=L;i<=mil;i++)
		block[a[i].x]--;
		for(int i=mir;i<=R;i++)
		block[a[i].x]--;
		
		return ;
	}

	return ;
}

void search(int x,int y)
{
//	printf("%d %d\n",x,y);
    int l=x/T + 1,r=y/T - 1;//取出中间块
    if(r - l <= 1)//如果x,y相差很小,那么暴力统计
    {
        re=0;
        for(int i=x;i<=y;i++)
            if((++block[b[i].x] > block[answer]) || (block[b[i].x] == block[answer] && b[i].x < answer)) answer=b[i].x;
        for(int i=x;i<=y;i++)
            --block[b[i].x];
        printf("%d\n",s[answer]);
        return ;
    }
    else//不然的话
    {
        int ll=l * block - 1,rr=(r+1) * block;
        answer=ans[l][r];
        for(R i=x;i<=ll;i++)
        {
            ++block[b[i].x];
            if(block[b[i].x] + sum[r][b[i].x] - sum[l-1][b[i].x] > block[answer] + sum[r][answer] - sum[l-1][answer]) answer=b[i].x;
            else if(block[b[i].x] + sum[r][b[i].x] - sum[l-1][b[i].x] == block[answer] + sum[r][answer] - sum[l-1][answer] && b[i].x < answer) answer=b[i].x;//编号小也要优先，因为一行写不下，为了美观，，，就用else吧，不然就用||了
        }
        for(R i=rr;i<=y;i++)
        {
            ++block[b[i].x];
            if(block[b[i].x] + sum[r][b[i].x] - sum[l-1][b[i].x] > block[answer] + sum[r][answer] - sum[l-1][answer]) answer=b[i].x;
            else if(block[b[i].x] + sum[r][b[i].x] - sum[l-1][b[i].x] == block[answer] + sum[r][answer] - sum[l-1][answer] && b[i].x < answer) answer=b[i].x;
        }
        for(R i=x;i<=ll;i++) --block[b[i].x];
        for(R i=rr;i<=y;i++) --block[b[i].x];
        printf("%d\n",s[answer]);
        return ;
    }
}

void init()
{
	/*for(int i=1;i<=n;i++)
	{
		belong[i]=i/T;	
		sum[belong[i]][a[i].x]++;
	}
	for(int i=0;i<=belong[n];i++)
	{
		for(int j=1;j<=cnt;j++)
		sum[i][j]+=sum[i-1][j];
	}*/
	    for(int i=1;i<=n;i++)
    {
        belong[i]=i/T;
        sum[belong[i]][a[i].x]++;
    }
    for(int i=0;i<=belong[n];i++)
        for(int j=1;j<=cnt;j++)
            sum[i][j]+=sum[i-1][j];
	return ;
}


int main()
{
	ios::sync_with_stdio(false);
	cin>>n>>m;
	T=sqrt(n);
	
	for(int i=1;i<=n;i++)	
	{
		cin>>a[i].w;
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		if(a[i].w!=a[i-1].w)
		{
			dat[++cnt]=a[i].w;
			a[i].x=cnt;
		}
		else
		{
			a[i].x=a[i-1].x;
		}
	}
	sort(a+1,a+1+n,cmpp);
	init();
	
/*	for(int i=0;i<=belong[n];i++)
	{
		int num=i*T,now=0;
		if(!num)
		num=1;
		
		for(int j=num;j<=n;j++)
		{
			if((++block[a[j].x]>block[now])||(block[a[j].x]==block[now]&&a[j].x<now))
			now=a[j].x;
			
			ans[i][belong[j]]=now;
		}
		for(int j=num;j<=n;j++)
		block[a[j].x]--;
	}*/
	    for(int i=0;i<=belong[n];i++)
    {
        int be=i * T,now=0;
        if(!be) be=1;//这里和作诗不同，因为这里的now要参与比较了，而不是单纯的统计，而now初始值为0，所以color[0]不能被修改
        for(int  j=be;j<=n;j++)
        {
            if((++block[a[j].x] > block[now]) || (block[a[j].x] == block[now] && a[j].x < now)) now=a[j].x;//更新ans
            ans[i][belong[j]]=now;
        }
        for(int j=be;j<=n;j++) --block[a[j].x];//暴力撤销
    }
	
	for(int i=1;i<=m;i++)
    {
    	int x,y,A,B;
    	cin>>x>>y;
        A=(x+dat[re]-1)%n+1,B=(y+dat[re]-1)%n+1;
        if(!(A<B))
		swap(A,B);
		find(A,B);
    }	
		
	
	return 0;
}
