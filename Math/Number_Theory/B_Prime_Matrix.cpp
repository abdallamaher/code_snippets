#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 5;
int p[N];

void sieve() {
    p[1] = 1;
    for (int i = 2; i * i < N; i++) {
        if (p[i]) continue;
        for (int j = i + i; j < N; j += i)
            p[j] = 1;
    }
}

int main() {
    //cout << "her";
    sieve();
    vector<int> primes;
    for (int i = 2; i < N; i++) if (!p[i]) {
        primes.push_back(i);
    }
    int n, m; cin >> n >> m;
    vector<int> r(n), c(m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x; scanf("%d", &x);
            if (!p[x])continue;
            int f = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
            r[i] += primes[f] - x;
            c[j] += primes[f] - x;
        }
    }
    int ans = 1e9;
    for (auto it : r)ans = min(ans, it);
    for (auto it : c)ans = min(ans, it);

    cout << ans << endl;
    return 0;
}