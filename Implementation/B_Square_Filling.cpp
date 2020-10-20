#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m;
const int N = 60;
int a[N][N], b[N][N];

int main() {
    int n, m; cin >> n >> m;

    for (int i = 0; i < n;i++) {
        for (int j = 0;j < m; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    vector<pair<int, int>> ans;
    for (int i = 0; i < n - 1;i++) {
        for (int j = 0;j < m - 1; j++) {
            if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
                ans.push_back({ i, j });
                b[i][j] = 1, b[i][j + 1] = 1, b[i + 1][j] = 1, b[i + 1][j + 1] = 1;
            }
        }
    }
    for (int i = 0; i < n;i++) {
        for (int j = 0;j < m; j++) {
            if (a[i][j] != b[i][j]) {
                return cout << -1, 0;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto it : ans)cout << it.first + 1 << ' ' << it.second + 1 << endl;

    return 0;
}