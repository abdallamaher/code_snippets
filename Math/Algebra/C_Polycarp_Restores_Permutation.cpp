#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;
    vector<int> data(n);
    int low = 0, cur = 0;
    for (int i = 0; i < n - 1; i++) {
        scanf("%d", &data[i]);
        cur += data[i];
        low = min(low, cur);
    }
    vector<int> perm(n + n);
    int st = -1 * low + 1;  // start with low, you come to it with at least bigger number
    perm[0] = st;
    for (int i = 1; i < n;i++) {
        perm[i] = perm[i - 1] + data[i - 1];
    }

    // check
    set<int> ss;
    for (int i = 0; i < n;i++) {
        ss.insert(perm[i]);
    }
    if (ss.size() != n) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++)if (perm[i]<0 || perm[i] > n) {
        cout << -1;
        return 0;
    }

    // print
    for (int i = 0; i < n; i++)printf("%d ", perm[i]);
}