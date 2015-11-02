#include <cstdio>

using namespace std;

int main() {
    double x = 0;
    int a, b;
    for (int i = 0; i < 12; ++i) {
        scanf("%d.%d", &a, &b);
        x += a * 100 + b;
    }
    x /= 12.0;
    a = (int) (x + 0.5);
    printf("$%d.%02d\n", a / 100, a % 100);
    return 0;
}

