#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int n, k; cin >> n >> k;
    int ans = -1;
    for (int i = (n + 1) / 2; i <= n; i++) {
        if (i % k == 0) {
            ans = i;
            break;
        }
    }
    printf("%d\n", ans);
    return 0;
}