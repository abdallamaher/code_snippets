#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; scanf("%d", &n);
    vector<int> b;
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int x; scanf("%d", &x);
        if (mp[x] == 0)b.push_back(x);
        mp[x]++;
    }
    sort(b.begin(), b.end());
    deque<int> ans;
    for (int i = b.size() - 1; i >= 0; i--) {
        if (i != b.size() - 1 && mp[b[i]] > 1)ans.push_front(b[i]);
        ans.push_back(b[i]);
    }
    printf("%d\n", ans.size());
    for (int i = 0;i < ans.size(); i++)printf("%d ", ans[i]);
    // while (ans.size()) {
    //     printf("%d ", ans.front());
    //     ans.pop_front();
    // }
    return 0;
}