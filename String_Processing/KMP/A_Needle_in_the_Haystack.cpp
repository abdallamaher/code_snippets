#include <bits/stdc++.h>
using namespace std;
#define ll long long

string p, t;
int n;
int f[1000000];

void search() {
    int len = 0;
    for (int i = 0; i < t.size(); i++) {
        if (len > 0 && t[i] != p[len])len = f[len - 1];
        if (t[i] == p[len])len++;
        if (len == p.size()) {
            cout << i - len + 1 << endl;
            len = f[len - 1];
        }
    }
}

void build() {
    int len = 0;
    for (int i = 1; i < p.size(); i++) {
        if (len > 0 && p[i] != p[len]) len = f[len - 1];
        if (p[i] == p[len])len++;
        f[i] = len;
    }
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    while (cin >> n) {
        cin >> p >> t;
        build();
        search();
        cout << endl;
    }
}