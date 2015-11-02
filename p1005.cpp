#include <cmath>
#include <cstdio>

using namespace std;

int Main() {
    double x, y;
    scanf("%lf%lf", &x, &y);
    return (int) (acos(-1.0) * (x * x + y * y) / 2.0) / 50 + 1;

}

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        printf("Property %d: This property will begin eroding in year %d.\n", i, Main());
    }
    puts("END OF OUTPUT.");
    return 0;
}

