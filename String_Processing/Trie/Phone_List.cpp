#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector< vector<int> > v;
vector<int> e;

void insert(string& s) {
    int node = 0;
    for (int i = 0;i < (int)s.size(); i++) {
        int c = s[i] - '0';
        if (v[node][c] == -1) { //stand on node and want to c
            v[node][c] = v.size();
            v.push_back(vector<int>(10, -1));
            e.push_back(false);
        }
        node = v[node][c];
    }
    e[node] = true;
}

bool is_found(string& s) {
    int node = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        int c = s[i] - '0';
        if (v[node][c] == -1)return false;
        node = v[node][c];
    }
    return true;
}

void init() {
    v.clear();
    e.clear();
    v.push_back(vector<int>(10, -1));
    e.push_back(false);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int T; cin >> T;
    while (T--) {
        init();
        int n; cin >> n;
        vector<string> vec;
        for(int i=0; i<n;i++){
            string s; cin >> s;
            vec.push_back(s);
        }

        sort(vec.begin(), vec.end(), [](string& f, string &s){
            return (int)f.size() > (int)s.size();
        });

        bool ok = false;
        for (int i = 0; i < n; i++) {
            ok |= is_found(vec[i]);
            insert(vec[i]);
        }
        cout << (!ok ? "YES" : "NO") << endl;
    }
}