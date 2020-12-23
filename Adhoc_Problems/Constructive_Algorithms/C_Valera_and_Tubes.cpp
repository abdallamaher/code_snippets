#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m, k; scanf("%d %d %d", &n, &m, &k);
    vector<vector<int>> g(n, vector<int>(m));
    vector<vector<pair<int, int>>> ans(k);
    k--;
    for (int i = 0; i < n;i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < m; j++) {
                int indx = max(0, k);
                ans[indx].push_back({ i, j });
                if (ans[indx].size() > 1)k--;
            }
        }
        else {
            for (int j = m - 1; j >= 0; j--) {
                int indx = max(0, k);
                ans[indx].push_back({ i, j });
                if (ans[indx].size() > 1)k--;
            }
        }
    }
    for (auto it : ans) {
        printf("%d ", it.size());
        for (auto a : it)printf("%d %d ", a.first + 1, a.second + 1);
        puts("");
    }
}