#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int n, a, b, c, d; scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x = i + b - c;
        int y = x + a - d;
        int z = c + y - b;
        
        if (1 <= x && x <= n &&
            1 <= y && y <= n &&
            1 <= z && z <= n &&
            z + d == i + a)ans++;
    }
    cout << 1ll * ans * n << endl;
}