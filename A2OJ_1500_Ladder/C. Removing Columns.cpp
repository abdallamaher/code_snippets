#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, ans;
int removed[200];

int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    vector<string> ar(n);
    for (int i = 0; i < n; i++) cin >> ar[i];


    for (int i = 1; i < n; i++) {
        for (int j = 0; j < ar[i - 1].length() && j < ar[i].length(); j++) {
            if (removed[j])continue;
            else if (ar[i - 1][j] < ar[i][j]) break;
            else if (ar[i - 1][j] > ar[i][j]) {
                removed[j]++;
                ans++;
                i = 1; j = 0;
            }
        }
    }
    cout << ans;
    return 0;
}