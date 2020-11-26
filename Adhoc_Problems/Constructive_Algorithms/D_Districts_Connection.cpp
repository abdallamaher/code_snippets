#include <bits/stdc++.h>
using namespace std;
#define ll long long


int main() {
    int t; cin >> t;
    while (t--) {
        int n; scanf("%d", &n);
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++) {
            int x; scanf("%d", &x);
            mp[x].push_back(i + 1);
        }
        if (mp.size() == 1) {
            cout << "NO\n";
            continue;
        }
        int a = 0, b = 0, j = 0;
        for (auto it : mp) {
            if (j == 0)a = it.second[0];
            if (j) {
                b = it.second[0];
                break;
            }
            j++;
        }
        j = 0;
        cout << "YES\n";
        for (auto it : mp) {
            if (j == 0) {
                for (int i = 1; i < it.second.size(); i++) {
                    cout << it.second[i] << ' ' << b << endl;
                }
            }
            if (j) {
                for (int i = 0; i < it.second.size(); i++) {
                    cout << it.second[i] << ' ' << a << endl;
                }
            }
            j++;
        }
    }
    return 0;
}