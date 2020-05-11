#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 7;

int n, m, s1, s2, f, s;
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> m;
    swap(n, m);
    s1 = n, s2 = m;
    if (n > m)f = 1;
    for (ll i = (f ? n : m); i <= 1ll * n * m; i += (f ? n : m)) {
        if (i % (f ? m : n) == 0) {
            f ? s2++ : s1++;
        }
    }
    if (s1 == s2)puts("Equal");
    else if (s1 > s2)puts("Dasha");
    else puts("Masha");
    return 0;
}