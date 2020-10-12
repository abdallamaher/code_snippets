#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, k; scanf("%d%d", &n, &k);
    ll sum = 0;
    while (n--) {
        int l, r; scanf("%d%d", &l, &r);
        sum += (r - l + 1);
    }
    printf("%lld\n", sum % k == 0 ? 0 : k - sum % k);
    return 0;
}