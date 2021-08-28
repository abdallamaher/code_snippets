#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n; cin >> n;

    vector<int> ans(n);
    vector<int> indexs;
    vector<pair<int, int>> store;

    int next_index = 0;
    for (int i = 0; i < 2 * n; i++) {
        char type; cin >> type;
        if (type == '+') {
            indexs.push_back(next_index++);
            store.emplace_back(1, 1);
        }
        else {
            int x; scanf("%d", &x);
            if (store.empty() || store.back().first > x) {
                return 0 * puts("NO");
            }
            ans[indexs.back()] = x;
            indexs.pop_back();
            store.back().second--;
            int count = 0;
            while (store.size() && store.back().first <= x + 1) {
                count += store.back().second;
                store.pop_back();
            }
            if (count != 0) store.emplace_back(x, count);
        }
    }
    puts("YES");
    for (auto& it : ans) printf("%d ", it);
    return 0;
}