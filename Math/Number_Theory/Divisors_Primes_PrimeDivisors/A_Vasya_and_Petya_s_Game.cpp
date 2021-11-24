#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n; cin >> n;
    vector<int> v(n * n), ans;
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= n; j *= i) {
                ans.push_back(j);
            }
            for (int j = i; j <= n; j += i) {
                v[j] = 1;
            }
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)cout << it << ' ';
}