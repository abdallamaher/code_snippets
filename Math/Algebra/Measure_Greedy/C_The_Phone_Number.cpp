#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int n; cin >> n;
    int r = sqrt(n);
    int t = r;
    int D = n / r;
    while (D--) {
        for (int i = t; i > t - r; i--) {
            printf("%d ", i);
        }
        t += r;
    }

    if (n % r) {
        for (int i = n; i > n / r * r; i--) {
            printf("%d ", i);

        }
    }
}


int main() {
    int n; cin >> n;
    int r = sqrt(n);
    vector<int> v;
    for (int i = 0;i <= n; i++) {
        v.push_back(i);
    }

    for (int i = 1; i <= n;i += r) {
        reverse(v.begin() + i, v.begin() + min(i + r, n + 1));
    }

    for (int i = 1;i <= n;i++)printf("%d ", v[i]);


    return 0;
}