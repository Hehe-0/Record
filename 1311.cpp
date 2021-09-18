#include<bits/stdc++.h>

int n,p,x;
int a,b,ans;
int s[55],l[55],c[55];

int main() 
{
	std::cin>>n>>x>>p;
    
    for(int i=1;i<=n;++i) 
	{
        std::cin>>a>>b;
        if(b<=p) 
		x=i;
        if(x&&l[a]<=x) 
		c[a]=s[a];
		
        s[a]++;
        l[a]=i;
        ans+=c[a];
    }
    
    std::cout<<ans;
    return 0;
}
