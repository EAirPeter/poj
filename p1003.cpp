#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

struct que {
    int n;
    double d;
    int x;
};

inline bool cd(const que &a, const que &b) {
    if (a.d != b.d)
        return a.d < b.d;
    return a.n < b.n;
}

inline bool cn(const que &a, const que &b) {
    return a.n < b.n;
}

vector<que> D;

int main() {
    int n = 0;
    char s[8];
    while (scanf("%s", s) == 1) {
        if (!strcmp(s, "0.00"))
            break;
        que q = {n++, atof(s), 0};
        D.push_back(q);
    }
    sort(D.begin(), D.end(), cd);
    double x = 0;
    int y = 1;
    for (vector<que>::iterator i = D.begin(); i != D.end(); ++i) {
        while (x < i->d)
            x += 1.0 / ++y;
        i->x = y - 1;
    }
    sort(D.begin(), D.end(), cn);
    for (vector<que>::iterator i = D.begin(); i != D.end(); ++i)
        printf("%d card(s)\n", i->x);
    return 0;
}

