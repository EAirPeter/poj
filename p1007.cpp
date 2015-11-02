#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

struct ele {
    const char *s;
    int n;
} T[200];

inline bool operator < (const ele &a, const ele &b) {
    if (a.n != b.n)
        return a.n < b.n;
    return a.s < b.s;
}

int N, M;
char S[200][200];
int F[128];

void fad(int p) {
    while (p) {
        ++F[p];
        p -= p & -p;
    }
}

int fqr(int p) {
    int x = 0;
    while (p < 128) {
        x += F[p];
        p += p & -p;
    }
    return x;
}

int main() {
    scanf("%d%d", &N, &M);
    for (int i = 0; i < M; ++i) {
        scanf("%s", S[i]);
        memset(F, 0, sizeof(F));
        T[i].s = S[i];
        for (int j = 0; j < N; ++j) {
            fad(S[i][j]);
            T[i].n += fqr(S[i][j] + 1);
        }
    }
    sort(T, T + M);
    for (int i = 0; i < M; ++i)
        puts(T[i].s);
    return 0;
}

