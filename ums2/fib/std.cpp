#include <cstdio>
#include <cstring>

typedef long long ll;
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
int n, m, a[maxn];
struct mat {
    int a[2][2];

    mat() {
        memset(a, 0, sizeof(a));
    }

    mat operator* (const mat& x) const {
        mat re;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                for (int w = 0; w < 2; ++w)
                    (re.a[i][j] += (ll)a[i][w] * x.a[w][j] % mod) %= mod;
        return re;
    }

    mat operator+ (const mat& x) const {
        mat re;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 2; ++j)
                re.a[i][j] = (a[i][j] + x.a[i][j]) % mod;
        return re;
    }
}base;

mat ksm(ll x) {
    mat re, bs = base;
    re.a[0][0] = re.a[1][1] = 1;
    while (x) {
        if (x & 1) re = re * bs;
        bs = bs * bs;
        x >>= 1;
    }
    return re;
}

struct seg_t {
    mat c[maxn << 2], tag[maxn << 2];

    void pushup(int k) {
        c[k] = c[k << 1] + c[k << 1 | 1];
    }

    void pushdown(int k) {
        c[k << 1] = c[k << 1] * tag[k];
        c[k << 1 | 1] = c[k << 1 | 1] * tag[k];
        tag[k << 1] = tag[k << 1] * tag[k];
        tag[k << 1 | 1] = tag[k << 1 | 1] * tag[k];
        tag[k].a[0][1] = tag[k].a[1][0] = 0;
        tag[k].a[0][0] = tag[k].a[1][1] = 1;
    }

    void init(int k, int l, int r) {
        tag[k].a[0][0] = tag[k].a[1][1] = 1;
        if (l == r) {
            c[k] = ksm(a[l] - 1);
            return;
        }
        int mid = (l + r) >> 1;
        init(k << 1, l, mid);
        init(k << 1 | 1, mid + 1, r);
        pushup(k);
    }

    void update(int k, int l, int r, int L, int R, mat x) {
        if (L <= l && r <= R) {
            c[k] = c[k] * x;
            tag[k] = tag[k] * x;
            return;
        }
        pushdown(k);
        int mid = (l + r) >> 1;
        if (L <= mid) update(k << 1, l, mid, L, R, x);
        if (R > mid) update(k << 1 | 1, mid + 1, r, L, R, x);
        pushup(k);
    }

    mat query(int k, int l, int r, int L, int R) {
        if (L <= l && r <= R)
            return c[k];
        mat re;
        pushdown(k);
        int mid = (l + r) >> 1;
        if (L <= mid) re = re + query(k << 1, l, mid, L, R);
        if (R > mid) re = re + query(k << 1 | 1, mid + 1, r, L, R);
        return re;
    }
}t;

int main() {
    base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    base.a[1][1] = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
    t.init(1, 1, n);
    while (m--) {
        int op, l, r, x;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%d", &l, &r, &x);
            t.update(1, 1, n, l, r, ksm(x));
        } else {
            scanf("%d%d", &l, &r);
            mat re = t.query(1, 1, n, l, r);
            printf("%d\n", (re.a[1][0] + re.a[1][1]) % mod);
        }
    }
    return 0;
}
