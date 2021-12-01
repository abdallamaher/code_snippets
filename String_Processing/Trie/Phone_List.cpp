#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<int>> v;
vector<int> e;


void insert(string& s) {
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i] - '0';
        if (v[cur][c] == -1) {
            v[cur][c] = v.size();
            v.push_back(vector<int>(10, -1));
            e.push_back(false);
        }
        cur = v[cur][c];
    }
    e[cur] = true;
}

bool find(string& s) {
    int cur = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        char c = s[i] - '0';
        if (v[cur][c] == -1) return false;
        cur = v[cur][c];
    }
    return true;
}

inline void solve() {
    int n; cin >> n;
    vector<string> vec;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        vec.push_back(s);
    }
    sort(vec.begin(), vec.end(), [](string& a, string& b) {
        return (b.size() < a.size());
        });

    for (int i = 0; i < n; ++i) {
        if (find(vec[i])) {
            cout << "NO\n";
            return;
        }
        insert(vec[i]);
    }
    cout << "YES\n";
}

void init() {
    v.clear();
    e.clear();
    v.push_back(vector<int>(10, -1));
    e.push_back(false);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--)init(), solve();
}