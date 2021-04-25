#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline bool check(int val, int k) {
    return val >= 0 && val >= k && __builtin_popcountll(val) <= k;
}


int main() {
    int n, p; scanf("%d %d", &n, &p);

    for (int i = 1; i < 1e6; i++) {
        if (check(n - i * p, i)) {
            cout << i << endl;
            return 0;
        }
    }
    puts("-1");
}