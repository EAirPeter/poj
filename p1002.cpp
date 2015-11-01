#include <cctype>
#include <cstddef>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int N;
int M[128];
char S[1024];
map<int, int> T;

int main() {
    M['A'] = M['B'] = M['C'] = 2;
    M['D'] = M['E'] = M['F'] = 3;
    M['G'] = M['H'] = M['I'] = 4;
    M['J'] = M['K'] = M['L'] = 5;
    M['M'] = M['N'] = M['O'] = 6;
    M['P'] = M['R'] = M['S'] = 7;
    M['T'] = M['U'] = M['V'] = 8;
    M['W'] = M['X'] = M['Y'] = 9;
    scanf("%d", &N);
    while (N--) {
        scanf("%s", S);
        int s = 0;
        for (const char *c = S; *c; ++c)
            if (*c != '-')
                s = s * 10 + (isdigit(*c) ? (*c & 0x0f) : M[(size_t) *c]);
        ++T[s];
    }
    bool nod = true;
    for (map<int, int>::iterator i = T.begin(); i != T.end(); ++i)
        if (i->second > 1) {
            nod = false;
            printf("%03d-%04d %d\n", i->first / 10000, i->first % 10000, i->second);
        }
    if (nod)
        puts("No duplicates.");
    return 0;
}
