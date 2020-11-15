#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    int n, m; cin >> n >> m;
    int nn = n, mm = m;
    if (n >= m)return cout << n - m << endl, 0;

    // shortest path from n to m
    int res1 = 0;
    while (n < m) {
        n *= 2;
        res1++;
    }
    res1 += (n - m);

    // shortest path from m to n
    n = nn, m = mm;
    int res2 = 0;
    while (n < m) {
        if (m & 1) {
            m++;
        }
        else {
            m /= 2;
        }
        res2++;
    }
    res2 += (n - m);

    
    cout << min(res1, res2) << endl;


    return 0;
    int N = 100005;
    vector<int> vis(N);
    queue<pair<int, int>> q;
    q.push({ n, 0 });
    while (q.size()) {
        auto x = q.front(); q.pop();
        if (x.first < 0 || x.first > N || vis[x.first])continue;
        vis[x.first]++;
        if (x.first == m) {
            return cout << x.second << endl, 0;
        }
        q.push({ x.first - 1, x.second + 1 });
        q.push({ x.first * 2, x.second + 1 });
    }
    return 0;
}