#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<int> best(1 << 3, 1e8);
    best[0] = 0;
    for (int i = 0; i < n; i++) {
        int c; string s; cin >> c >> s;
        int mask = 0;
        for (auto& it : s)mask |= (1 << (it - 'A'));
        best[mask] = min(best[mask], c);
    }

    int ans = 1e8;
    for (int a = 0; a < (1 << 3); a++) {
        for (int b = 0; b < (1 << 3); b++) {
            for (int c = 0; c < (1 << 3); c++) {
                if ((a | b | c) == (1 << 3) - 1) {
                    ans = min(ans, best[a] + best[b] + best[c]);
                }
            }
        }
    }

    cout << (ans != 1e8 ? ans : -1) << endl;
}