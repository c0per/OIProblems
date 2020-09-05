#include <cstdio>
#include <algorithm>

typedef long long ll;
const int maxn = 1e6 + 5;
int n, cnt, w[maxn], head[maxn];
struct edge {
    int v, w, nxt;
}e[maxn << 1];
ll ans, f[maxn];

void add(int u, int v, int w) {
    e[++cnt] = (edge){v, w, head[u]};
    head[u] = cnt;
    e[++cnt] = (edge){u, w, head[v]};
    head[v] = cnt;
}

void dfs(int x, int fa) {
    f[x] = w[x];
    ans = std::max(ans, f[x]);
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].v != fa) {
            dfs(e[i].v, x);
            ans = std::max(ans, f[x] + f[e[i].v] - e[i].w);
            f[x] = std::max(f[x], w[x] + f[e[i].v] - e[i].w);
        }
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) scanf("%d", &w[i]);
    for (int i = 1; i < n; ++i) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
    }
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}
