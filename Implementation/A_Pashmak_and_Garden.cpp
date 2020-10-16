#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x2 < x1)swap(x2, x1), swap(y2, y1);

    if (x1 == x2) {
        printf("%d %d %d %d\n", x1 + y2 - y1, y1, x2 + y2 - y1, y2);
    }
    else if (y1 == y2) {
        printf("%d %d %d %d\n", x1, y1 + x2 - x1, x2, y2 + x2 - x1);
    }
    else if (abs(x2 - x1) == abs(y2 - y1) &&
        (    tan(acos(-1.0L) * 45 / 180.0L) == (y2 - y1) / (x2 - x1) ||
            -1 * tan(acos(-1.0L) * 45 / 180.0L) == (y2 - y1) / (x2 - x1)
            )
        ) {
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    }
    else puts("-1");

    return 0;
}