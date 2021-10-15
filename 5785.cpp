#include<bits/stdc++.h>

#define int long long
#define mid ((l+r)>>1)
using namespace std;
const int N=3e5+7;

long long n,hd,tl,q[N];
long long S,dd[N],w[N],f[N];

double slope(int x,int y)
{
	return 1.0*(f[x]-f[y])/(1.0*(w[x]-w[y]));
}

long long find(int cmp)
{
    if(hd==tl)
	return q[hd];
	
    long long l=hd,r=tl;
    while(l<r)
	{
        if(f[q[mid+1]]-f[q[mid]]<=cmp*(w[q[mid+1]]-w[q[mid]]))
		l=mid+1;
        else r=mid;
    }
    return q[l];
}

signed main()
{
	ios::sync_with_stdio(false);
    cin>>n>>S;
	hd=1,tl=1;
    for(int i=1;i<=n;i++)
    {
    	int x;
    	cin>>x;
    	dd[i]=x+dd[i-1];
    	cin>>x;
		w[i]=x+w[i-1];	
	}
	
    for(int i=1;i<=n;i++)
	{
        int pos=find(S+dd[i]);
        f[i]=f[pos]+S*(w[n]-w[pos])+dd[i]*(w[i]-w[pos]);
        
        while(hd<tl && (f[q[tl]]-f[q[tl-1]])*(w[i]-w[q[tl]])>=(f[i]-f[q[tl]])*(w[q[tl]]-w[q[tl-1]]))
		--tl;
        q[++tl]=i;
    }
    
    cout<<f[n];
    return 0;
}
