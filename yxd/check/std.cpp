#include <cstdio>

const int maxn = 1005;
const int maxm = 2005;

int n, m, q, now, cnt, head[maxn];
struct edge {
    int v, nxt;
}e[maxm * 2];
bool vis[maxn][maxn];

void add(int u, int v) {
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}

void dfs(int x) {
    vis[now][x] = true;
    for (int i = head[x]; i; i = e[i].nxt)
        if (!vis[now][e[i].v])
            dfs(e[i].v);
}

int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        add(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        now = i;
        dfs(i);
    }
    scanf("%d", &q);
    while (q--) {
        scanf("%d%d", &u, &v);
        puts(vis[u][v] ? "Yes" : "No");
    }
    return 0;
}
