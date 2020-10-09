#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    int a = 0, b = 0, c = 0;
    while (n--) {
        int z, y, x; scanf("%d%d%d", &x, &y, &z);
        a += x, b += y, c += z;
    }
    puts(a || b || c ? "NO" : "YES");
    return 0;
}