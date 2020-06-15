#define _CRT_SECURE_NO_WvNINGS
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9 + 5;
const int N = 1e7 + 5;

int n, mn, ans;
int ar[N];

bool ok(int x) {
    vector<int> adjList[110];
    for (int i = 0; i < n; i++) {
        int l = i % x;
        adjList[l].push_back(ar[i]);
    }
    for (auto it : adjList) {
        for (int i = 0; i < it.size(); i++) {
            if (it[i] < it.size() - i - 1) return 0;
        }
    }
    return 1;
}
int main() {
    cin.sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    sort(ar, ar + n, [](const int& a, const int& b) {
        return a > b;
        });
    int st = 1, en = 100, mid;
    while (st < en) {
        mid = (st + en) / 2;
        if (ok(mid))
            en = mid;
        else
            st = mid + 1;
    }
    cout << en;
    return 0;
}