#include <cstdio>
#include <algorithm>

const int maxn = 3005;
int n, m, f[maxn][maxn], w[26];
char s[maxn];
bool vis[26];

int main() {
    scanf("%s\n", s + 1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = true;
            ++m;
        }
    for (int i = 1; i <= m; ++i) {
        char c;
        int a, b;
        scanf("%c%d%d\n", &c, &a, &b);
        w[c - 'a'] = std::min(a, b);
    }
    memset(f, 0x3f, sizeof(f));
    for (int i = 1; i <= n; ++i)f[i][i] = 0;
    for (int k = 2; k <= n; ++k)
        for (int i = 1; i + k - 1 <= n; ++i) {
            int j = i + k - 1;
            if (s[i] == s[j])
                f[i][j] = k == 2 ? 0 : f[i + 1][j - 1];
            f[i][j] = std::min(f[i][j], std::min(f[i + 1][j] + w[s[i] - 'a'], f[i][j - 1] + w[s[j] - 'a']));
        }
    printf("%d\n", f[1][n]);
    return 0;
}
