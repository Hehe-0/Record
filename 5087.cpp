#include<bits/stdc++.h>

#define int long long
using namespace std;
const int mod=1e9+7;

int dp[100011],a[100011];

signed main()
{
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=k;j>= 0;j--)
            dp[j]=(dp[j]+dp[j-1]*a[i]%mod)%mod;
        
    }
    cout<<dp[k]<<endl;
    
    
    return 0;
}
