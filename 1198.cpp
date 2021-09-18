#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 * 8 + 5;
ll mod, sum[maxn], b, len = 0, t = 0;
int n;
#define ls (x<<1)
#define rs ((x<<1)|1)
#define mid ((l+r)>>1)
#define lson ls,l,mid
#define rson rs,mid+1,r
char a;
void build(int x, int l ,int r, int rl, int rd) { //ÔÚrlÎ»ÖÃ²åÈërd 
	if(l == r )
	{
		sum[x] = rd;
		return;
	}
	if(rl <= mid) build(lson, rl, rd);
	if(rl >  mid) build(rson, rl, rd);
	sum[x] = max(sum[ls], sum[rs]);
	return;
}
ll search(int x, int l, int r, int L, int R) {
	ll ans = 0;
	if(l >= L && r <= R) return sum[x];
	if(L <= mid) ans = max(ans, search(lson, L, R));
	if(R >  mid) ans = max(ans, search(rson, L, R));
	return ans;
}
int main() {
//	ios::sync_with_stdio(false);
	cin>>n>>mod;
	while(n--) {
		cin>>a>>b;
		if(a == 'A') {
			++len;
			build(1,1,len,len,(t + b) % mod);
		}
		else  {
			t = search(1,1,len,len-b+1,len);
			cout<<t<<endl;
		}
	}
	return 0;
}
