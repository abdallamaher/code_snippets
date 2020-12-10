#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double


int main() {
    int c; cin >> c;
    vector<ll> v;
    for (int i = 1; i * i <= c; i++) {      // i Number of balls he can touch
        if (c % i)continue;
        int n = i;
        ll nTerm = 1 + (n - 1) * (c / n);
        ll sum = n * (nTerm + 1) / 2;
        v.push_back(sum);

        if (c / i == i)continue;
        n = c / i;
        nTerm = 1 + (n - 1) * (c / n);
        sum = n * (nTerm + 1) / 2;
        v.push_back(sum);
    }
    sort(v.begin(), v.end());
    for (auto it : v)printf("%lld ", it);
}