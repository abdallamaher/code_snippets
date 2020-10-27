#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

bool is_prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0)return 0;
    }
    return 1;
}

int main() {
    int t; cin >> t;
    while (t--) {
        double n; scanf("%lf", &n);
        if (n > 1 && (int)sqrt(n) == sqrt(n) && is_prime((int)sqrt(n)))puts("YES");
        else puts("NO");
    }

    return 0;
}