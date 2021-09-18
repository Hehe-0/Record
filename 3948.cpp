#include<bits/stdc++.h>

using namespace std;

int n,m,k,x,y,z,maxn,minn,mod,fin,ans,tot;
char _s;
long long a[80039],q[80039];

int main()
{
	register int i,j;
	scanf("%d%d%d%d%d",&n,&m,&mod,&minn,&maxn);
	for(i=1;i<=m;i++){
		_s=getchar();
		while(_s<'A'||_s>'Z') _s=getchar();
		if(_s=='A'){
			scanf("%d%d%d",&x,&y,&z);
			q[x]+=z;q[y+1]-=z;
		}
		else{
			scanf("%d%d",&x,&y);
				tot=0;
			for(j=1;j<=y;j++) {
				a[j]=a[j-1]+q[j];
				ans=a[j]*j%mod;
				
				if(ans>=minn&&ans<=maxn&&j>=x) tot++;
			}
			printf("%d\n",tot);
		}
	}
	scanf("%d",&fin);
	for(i=1;i<=n;i++) {
		a[i]=a[i-1]+q[i];
		q[i]=q[i-1];
		ans=a[i]*i%mod;
		if(ans>=minn&&ans<=maxn) q[i]++;
	}
	for(i=1;i<=fin;i++) 
	scanf("%d%d",&x,&y),printf("%d\n",q[y]-q[x-1]);
	
	return 0;
}
