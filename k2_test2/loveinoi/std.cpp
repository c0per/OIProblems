#include <cstdio>
#include <cstring>

int cnt = 0;
char s[100005];

int main() {
    char tmp[10001];
    while (scanf("%s", tmp) != EOF) {
        int len = strlen(tmp);
        for (int i = 0; i < len; ++i)
            if ((tmp[i] >= 'a' && tmp[i] <= 'z') || (tmp[i] >= 'A' && tmp[i] <= 'Z'))
                s[++cnt] = tmp[i];
    }
    for (int i = 1; i <= cnt; ++i) {
        printf("%c", s[i]);
        if (i % 5 == 0) printf(" ");
    }
    return 0;
}
