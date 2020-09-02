#include <cstdio>
#include <algorithm>

int n, sum, mx, a[101];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        sum += a[i];
        mx = std::max(mx, a[i]);
    }
    if (mx > sum - mx || (sum & 1)) printf("A\n");
    else printf("B\n");
    return 0;
}
