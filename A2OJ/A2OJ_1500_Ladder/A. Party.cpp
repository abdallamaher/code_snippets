#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
vector<int> adjList[2100];
vector<int> man;

int dfs(int i){
    int ans = 1;
    for (auto it : adjList[i]) {
        ans = max(ans, dfs(it) + 1);
    }
    return ans;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (x == -1)
            man.push_back(i);
        else
            adjList[x].push_back(i);
    }
    int ans = 0;
    for (auto it : man) {
        ans = max(ans, dfs(it));
    }
    cout << ans;
    return 0;
}
