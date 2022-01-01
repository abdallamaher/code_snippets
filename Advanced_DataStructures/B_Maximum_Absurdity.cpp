#include <bits/stdc++.h>
using namespace std;
#define ll long long

/*
5 2
3 9 7 5 1
*/

int main() {
    int n, k; cin >> n >> k;
    ll ar[n + n] = {};
    for (int i = 1; i <= n; i++) {
        cin >> ar[i];
        ar[i] += ar[i - 1];
    }
    for (int i = n; i >= k;i--) ar[i] -= ar[i - k];
    int bestL[n + n] = {};
    ll mx = 0;
    for (int i = k; i <= n; i++) {
        if (ar[i] > mx) bestL[i] = i, mx = ar[i];
        else bestL[i] = bestL[i - 1];
    }
    mx = 0;
    pair<int, int> ans = {};
    for (int i = n - k + 1; i > k; i--) {
        if (ar[bestL[i - 1]] + ar[i + k - 1] >= mx) {
            ans = { bestL[i - 1] - k + 1, i };
            mx = ar[bestL[i - 1]] + ar[i + k - 1];
        }
    }
    cout << ans.first << ' ' << ans.second << endl;
    return 0;
}