#include <bits/stdc++.h>
using namespace std;
#define ll long long



int main() {
    int n; cin >> n;
    vector<ll> v;
    for (int k = 1; k < 10; ++k) {
        for (int mask = 0; mask < (1 << k);mask++) {
            int num = 0;
            for (int i = 0; i < k; i++) {
                if (mask & (1 << i))num = num * 10 + 7;
                else num = num * 10 + 4;
            }
            v.push_back(num);
        }
    }
    sort(v.begin(), v.end());

    cout << lower_bound(v.begin(), v.end(), n) - v.begin() + 1 << endl;
}