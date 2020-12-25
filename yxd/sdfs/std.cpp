#include <cstdio>
#include <algorithm>

const int maxn = 1e5 + 5;
const int maxm = 2e5 + 5;

int n, m, cnt, tcnt, head[maxn];
bool vis[maxn];
struct edge {
    int v, nxt;
}e[maxm * 2];
struct tmp_edge {
    int u, v;
}tmp_e[maxm * 2];

bool cmp(tmp_edge a, tmp_edge b) {
    return a.v > b.v;
}

void add(int u, int v) {
    e[++cnt] = (edge){v, head[u]};
    head[u] = cnt;
}

void sdfs(int x) {
    printf("%d ", x);
    vis[x] = true;
    for (int i = head[x]; i; i = e[i].nxt)
        if (!vis[e[i].v])
            sdfs(e[i].v);
}

int main() {
    int u, v;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d", &u, &v);
        tmp_e[++tcnt] = (tmp_edge){u, v};
        tmp_e[++tcnt] = (tmp_edge){v, u};
    }
    std::sort(tmp_e + 1, tmp_e + 1 + tcnt, cmp);
    for (int i = 1; i <= tcnt; ++i)
        add(tmp_e[i].u, tmp_e[i].v);
    sdfs(1);
    return 0;
}
