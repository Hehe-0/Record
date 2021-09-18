#include<bits/stdc++.h>

const int N=610,M=20010;

int n,m,P,cnt,i,j,k,t,now,f[N][N];
bool g[N][N],v[N][N];
struct vec
{
  int x,y,p;
  vec(){}
  vec(int _x,int _y){x=_x,y=_y;}
  vec operator-(const vec&b){return vec(x-b.x,y-b.y);}
}a[N],b[M],c[N+M],O;

inline int cross(vec a,vec b){return a.x*b.y-a.y*b.x;}
inline bool cmp(vec x,vec y){return cross(x-O,y-O)<0;}
int dp(int l,int r){
  if(l+1==r)return 1;
  if(v[l][r])return f[l][r];
  v[l][r]=1;
  int&t=f[l][r];
  for(int i=l+1;i<r;i++)if(g[i][l]&&g[i][r])t=(t+dp(l,i)*dp(i,r))%P;
  return t;
}
int main()
{
  scanf("%d%d%d",&n,&m,&P);
  for(i=1;i<=n;i++)scanf("%d%d",&a[i].x,&a[i].y);
  for(i=1;i<=m;i++)scanf("%d%d",&b[i].x,&b[i].y);
  O=a[1];
  std::sort(a+2,a+n+1,cmp);
  for(i=1;i<=n;i++)a[i].p=i;
  for(i=1;i<=n;i++){
    O=a[i];
    cnt=0;
    for(j=1;j<=n;j++)if(j!=i)c[++cnt]=a[j];
    for(j=1;j<=m;j++)c[++cnt]=b[j];
    std::sort(c+1,c+cnt+1,cmp);
    for(j=1,t=0;j<=cnt;j=k){
      for(now=0,k=j;k<=cnt&&!cross(c[k]-O,c[j]-O);k++)if(!c[k].p)now++;
      if(!now&&!t)for(k=j;k<=cnt&&!cross(c[k]-O,c[j]-O);k++)if(c[k].p)g[i][c[k].p]=g[c[k].p][i]=1;
      t^=now&1;
    }
  }
  return printf("%d",dp(1,n)),0;
}
