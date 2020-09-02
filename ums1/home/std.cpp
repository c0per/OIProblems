#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#define mp std::make_pair

typedef long long ll;
const int maxn = 1e4 + 5;
const int maxm = 5e4 + 5;
const ll inf = 1ll << 62;
int n, m, b, cnt, k[maxn], head[maxn];
ll dis[maxn];
bool vis[maxn];
struct edge {
    int v, w, nxt;
}e[maxm * 4];
std::priority_queue<std::pair<ll, int> > q;

void add(int u, int v, int w) {
    e[++cnt] = (edge){v, w, head[u]};
    head[u] = cnt;
    e[++cnt] = (edge){u, w, head[v]};
    head[v] = cnt;
}

bool check(int mid) {
    memset(vis, 0, sizeof(vis));
    std::fill(dis + 2, dis + n + 1, inf);
    dis[1] = 0;
    q.push(mp(0, 1));
    while (!q.empty()) {
        int x = q.top().second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = true;
        for (int i = head[x]; i; i = e[i].nxt)
            if (k[e[i].v] <= mid && dis[x] + e[i].w < dis[e[i].v]) {
                dis[e[i].v] = dis[x] + e[i].w;
                q.push(mp(-dis[e[i].v], e[i].v));
            }
    }
    return dis[n] <= b;
}

int main() {
    int l, r = 0;
    scanf("%d%d%d", &n, &m, &b);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &k[i]);
        r = std::max(r, k[i]);
    }
    for (int i = 1; i <= m; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (u != v)
            add(u, v, w);
    }
    l = std::max(k[1], k[n]);
    if (!check(r))
        printf("-1");
    else {
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("%d\n", l);
    }
    return 0;
}
