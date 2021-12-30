#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5 + 5;
int n, T, counter;
int p[N];
map<string, int> mp;

int find_parent(int n) {
    vector<int> v;
    while (p[n] > 0) {
        v.push_back(n);
        n = p[n];
    }
    for (auto& it : v)p[it] = n;
    return n;
}

int Union(int u, int v) {
    u = find_parent(u);
    v = find_parent(v);
    if (u == v)return abs(p[u]);
    p[u] += p[v];
    p[v] = u;
    return abs(p[u]);
}

void init() {
    counter = 1;
    mp.clear();
    memset(p, -1, sizeof(p));
}

int get_num(string& s) {
    if (mp[s] == 0) mp[s] = counter++;
    return mp[s];
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> T;
    for (int t = 0; t < T; ++t) {
        init();
        cin >> n;
        while (n--) {
            string a, b; cin >> a >> b;
            cout << Union(get_num(a), get_num(b)) << endl;
        }
    }
}