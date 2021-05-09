#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int x, y; cin >> x >> y;
    int a = y, b = y, c = y;
    int ans = 0;
    while (true) {
        if (a >= x && b >= x && c >= x)break;

        ans++;

        if (ans % 3 == 1)
            a = b + c - 1;
        if (ans % 3 == 2)
            b = a + c - 1;
        if (ans % 3 == 0)
            c = a + b - 1;
    }

    printf("%d\n", ans);
}