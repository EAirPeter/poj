#include <cstdio>

using namespace std;

int N[3] = {23, 28, 33};
int M[3];
int P = 1;

int Main(int (&n)[3], int s) {
    int x = 0;
    for (int i = 0; i < 3; ++i) {
        n[i] %= N[i];
        x += n[i] * M[i];
    }
    x -= s;
    x = (x % P + P) % P;
    return x ? x : P;
}

int exgcd(int a, int b, int &x, int &y) {
    if (b) {
        int c = exgcd(b, a % b, x, y);
        int t = y;
        y = x - a / b * y;
        x = t;
        return c;
    }
    x = 1;
    y = 0;
    return a;
}

int main() {
    int a, b, c;
    for (int i = 0; i < 3; ++i)
        P *= N[i];
    for (int i = 0; i < 3; ++i) {
        M[i] = P / N[i];
        c = exgcd(M[i], N[i], a, b);
        c = (a % N[i] + N[i]) % N[i];
        M[i] = M[i] * c;
    }
    int t = 0;
    int n[3], s;
    while (scanf("%d%d%d%d", &n[0], &n[1], &n[2], &s) == 4) {
        if (s== -1)
            break;
        printf("Case %d: the next triple peak occurs in %d days.\n", ++t, Main(n, s));
    }
    return 0;
}

