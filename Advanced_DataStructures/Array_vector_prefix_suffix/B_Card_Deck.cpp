#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int ar[N], pos[N];
int n;

inline void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
        pos[ar[i]] = i;
    }
    int pre_mx_pos = n;
    for (int i = n; i >= 1; i--) {  // mx

        // from  mx     to  pre_mx_pos
        for (int j = pos[i]; j < pre_mx_pos; j++) {
            cout << ar[j] << ' ';
        }
        pre_mx_pos = min(pre_mx_pos, pos[i]);

    }
    cout << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}