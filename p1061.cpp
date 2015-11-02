#include <iostream>

using namespace std;

long long X, Y, M, N, L;

long long exgcd(long long a, long long b, long long &x, long long &y) {
    if (b) {
        long long c = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return c;
    }
    x = 1;
    y = 0;
    return a;
}

int main() {
    cin >> X >> Y >> M >> N >> L;
    long long a, b, c;
    long long u = M - N;
    long long v = Y - X;
    u = (u % L + L) % L;
    v = (v % L + L) % L; 
    c = exgcd(u, L, a, b);
    if (c != 1)
        cout << "Impossible" << endl;
    else
        cout << (a * v % L + L) % L << endl;
    return 0;
}

