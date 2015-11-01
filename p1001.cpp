#include <cstdio>

struct num {
    int d[160];
    int s, p;
};

inline num operator * (const num &a, const num &b) {
    num c = {};
    for (int i = 0; i < a.s; ++i) {
        for (int j = 0; j < b.s; ++j) {
            c.d[i + j] += a.d[i] * b.d[j];
            c.d[i + j + 1] += c.d[i + j] / 10;
            c.d[i + j] %= 10;
        }
    }
    c.s = a.s + b.s;
    c.p = a.p + b.p;
    for (int i = 0; i < c.s; ++i)
        if (c.d[i] > 10) {
            c.d[i + 1] += c.d[i] / 10;
            c.d[i] %= 10;
        }
    while (c.d[c.s - 1] > 10) {
        c.d[c.s] = c.d[c.s - 1] /= 10;
        c.d[c.s - 1] %= 10;
        ++c.s;
    }
    return c;
}

char S[160];
int N;

int main() {
    while (scanf("%s%d", S, &N) == 2) {
        num a = {};
        a.s = 0;
        for (int i = 5; i > -1; --i)
            if (S[i] == '.')
                a.p = a.s;
            else
                a.d[a.s++] = S[i] & 0x0f;
        num x = {{1}, 1, 0};
        while (N--)
            x = x * a;
        int j = 0;
        for (int i = x.s - 1; i >= x.p; --i)
            S[j++] = (char) (x.d[i] | 0x30);
        S[j++] = '.';
        for (int i = x.p - 1; i >= 0; --i)
            S[j++] = (char) (x.d[i] | 0x30);
        char *s = S;
        while (*s == '0')
            ++s;
        char *t = S + j - 1;
        while (*t == '0')
            --t;
        if (s == t)
            puts("0");
        else {
            if (*t == '.')
                --t;
            *(t + 1) = '\0';
            puts(s);
        }
    }
    return 0;
}
