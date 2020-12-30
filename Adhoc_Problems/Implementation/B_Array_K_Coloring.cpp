#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int n, k; cin >> n >> k;
    map<int, vector<int>> indx;
    int ok = 1;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        indx[x].push_back(i);
        if (indx[x].size() > k)ok = 0;
    }
    if (ok == 0) {
        cout << "NO";
        return 0;
    }
    cout << "YES\n";
    int ans[n + n] = {};
    int cnt = 0;
    for (auto it : indx) {
        for (int i = 0; i < it.second.size(); i++) {
            ans[it.second[i]] = cnt + 1;
            cnt++;
            cnt %= k;
        }
    }
    for (int i = 0; i < n; i++)cout << ans[i] << ' '; cout << endl;
}