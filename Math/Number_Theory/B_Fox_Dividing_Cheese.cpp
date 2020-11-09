#include<bits/stdc++.h>
using namespace std;
#define ld long double 


inline int bfs(int a, int b) {
    map<pair<int, int>, int> vis;
    queue<pair<int, pair<int, int>>> q;
    q.push({ 0, {a, b} });
    while (q.size()) {
        auto cur = q.front(); q.pop();
        int a = cur.second.first, b = cur.second.second, dis = cur.first;
        if (vis[{a, b}])continue;
        vis[{a, b}] = 1;
        if (a == b)return dis;
        for (int i = 2; i <= 5; i++) {
            if(i == 4)continue;
            if (a % i == 0)q.push({ dis + 1, {a / i, b} });
            if (b % i == 0)q.push({ dis + 1, {a , b / i} });
        }
    }
    return -1;
}

int main() {
    int x, y; cin >> x >> y;

    cout << bfs(x, y) << endl;

    return 0;
    int ar[] = { 2, 3, 5 };
    vector<int> a(10), b(10);
    for (int i = 0; i < 3;i++) {
        while (x % ar[i] == 0) {    // ( 1 << 30 ) is 1e9
            x /= ar[i];
            a[ar[i]]++;
        }
        while (y % ar[i] == 0) {
            y /= ar[i];
            b[ar[i]]++;
        }
    }

    if (x != y) return cout << -1, 0;

    int sum = 0;
    for (int i = 0; i < 10; i++) {
        sum += abs(a[i] - b[i]);
    }
    cout << sum << endl;
    return 0;
}