#include <bits/stdc++.h>
using namespace std;
#define ll long long

int ar[1005][6];
int n;

bool check(int i, int j) {
    int a = 0, b = 0, c = 0;
    for (int x = 0; x < n; x++) {
        if (ar[x][i] && ar[x][j])
            ++c;
        else if (ar[x][i])
            ++a;
        else if (ar[x][j])
            ++b;
    }
    int h = n / 2;
    int need = max(0, h - a);
    need += max(0, h - b);
    return need <= c;
}


inline void solve() {
    cin >> n;
    for (int i = 0;i < n; i++) {
        for (int j = 0; j < 5; j++) {
            int x; cin >> x;
            ar[i][j] = x;
        }
    }
    int ok = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            ok |= check(i, j);
        }
    }
    cout << (ok ? "YES" : "NO") << endl;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)solve();
}