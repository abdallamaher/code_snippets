#include <bits/stdc++.h>
using namespace std;
#define ll long long

inline void solve() {
    int x1, x2, y1, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if (abs(y1 - y2) == abs(x1 - x2)) {
        printf("%d %d %d %d\n", x1, y2, x2, y1);
    }
    else if (y1 == y2) {
        int dis = abs(x1 - x2);
        printf("%d %d %d %d\n", x1, y2 + dis, x2, y1 + dis);
    }
    else  if (x1 == x2) {
        int dis = abs(y1 - y2);
        printf("%d %d %d %d\n", x1 + dis, y2, x2 + dis, y1);
    }
    else {
        cout << -1 << endl;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--)solve();
}