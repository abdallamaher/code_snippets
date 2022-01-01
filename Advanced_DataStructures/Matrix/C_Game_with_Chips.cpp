#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 200;
int sx[N], sy[N];
int ex[N], ey[N];

int main() {
    int n, m, k; cin >> n >> m >> k;


    for (int i = 0; i < k; i++) {
        scanf("%d %d", sx + i, sy + i);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d %d", ex + i, ey + i);
    }

    string ans = "";
    for (int i = 1;i < n; i++)ans += 'U';
    for (int i = 1;i < m; i++)ans += 'L';

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j < m; j++)ans += 'R';
        }
        else {
            for (int j = m - 1; j >= 1; j--)ans += 'L';
        }

        if (i < n - 1)ans += 'D';
    }
    cout << ans.size() << endl << ans << endl;
}