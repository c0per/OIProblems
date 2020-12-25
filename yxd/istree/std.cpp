#include <cstdio>
#include <cstring>

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

int n, m, cnt, head[maxn];
bool flg, vis[maxn];
struct edge {
    int v, nxt;
}e[maxm * 2];

void add(int u, int v) {
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}

void dfs(int x, int f) {
    vis[x] = true;
    for (int i = head[x]; i; i = e[i].nxt)
        if (e[i].v != f) {
            if (vis[e[i].v]) {
                flg = true;
            } else {
                dfs(e[i].v, x);
            }
        }
}

int main() {
    int t, u, v;
    scanf("%d", &t);
    while (t--) {
        cnt = 0;
        memset(head, 0, sizeof(head));
        memset(vis, 0, sizeof(vis));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; ++i) {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        flg = (n - 1 != m);
        dfs(1, 0);
        puts(flg ? "No" : "Yes");
    }
    return 0;
}
