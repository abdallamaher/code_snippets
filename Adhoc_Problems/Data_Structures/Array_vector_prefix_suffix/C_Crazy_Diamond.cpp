#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 3e5 + 5;
int ar[N], idx[N];
vector<pair<int, int>> ans;

int main() {
    cin >> n;
    for (int i = 1;i <= n; i++) {
        int x; scanf("%d", &x);
        ar[i] = x;
        idx[x] = i;
    }

    for (int i = 1;i <= n; i++) {
        if (ar[i] == i)continue;
        int j = idx[i];
        if ((j - i) * 2 >= n) {
            ans.push_back({ i, j });
        }
        else if ((i - 1) * 2 >= n) {
            ans.push_back({ 1, i });
            ans.push_back({ 1, j });
            ans.push_back({ 1, i });
        }
        else if ((n - j) * 2 >= n) {
            ans.push_back({ j, n });
            ans.push_back({ i, n });
            ans.push_back({ j, n });
        }
        else {
            ans.push_back({ i, n });
            ans.push_back({ 1, j });
            ans.push_back({ 1, n });
            ans.push_back({ i, n });
            ans.push_back({ 1, j });
        }
        swap(idx[ar[i]], idx[ar[j]]);
        swap(ar[i], ar[j]);
    }
    cout << ans.size() << endl;
    for (auto& [key, val] : ans) {
        printf("%d %d\n", key, val);
    }
}