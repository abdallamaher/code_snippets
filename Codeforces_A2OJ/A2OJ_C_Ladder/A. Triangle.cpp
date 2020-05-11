#include <bits/stdc++.h>
using namespace std;
#define ll long long
struct point {
    int x, y;
} p1, p2;
int a, b;

ll dis(int x1, int y1, int x2, int y2) {
    return 1ll * (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
    cin.sync_with_stdio(false);
    cin >> a >> b;
    for (int x = 1; x <= a; x++) {
        if (sqrt(a * a - x * x) - (int)sqrt(a * a - x * x))continue;
        p1 = { x, (int)sqrt(a * a - x * x) };
        for (int y = 1; y <= b; y++) {
            if (sqrt(b * b - y * y) - (int)sqrt(b * b - y * y))continue;
            p2 = { -(int)sqrt(b * b - y * y),  y };
            if (p1.y == p2.y ||
                p1.x == 0 || p1.y == 0 || 
                p2.x == 0 || p2.y == 0 ||
                dis(p1.x, p1.y, p2.x, p2.y) != 1ll * a * a + 1ll * b * b)continue;
            return printf("YES\n0 0\n%d %d\n%d %d\n", p1.x, p1.y, p2.x, p2.y), 0;
        }
    }
    puts("NO");
    return 0;
}