#include <cstdio>
#include <algorithm>

int n, m, ans, same[10], nsame[10], equ[10], nequ[10], a[10];

void dfs(int dep) {
    if (dep > n) {
        ++ans;
        return;
    }
    for (int i = 0; i <= 9; ++i) {
        if (same[dep] && i != a[same[dep]]) continue;
        if (nsame[dep] && i == a[nsame[dep]]) continue;
        if (equ[dep] && i != equ[dep]) continue;
        if (nequ[dep] && i == nequ[dep]) continue;
        a[dep] = i;
        dfs(dep + 1);
    }
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; ++i) {
        int o, x, y;
        scanf("%d%d%d", &o, &x, &y);
        if (x < y) std::swap(x, y);
        switch (o) {
            case 1:
                same[x]= std::max(same[x], y);
                break;
            case 2:
                nsame[x] = y;
                break;
            case 3:
                equ[x] = y;
                break;
            case 4:
                nequ[x] = y;
                break;
        }
    }
    dfs(1);
    printf("%d\n", ans);
    return 0;
}
