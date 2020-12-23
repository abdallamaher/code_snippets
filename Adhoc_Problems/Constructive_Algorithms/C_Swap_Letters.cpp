#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int sum1 = 0, sum2 = 0;
    for (auto& it : a) {
        sum1 += bool(it == 'a');
    }
    for (auto& it : b) {
        sum2 += bool(it == 'a');
    }
    int sum = sum1 + sum2;
    if (sum & 1) {
        puts("-1");
        return 0;
    }
    vector<int> ab, ba;
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (a[i] == 'a')ab.push_back(i);
            else ba.push_back(i);
        }
    }
    int ans = ab.size() / 2 + ba.size() / 2;
    if (ab.size() & 1) {
        cout << ans + 2 << endl;
        cout << ab[0] + 1 << ' ' << ab[0] + 1 << endl;
        cout << ab[0] + 1 << ' ' << ba[0] + 1 << endl;
    }
    else cout << ans << endl;
    for (int i = ab.size() - 1; i > 0; i -= 2) {
        cout << ab[i] + 1 << ' ' << ab[i - 1] + 1 << endl;
    }
    for (int i = ba.size() - 1; i > 0; i -= 2) {
        cout << ba[i] + 1 << ' ' << ba[i - 1] + 1 << endl;
    }
}