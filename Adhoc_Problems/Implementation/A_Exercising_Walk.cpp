#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int t; cin >> t;
    while (t--) {
        int a, b, c, d; scanf("%d %d %d %d", &a, &b, &c, &d);
        int x, y, x1, x2, y1, y2; scanf("%d %d %d %d %d %d", &x, &y, &x1, &y1, &x2, &y2);

        int fx = x + b - a;
        int fy = y + d - c;

        if ((x1 == x2 && b + a) || (y1 == y2 && d + c) || fx > x2 || fx < x1 || fy > y2 || fy < y1)
            puts("No");
        else puts("Yes");
    }
    return 0;
}