#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, a, b; scanf("%d%d%d%d", &n, &m, &a, &b);
    vector<pair<int, int>> ans;
    for (int i = a; i <= n; i++) {
        for (int j = b; j <= m; j++) {
            if (i > j)ans.push_back({ i, j });
        }
    }
    cout << ans.size() << endl;
    for (auto it : ans)printf("%d %d\n", it.first, it.second);
    return 0;
}