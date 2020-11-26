#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, d; cin >> n >> d;
    vector<int> v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
        if (i && v[i - 1] >= v[i]) {
            int x = (v[i - 1] - v[i] + d) / d;
            sum += x;
            v[i] += x * d;
        }
    }
    cout << sum << '\n';
    return 0;
}