#include<bits/stdc++.h>

#define int long long
using namespace std;
const int N=2e5+7;

int n,k;
int a[N];
vector<int >bl[N];
int sum;
int fd(int x,int y)
{
	return find(bl[x].begin(),bl[x].end(),y)-bl[x].begin();
}
int B;
void ch(int &fx,int &fy,int &x,int &y,int &k,int &l,int &r)
{
	x=a[l];
	y=a[r];
	fx=l/B;
	fy=r/B;
	k=fd(fx,x);
	bl[fx][k]=y;
	sort(bl[fx].begin(),bl[fx].end());
	k=fd(fy,y);
	bl[fy][k]=x;
	
	sort(bl[fy].begin(),bl[fy].end());
	return ;
}

int query(int l,int r)
{
	if(l==r)
		return 0;
	int fx,fy,x,y,k;
    ch(fx,fy,x,y,k,l,r);
    int re=0,ch=1;
    if(x>y) 
	{ 
        ch=-1; 
        swap(x, y);
    }
    if (fx!=fy) 
	{
        for(int i=l+1;i<(fx+1)*B;i++)
        {
        	if(x<a[i]&&a[i]<y)
            re++;
		}   
            
        for(int id=fx+1;id<fy;id++)
            re+=upper_bound(bl[id].begin(),bl[id].end(),y)-lower_bound(bl[id].begin(),bl[id].end(),x);
        for(int i=fy*B;i<r;i++)
        {
			if(x<a[i]&&a[i]<y)
                re++;
		}    
    } 
	else 
	{
        for(int i=l+1;i<=r-1;i++) 
		{
            if (x<a[i]&&a[i]<y)
                re++;
        }
    }
    swap(a[l],a[r]);
    return (2*re+1)*ch;
}
int l,r,q;
int ans;
signed main()
{
	ios::sync_with_stdio(false);
	cin>>n>>q;
	B=sqrt(n);
	
	for(int i=1;i<=n;i++)
	{
		a[i]=i;
		bl[i/B].push_back(i);
	}
	
	while(q--)
	{
		cin>>l>>r;
		if(l>r)
		swap(l,r);
		
		ans+=query(l,r);
		cout<<ans<<endl;
	}
	
	
	return 0;
}
