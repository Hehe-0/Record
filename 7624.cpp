/*#include <bits/stdc++.h>

#define int long long
#define mid ((l + r) >> 1)
#define midd ((l + r + 1) >> 1)
using namespace std;
const int N = 1e6 + 7;

int n, m;
int _;
int head[N], nxt[N << 1], to[N << 1], edge[N << 1];
int pre[N], k[N];
void add(int x, int y, int z, int kk)
{
    _++;
    k[_] = kk;
    nxt[_] = head[x];
    head[x] = _;
    edge[_] = z;
    to[_] = y;
    return;
}
int d[N];

int pd(int top)
{
    fill(d + 1, d + 1 + n, (long long)8e18);
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; i <= _; j++)
        {
            int x = head[j], y = to[j];
            if (d[y] > d[x] + edge[j] + k[j] * top)
            {
                d[y] = d[x] + edge[j] + k[j] * top;
                pre[y] = j;
            }
        }
    }
    for (int j = 1; j <= _; j++)
    {
        int x = head[j], y = to[j];
        if (d[y] > d[x] + edge[j] + k[j] * top)
        {
            for (int i = 1; i <= n; i++)
                x = head[pre[x]];
            int moe = k[pre[x]];
            for (int now = head[pre[x]]; now != x; now = head[pre[now]])
                moe += k[pre[now]];
            return moe > 0 ? 1 : -1;
        }
    }
    return 0;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
        add(i + 1, i, -1, 0);
    add(1, n, -1, 1);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y, z;

        cin >> op >> x >> y >> z;
        if (op == 1)
        {
            if (x < y)
                add(y, x, -z, 0);
            else
                add(y, x, -z, -1);
        }
        else
        {
            if (x < y)
                add(x, y, z, 0);
            else
                add(x, y, z, -1);
        }
    }
    int l = 0, r = 1e12 + 7;

    while (l < r)
    {
        int f = pd(midd);
        if (!f)
            r = midd;
        else if (f == 1)
            l = midd + 1;
        else
            r = midd - 1;
    }

    int lans = l;
    l = 0, r = 1e12 + 7;
    while (l < r)
    {
        int t = pd(mid);
        if (t == 0)
            r = mid;
        else if (t == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    int rans = l;
    if (lans >= 1e12 + 7)
        puts("-1");
    else
        printf("%lld", lans - rans + 1);

    system("pause");
    return 0;
}*/
#include <bits/stdc++.h>

#define int long long
using namespace std;
const int N = 505;
const int M = 5005;

int ver[M], edge[M], k[M], from[M];
int cnt;
void add(int x, int y, int z, int kk)
{
    ver[++cnt] = y;
    from[cnt] = x;
    edge[cnt] = z;
    k[cnt] = kk;
}
int d[N];
int pre[N];
int n, m;
int check(int C)
{
    for (int i = 1; i <= n; i++)
    {
        d[i] = 9e18;
    }
    d[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= cnt; j++)
        {
            int x = from[j], y = ver[j];
            if (d[y] > d[x] + edge[j] + k[j] * C)
            {
                d[y] = d[x] + edge[j] + k[j] * C;
                pre[y] = j;
            }
        }
    }
    for (int j = 1; j <= cnt; j++)
    {
        int x = from[j], y = ver[j];
        if (d[y] > d[x] + edge[j] + k[j] * C)
        {
            for (int i = 1; i <= n; i++)
                x = from[pre[x]];
            int coe = k[pre[x]];
            for (int now = from[pre[x]]; now != x; now = from[pre[now]])
                coe += k[pre[now]];
            return coe > 0 ? 1 : -1;
        }
    }
    return 0;
}
signed main()
{
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i < n; i++)
        add(i + 1, i, -1, 0);
    add(1, n, -1, 1);
    for (int i = 1; i <= m; i++)
    {
        int opt, x, y, z;
        scanf("%lld%lld%lld%lld", &opt, &x, &y, &z);
        if (opt == 1)
        {
            if (x < y)
                add(y, x, -z, 0);
            else
                add(y, x, -z, 1);
        }
        else
        {
            if (x < y)
                add(x, y, z, 0);
            else
                add(x, y, z, -1);
        }
    }
    int l = 0, r = 1e12;
    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        int t = check(mid);
        if (t == 0)
            l = mid;
        else if (t == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    int lans = l;
    l = 0;
    r = 1e12;
    while (l < r)
    {
        int mid = (l + r) / 2;
        int t = check(mid);
        if (t == 0)
            r = mid;
        else if (t == 1)
            l = mid + 1;
        else
            r = mid - 1;
    }
    int rans = l;
    if (lans >= 1e12)
        puts("-1");
    else
        printf("%lld", lans - rans + 1);
    return 0;
}

