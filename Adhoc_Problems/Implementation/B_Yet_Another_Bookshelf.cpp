#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> v;
        for (int i = 1; i <= n; i++) {
            int x; scanf("%d", &x);
            if (x)v.push_back(i);
        }
        n = v.size();
        int sum = 0;
        for (int i = 1; i < n; i++) {
            sum += v[i] - v[i - 1] - 1;
        }
        cout << sum  << '\n';
    }
    return 0;
}