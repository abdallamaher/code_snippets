#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = (int)4e3 + 5;

int n, k, f;
bool fac(int x) {
    ll res = 0;
    for (int i = 1; i <= x; i++) {
        res += i;
        if (res > k)return 1;   //hack
    }
    return 0;
}
int main() {
    cin.sync_with_stdio(false);
    cin >> n >> k;
    f = fac(n - 1);
    if (!f) return puts("no solution"), 0;
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", 0, i);
    }
    return 0;
}